//打开MP3里面的相关信息----------------------------------------------------
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>

void Tag_GetTrailer(void);
void Tag_GetHeader(void);

#define BLACK 0		//黑色
#define WHITE 0xffff	//白色
#define RED 0xff0000	//红色
#define GREEN 0xff00	//绿色
#define BLUE 0xff		//蓝色
#define BACK_NULL 1024 	//透明

FILE *fp;
char curr_mp3_path[64];
//Tag_header_Start
struct Tag_Header{
 char Header[3]; //it must be ID3
 char ver[2];            //the version of ID3
 char ReVer[2];      //the subversion of ID3
 char Flag[2];
 char Size[4];
};
//Tag_header_End
//Tag_Trailer_Start
struct Tag_Trailer{
 char Header[4];
 char Title[31];
 char Artist[31];
 char Album[31];
 char Year[5];
 char Comment[32];
 char Cenre[2];
};
//Tag_Trailer_End
//定义结构体变量,文件头和文件尾
struct Tag_Header Mp3Header;
struct Tag_Trailer Mp3Trailer;
int mp3_kbps;		//kbps是指mp3的位数（bit率），位速是指在一个数据流中每秒钟能通过的信息量
int mp3_time;		//是指mp3播放时间的总长数，单位是秒
int OpenMP3File(char *path)
{	char mp3_name[128];
	memset(&Mp3Header, 0, sizeof(Mp3Header));//清空
	memset(&Mp3Trailer, 0, sizeof(Mp3Trailer));
	 fp=fopen(path,"r+");
	 strcpy(curr_mp3_path,path);
	 if(fp==NULL)
	 {
	  printf("Can't open file\n");
	 }
	 else
	 {
		  Tag_GetHeader();
		  Tag_GetTrailer();
	 }


#if 1
	sprintf(mp3_name, "MP3___Title:%s",Mp3Trailer.Title);
	printf("\n%s\n",mp3_name);
//	lcd_put_ascii_string(120, 50, , GREEN, (unsigned char *)mp3_name);
	
	sprintf(mp3_name, "MP3__Artist:%s",Mp3Trailer.Artist);
	printf("%s\n",mp3_name);
//	lcd_put_ascii_string(120, 70, BACK_NULL, GREEN, (unsigned char *)mp3_name);
	
	
	sprintf(mp3_name, "MP3___Album:%s",Mp3Trailer.Album);
	printf("%s\n",mp3_name);
//	lcd_put_ascii_string(120, 90, BACK_NULL, GREEN, (unsigned char *)mp3_name);

	sprintf(mp3_name, "MP3____Year:%s",Mp3Trailer.Year);
	printf("%s\n",mp3_name);
//	lcd_put_ascii_string(120, 110, BACK_NULL, GREEN, (unsigned char *)mp3_name);
	
	sprintf(mp3_name, "MP3_Comment:%s",Mp3Trailer.Comment);
	printf("%s\n",mp3_name);
//	lcd_put_ascii_string(120, 130, BACK_NULL, GREEN, (unsigned char *)mp3_name);

	char tmp_str[10];
	sprintf(tmp_str,"time:%d",mp3_time);
	printf("%s\n",tmp_str);
//	lcd_put_ascii_string(110, 170, BACK_NULL, GREEN, (unsigned char *)tmp_str);
	
	sprintf(tmp_str,"KBPS:%d", mp3_kbps);
	printf("%s\n",tmp_str);
//	lcd_put_ascii_string(270, 170, BACK_NULL, GREEN, (unsigned char *)tmp_str);
#endif

	 return 0;
}

