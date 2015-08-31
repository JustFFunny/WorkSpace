/*
 * MPEGAudioFrame.cpp
 *
 *  Created on: 2010-11-26
 *      Author: gansc23@gmail.com
 * 
 *  2010-12-16:
 *      1)It should ignore the CRC data size when finding "XING" header.
 *      2)Fix the XING flag bug.
 *      3)在运行时判断是否是大端模式
 */
#include <STRING.H>
#include "MPEGAudioFrame.h"



enum{
    MPEG_AUDIO_ERR = -199
};



/**
 * 比特率表 (kbits/s)
 */
const short int BitrateTable[2][3][15] =
{
    {
        {0,32,64,96,128,160,192,224,256,288,320,352,384,416,448},
        {0,32,48,56,64 ,80 ,96 ,112,128,160,192,224,256,320,384},
        {0,32,40,48,56 ,64 ,80 ,96 ,112,128,160,192,224,256,320}
    },
    {
        {0,32,48,56,64 ,80 ,96 ,112,128,144,160,176,192,224,256},
        {0,8 ,16,24,32 ,40 ,48 ,56 ,64 ,80 ,96 ,112,128,144,160},
        {0,8 ,16,24,32 ,40 ,48 ,56 ,64 ,80 ,96 ,112,128,144,160}
    }
};


/**
 * 采样率表
 */
const short int SamplerateTable[3][3] =
{
    {44100,48000,32000 }, // MPEG-1
    {22050,24000,16000 }, // MPEG-2
    {11025,12000,8000  }  // MPEG-2.5
};


/**
 * 解析MPEG音频帧头
 */
static int parseMpegFrameHdr(
        unsigned char * hdrBuf, 
        int bufSize,
        MPEGAudioFrameInfo * info, 
        bool firstFrame);


/**
 * 解析"XING"或者"INFO"头，只会出现在第一帧音频数据区域中
 */
static int parseVbrXINGHdr(unsigned char * xingHdr, int bufSize,
        MPEGAudioFrameInfo * info);


/**
 * 解析"VBRI"头，只会出现在第一帧音频数据区域中
 */
static int parseVbrVBRIHdr(unsigned char * vbriHdr, int bufSize,
        MPEGAudioFrameInfo * info);


/**
 * 对Frame info中的数据进行计算
 */
static int calculateFrame(MPEGAudioFrameInfo * info);



/**
 * big-endian to local endian
 */
static int bigendian2Local(unsigned char * valueAddr, int len);

/**
 * little-endian to local endian
 */
static int litendian2Local(unsigned char * valueAddr, int len);

/**
 * swap endian:
 * 
 * little-endian -> big-endian
 * big-endian -> little-endian
 */
static void exchangeByteEndian(unsigned char * valueAddr, int len);

/**
 * 在运行时判断是否为大端字节序
 */
static inline int isBigendian();


//==============================================================================
// findMpegAudioFramePos
//==============================================================================
MPEGAudioRet findMpegAudioFramePos(
        unsigned char * buf, 
        int bufSize,
        MPEGAudioFrameInfo * info, 
        bool firstFrame)
{
    MPEGAudioRet ret;
    ret.mErrCode = MPEG_AUDIO_NEED_MORE;
    ret.mNextPos = 0;

    MPEGAudioFrameInfo tmp;
    MPEGAudioFrameInfo * pFrameInfo = info;
    if(!pFrameInfo)
        pFrameInfo = &tmp;

    int loopSize = bufSize - 1;
    int i = 0;
    for( ; i < loopSize; i++ )
    {
        // 帧同步标识: 1111 1111 111x xxxxb
        if( buf[i]==0xff && (buf[i+1]&0xe0)==0xe0 )
        {
            memset(pFrameInfo, 0, sizeof(*pFrameInfo));
            
            ret.mErrCode = parseMpegFrameHdr(buf+i, bufSize-i, pFrameInfo, firstFrame);
            if( MPEG_AUDIO_OK == ret.mErrCode 
                    || MPEG_AUDIO_NEED_MORE == ret.mErrCode)
            {
                break;
            }
        }
        else if(i==loopSize-1 && buf[i+1] != 0xff)
        {
            i++;
        }
    }

    ret.mNextPos = i;
    
    if(i > 0 && ret.mErrCode != MPEG_AUDIO_OK)
        memset(pFrameInfo, 0, sizeof(MPEGAudioFrameInfo));

    return ret;
}


//==============================================================================
// parseMpegFrameHdr
//==============================================================================
int parseMpegFrameHdr(
        unsigned char * hdrBuf, 
        int bufSize,
        MPEGAudioFrameInfo * info, 
        bool firstFrame)
{
    if(bufSize < 4) // 帧头至少有4个字节
        return MPEG_AUDIO_NEED_MORE;
    
    // Protection Bit
    info->mProtection = (hdrBuf[1] & 0x01);
    info->mProtection = (0 == info->mProtection ? 1 : 0);
    
    if(info->mProtection && bufSize < 6)
    {
        // protected by 16 bit CRC following header
        return MPEG_AUDIO_NEED_MORE;
    }
    
    
    // MPEG版本
    info->mMPEGVersion = ((hdrBuf[1]>>3) & 0x03);
    switch(info->mMPEGVersion)
    {
    case 0:
        info->mMPEGVersion = 25;
        break;
    case 2:
        info->mMPEGVersion = 20;
        break;
    case 3:
        info->mMPEGVersion = 10;
        break;
    default:
        info->mMPEGVersion = 0;
        return MPEG_AUDIO_ERR;
    };
    
    // Layer index
    info->mLayer = ((hdrBuf[1]>>1) & 0x03);
    switch(info->mLayer)
    {
    case 1:
        info->mLayer = 3;
        break;
    case 2:
        info->mLayer = 2;
        break;
    case 3:
        info->mLayer = 1;
        break;
    default:
        info->mLayer = 0;
        return MPEG_AUDIO_ERR;
    };
    
    // 比特率
    info->mBitrate = ((hdrBuf[2]>>4)&0x0f);
    if(info->mBitrate == 0x0f)
        return MPEG_AUDIO_ERR;

    unsigned char index_I = (info->mMPEGVersion==10 ? 0 : 1);
    unsigned char index_II = info->mLayer - 1;

    info->mBitrate = BitrateTable[index_I][index_II][info->mBitrate];
    
    
    // 采样率
    info->mSamplerate = ((hdrBuf[2]>>2)&0x03);
    if(info->mSamplerate == 0x03)
        return MPEG_AUDIO_ERR;

    index_I = 2; // MPEG-2.5 by default
    if(info->mMPEGVersion == 20)
        index_I = 1;
    else if(info->mMPEGVersion == 10)
        index_I = 0;

    info->mSamplerate = SamplerateTable[index_I][info->mSamplerate];
    
    
    // Padding size
    info->mPaddingSize = ((hdrBuf[2]>>1)&0x01);
    if(info->mPaddingSize)
    {
        info->mPaddingSize = ( info->mLayer==1 ? 4 : 1 );
    }
    
    
    // channel mode
    info->mChannelMode = ((hdrBuf[3]>>6)&0x03);
    switch(info->mChannelMode)
    {
    case 0:
        info->mChannelMode = 3;
        break;
    case 1:
        info->mChannelMode = 0;
        break;
    case 2:
        info->mChannelMode = 2;
        break;
    case 3:
    default:
        info->mChannelMode = 1;
    };
    
    // 在MPEG-1 Layer II中，只有某些比特率和某些模式的组合是允许的。
    // 在MPEG -2/2.5，没有此限制。
    if(info->mMPEGVersion == 10 && info->mLayer == 2)
    {
        if( 32 == info->mBitrate
                || 48 == info->mBitrate
                || 56 == info->mBitrate
                || 80 == info->mBitrate )
        {
            if( info->mChannelMode != 1 )
                return MPEG_AUDIO_ERR;
        }
        else if( 224 == info->mBitrate
                || 256 == info->mBitrate
                || 320 == info->mBitrate
                || 384 == info->mBitrate )
        {
            if( 1 == info->mChannelMode )
                return MPEG_AUDIO_ERR;
        }
    }
    
    //  Extension Mode
    info->mExtensionMode = ((hdrBuf[3]>>4)&0x03);


    info->mCopyrightBit = ((hdrBuf[3]>>3)&0x01);

    info->mOriginalBit = ((hdrBuf[3]>>2)&0x01);


    // The emphasis indication is here to tell the decoder that the file must be 
    // de-emphasized, that means the decoder must 're-equalize' the sound after 
    // a Dolby-like noise suppression. It is rarely used.
    info->mEmphasis = ((hdrBuf[3])&0x03);
    if(0x2 == info->mEmphasis)
        return MPEG_AUDIO_ERR;
    
    if(info->mProtection)
    {
        // This checksum directly follows the frame header and is a big-endian 
        // WORD.
        // So maybe you shoud convert it to little-endian.
        info->mCRCValue = *((unsigned short int *)(hdrBuf + 4));
        
        bigendian2Local(
                (unsigned char *)(&(info->mCRCValue)), sizeof(info->mCRCValue) );
    }
    
    // 每帧数据的采样数
    info->mSamplesPerFrame = 1152;
    if(1 == info->mLayer)
    {
        info->mSamplesPerFrame = 384;
    }
    else if(info->mMPEGVersion != 10 && 3 == info->mLayer)
    {
        info->mSamplesPerFrame = 576;
    }
    
    // 边信息大小
    info->mSideInfoSize = 0;
    if(3 == info->mLayer)
    {
        if(info->mMPEGVersion != 10) // MPEG-2/2.5 (LSF)
        {
            if(info->mChannelMode != 1) // Stereo, Joint Stereo, Dual Channel
                info->mSideInfoSize = 17;
            else // Mono
                info->mSideInfoSize = 9;
        }
        else // MPEG-1.0
        {
            if(info->mChannelMode != 1) // Stereo, Joint Stereo, Dual Channel
                info->mSideInfoSize = 32;
            else // Mono
                info->mSideInfoSize = 17;
        }
    }
    
    
    info->mBitrateType = 0; // common CBR by default
    
    if(firstFrame)
    {
        short int reqSize = 4;
        
        // DELETE by gansc23 at 2010-12-16 for ignore CRC data size
        //if(info->mProtection)
        //    reqSize += 2;

        reqSize += info->mSideInfoSize;
        reqSize += 4; // "XING" OR "INFO"

        // "XING" OR "INFO"
        int ret1 = parseVbrXINGHdr(hdrBuf + reqSize - 4, bufSize - reqSize + 4, info);
        
        if(MPEG_AUDIO_OK == ret1)
        {
            goto label_get_XING_or_INFO;
        }
        else if(MPEG_AUDIO_NEED_MORE == ret1)
        {
            return MPEG_AUDIO_NEED_MORE;
        }
        
        
        // no "XING" OR "INFO", try to find "VBRI"
        reqSize -= ( info->mSideInfoSize + 4 );
        reqSize += 32;
        
        ret1 = parseVbrVBRIHdr(hdrBuf + reqSize, bufSize - reqSize, info);
        
        if(MPEG_AUDIO_NEED_MORE == ret1)
        {
            return MPEG_AUDIO_NEED_MORE;
        }
    }
    
    
label_get_XING_or_INFO:
    
    calculateFrame(info);
    
    
    return MPEG_AUDIO_OK;
}