void Tag_GetTrailer(void)
{
	int read_bytes;
	 //get header
	
	 fseek(fp,-128L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Header,3,1,fp);
	 Mp3Trailer.Header[3] = 0;
	 //get title
	 fseek(fp,-125L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Title,20,1,fp);
	 Mp3Trailer.Title[20] = 0;
	 //get artist
	 fseek(fp,-95L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Artist,20,1,fp);
	 Mp3Trailer.Artist[20] = 0;
	 //get album
	 fseek(fp,-65L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Album,20,1,fp);
	 Mp3Trailer.Album[20] = 0;
	 //get year
	 fseek(fp,-35L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Year,4,1,fp);
	 Mp3Trailer.Year[4] = 0;
	 //get comment
	 fseek(fp,-31L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Comment,20,1,fp);
	  Mp3Trailer.Comment[20] = 0;
	 //get Cenre
	 fseek(fp,-1L,SEEK_END);
	 read_bytes = fread(Mp3Trailer.Cenre,1,1,fp);
	 Mp3Trailer.Cenre[1] = 0;
	 
}

void Tag_GetHeader(void)
{

       int read_bytes;
       unsigned char ch[2];
       unsigned char ch1[4];
       ch[1] = 0;
        //get ID3 Tag
        
       
       read_bytes = fread(Mp3Header.Header,sizeof(Mp3Header.Header),1,fp);
        
        //get ID3 version
        fseek(fp,3,SEEK_CUR);
        read_bytes = fread(Mp3Header.ver,1,1,fp);
       
       //get ID3 Reversion
       fseek(fp,4,SEEK_CUR);
        read_bytes = fread(Mp3Header.ReVer,sizeof(Mp3Header.ReVer),1,fp);
       
        //get ID3 flag
        fseek(fp,5,SEEK_CUR);
        read_bytes = fread(Mp3Header.Flag,sizeof(Mp3Header.Flag),1,fp);
         
        //get ID3 size
        fseek(fp,6,SEEK_CUR);
        read_bytes = fread(Mp3Header.Size,sizeof(Mp3Header.Size),1,fp);
       
        fseek(fp,0,SEEK_SET);
   
        while(1)
       {
       	read_bytes = fread(ch, 1, 1,fp);
       	if(ch[0] == 0xff)
       	{ 
       		read_bytes = fread(ch, 1, 1,fp);
       		if(ch[0] == 0xfb)
       		{
       			printf("yes\n");
       			break;
       		}
       	}
       	ch[1] = 0;
  
       }
       
        read_bytes = fread(ch1, 3, 1,fp);
        printf("bytes:::%x %x %x",ch1[0],ch1[1],ch1[2]);
       ch[0] = (ch1[0] >> 4) & 0x0f;
       	
       double label[16] = {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320};
       printf("\n%f KBPS\n",label[ch[0]]);
	   mp3_kbps = (int)label[ch[0]];
       ch[1] = (ch1[0] >> 2) & 0x03;
       double label1[4] = {44100, 48000, 32000};
       printf("\n%fHZ\n",label1[ch[1]]);
       
       double ff; 
       int ff1;
       double ff2;
       ff = (double)(1152.00 / label1[ch[1]]) * label[ch[0]]*1000/8;
       printf("ff = %f\n",ff);
       printf("ff = %d\n",(int)ff);
         ff1 = (int)ff;
       if(ff1%8 != 0)
       	 ff2 = (ff1/8 + 1)*8;
       else
       	ff2 = ff1;
       printf("%f \n", ff2);
       
       struct stat f_stat;
       double f_size = 0;
       if(stat(curr_mp3_path, &f_stat) == -1)
       		printf("stat err\n");
       else
       {
       	printf("%ld\n", f_stat.st_size);
       	f_size = (double)f_stat.st_size;
       	printf("%f\n", f_size);
       }
	   
       mp3_time = (int)(f_size/ff2*0.0263);
       printf("%d", mp3_time);

}

//mp3的路径名由main函数的参数提供
int main(char argv, char** argc)
{
	if(argv == 1)
	{	
		printf("input mp3 file name\n");
		return 0;
	}
	OpenMP3File(argc[1]);
	return 0;
}