//==============================================================================
// parseVbrXINGHdr
//==============================================================================
int parseVbrXINGHdr(unsigned char * xingHdr, int bufSize,
        MPEGAudioFrameInfo * info)
{
    if(bufSize < 4)
        return MPEG_AUDIO_NEED_MORE;
    
    info->mBitrateType = 0;
    
    // for "XING"
    if( (xingHdr[0] == 'x' || xingHdr[0] == 'X')
            && (xingHdr[1] == 'i' || xingHdr[1] == 'I')
            && (xingHdr[2] == 'n' || xingHdr[2] == 'N')
            && (xingHdr[3] == 'g' || xingHdr[3] == 'G') )
    {
        // VBR(XING)
        info->mBitrateType = 2;
    }
    // for "INFO"
    else if( (xingHdr[0] == 'i' || xingHdr[0] == 'I')
            && (xingHdr[1] == 'n' || xingHdr[1] == 'N')
            && (xingHdr[2] == 'f' || xingHdr[2] == 'F')
            && (xingHdr[3] == 'o' || xingHdr[3] == 'O') )
    {
        // CBR(INFO)
        info->mBitrateType = 1;
    }
    
    if(!info->mBitrateType) // no "XING" or "INFO" header
        return MPEG_AUDIO_ERR;
    
    int offset = 8;
    
    if(bufSize < offset)
        return MPEG_AUDIO_NEED_MORE;
    
    // Modified by gansc23 at 2010-12-16 for fixing XING flag bug.
    //unsigned char flags = xingHdr[5];
    unsigned char flags = xingHdr[7];

    if(flags & 0x01) // Frames field is present
    {
        if(bufSize < offset+4)
            return MPEG_AUDIO_NEED_MORE;
        
        info->mTotalFrames = *((int *)(xingHdr+offset));
        
        bigendian2Local((unsigned char *)(&(info->mTotalFrames)), 
                sizeof(info->mTotalFrames));
        
        offset += 4;
        
    }
    if(flags & 0x02) // Bytes field is present
    {
        if(bufSize < offset+4)
            return MPEG_AUDIO_NEED_MORE;
        
        info->mTotalBytes = *((int *)(xingHdr+offset));
        
        bigendian2Local((unsigned char *)(&(info->mTotalBytes)), 
                sizeof(info->mTotalBytes));
        
        offset += 4;
    }
    if(flags & 0x04) // TOC field is present
    {
        if(bufSize < offset+100)
            return MPEG_AUDIO_NEED_MORE;
        
        offset += 100;
    }
    if(flags & 0x08) // Quality indicator field is present
    {
        if(bufSize < offset+4)
            return MPEG_AUDIO_NEED_MORE;
        
        int quality = *((int *)(xingHdr+offset));
        
        bigendian2Local((unsigned char *)(&quality), 
                sizeof(quality) );
        
        info->mQuality = 100 - quality;
        
        offset += 4;
    }
    
    return MPEG_AUDIO_OK;
}


//==============================================================================
// parseVbrVBRIHdr
//==============================================================================
int parseVbrVBRIHdr(unsigned char * vbriHdr, int bufSize,
        MPEGAudioFrameInfo * info)
{
    if(bufSize < 4)
        return MPEG_AUDIO_NEED_MORE;
    
    info->mBitrateType = 0;
    
    // for "VBRI"
    if( (vbriHdr[0] == 'v' || vbriHdr[0] == 'V')
            && (vbriHdr[1] == 'b' || vbriHdr[1] == 'B')
            && (vbriHdr[2] == 'r' || vbriHdr[2] == 'R')
            && (vbriHdr[3] == 'i' || vbriHdr[3] == 'I') )
    {
        // VBR
        info->mBitrateType = 3;
    }
    
    if(!info->mBitrateType) // no "VBRI" header
        return MPEG_AUDIO_ERR;
    
    if(bufSize < 26)
        return MPEG_AUDIO_NEED_MORE;
    
    unsigned char * offset = (vbriHdr + 4);
    
    // VBRI version
    info->mVBRIVersionID = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mVBRIVersionID)), 
            sizeof(info->mVBRIVersionID));
    
    offset += 2;
    
    // Delay，不清楚作用
    (info->mVBRIDelay)[0] = *offset;
    (info->mVBRIDelay)[1] = *(offset + 1);
    
    offset += 2;
    
    // Quality indicator
    info->mQuality = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mQuality)), 
            sizeof(info->mQuality) ); // 不确定是以大端字节序存放的
    
    info->mQuality = 100 - info->mQuality; // 不确定
    
    offset += 2;
    
    // total bytes
    info->mTotalBytes = *((int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mTotalBytes)), 
            sizeof(info->mTotalBytes));
    
    offset += 4;
    
    
    // total frames number
    info->mTotalFrames = *((int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mTotalFrames)), 
            sizeof(info->mTotalFrames));
    
    offset += 4;
    
    // Number of entries within TOC table
    info->mEntriesNumInTOCTable = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mEntriesNumInTOCTable)), 
            sizeof(info->mEntriesNumInTOCTable));
    
    offset += 2;
    
    // Scale factor of TOC table entries
    info->mTOCTableFactor = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mTOCTableFactor)), 
            sizeof(info->mTOCTableFactor));
    
    offset += 2;
    
    // Size per table entry in bytes (max 4)
    short int entrySize = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&entrySize), sizeof(entrySize));
    
    info->mEntrySize = entrySize;
    
    offset += 2;
    
    // Frames per table entry
    info->mFramesNumPerTable = *((short int *)offset);
    
    bigendian2Local((unsigned char *)(&(info->mFramesNumPerTable)), 
            sizeof(info->mFramesNumPerTable));
    
    offset += 2;
    
    
    return MPEG_AUDIO_OK;
}


//==============================================================================
// calculateFrame
//==============================================================================
int calculateFrame(MPEGAudioFrameInfo * info)
{
    info->mFrameSize = (info->mSamplesPerFrame * info->mBitrate * 1000)
            / (8 * info->mSamplerate)
            + info->mPaddingSize;
    
    return MPEG_AUDIO_OK;
}


//==============================================================================
// bigendian2Local
//==============================================================================
int bigendian2Local(unsigned char * valueAddr, int len)
{
    if(len <= 0 || len % 2 != 0)
        return -1;
    
//#if !defined(BIG_ENDIAN)
    if( isBigendian() )
        exchangeByteEndian(valueAddr, len);
//#endif
    
    return 0;
}

//==============================================================================
// litendian2Local
//==============================================================================
int litendian2Local(unsigned char * valueAddr, int len)
{
    if(len <= 0 || len % 2 != 0)
        return -1;
    
//#if defined (BIG_ENDIAN)
    if( isBigendian() )
        exchangeByteEndian(valueAddr, len);
//#endif
    
    return 0;
}


//==============================================================================
// exchangeByteEndian
//==============================================================================
void exchangeByteEndian(unsigned char * valueAddr, int len)
{
    int n = len >> 1;
    
    for(int i = 0; i < n; i++)
    {
        unsigned char v = *(valueAddr + i);
        *(valueAddr + i) = *(valueAddr + len - 1 - i);
        *(valueAddr + len - 1 - i) = v;
    }
}


//==============================================================================
// isBigendian
//==============================================================================
inline int isBigendian()
{
    const unsigned short int num16 = 0x12ab;
    const unsigned char * const pLowByte = (const unsigned char *)num16;

    if( 0x12 == *pLowByte )
        return 1;

    return 0;
}