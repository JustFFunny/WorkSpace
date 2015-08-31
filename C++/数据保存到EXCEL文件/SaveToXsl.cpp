// SaveToXsl.cpp: implementation of the CSaveToXsl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SaveToXsl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaveToXsl::CSaveToXsl()
{
	m_strH = "";
	m_strFileName = "";
}

CSaveToXsl::~CSaveToXsl()
{
	if(m_database.IsOpen())
	m_database.Close();
}

void CSaveToXsl::GetFileName(CString strFileName)
{
	///默认文件名
	if(strFileName == "")
		GetDefaultXlsFileName(m_strFileName);
	else 
		m_strFileName = strFileName ;
			
}

void CSaveToXsl::Initialize(CString strTitle/*表名*/,CString strCreateName/*字段名*/,CString strName)
{	//strNames = "索引 TEXT,方向 TEXT,时间 TEXT" ；
		CString warningStr;
		CString sDriver;
		CString sSql = ""; //SQL 语句
		m_tableName = strTitle;
		m_strH = strName;  //保存字段名	

		// 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)" 
		sDriver = GetExcelDriver();
		if (sDriver.IsEmpty())
		{
			// 没有发现Excel驱动
			AfxMessageBox("没有安装Excel!\n请先安装Excel软件才能使用导出功能!");
			return;
		}

		if(m_strFileName == "")
		{
			GetFileName() ;
		}
	// 创建进行存取的字符串
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, m_strFileName, m_strFileName);
		
		// 创建数据库 (既Excel表格文件)
		if( m_database.OpenEx(sSql,CDatabase::noOdbcDialog) )
		{
			// 创建表结构
			sSql = "CREATE TABLE " + m_tableName + " ( " + strCreateName +  " ) ";
			m_database.ExecuteSQL(sSql);
		}      
}

BOOL CSaveToXsl::InsertToTable(CString strV/*字段值*/)
{
	// strV = " '10' ,'0', '2006:10:15' " ;
	if(!m_database.IsOpen()) 
	{
		AfxMessageBox("数据库未打开");
		return FALSE ;
	}

	CString sSql = "";
	sSql = "INSERT INTO " + m_tableName + "(" + m_strH + ")" + "VALUES(" + strV + ")";
	m_database.ExecuteSQL(sSql);
	return TRUE ;
}


CString CSaveToXsl::GetExcelDriver()
{
    char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
	
    // 获取已安装驱动的名称(函数在odbcinst.h里)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return "";
    
    // 检索已安装的驱动是否有Excel...
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            //发现 !
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
	
    return sDriver;
}

BOOL CSaveToXsl::MakeSurePathExists( CString &Path,bool FilenameIncluded)
{
	int Pos=0;
	while((Pos=Path.Find('\\',Pos+1))!=-1)
		CreateDirectory(Path.Left(Pos),NULL);
	if(!FilenameIncluded)
		CreateDirectory(Path,NULL);
	//	return ((!FilenameIncluded)?!_access(Path,0):
	//	!_access(Path.Left(Path.ReverseFind('\\')),0));
	
	return !_access(Path,0);
}

//获得默认的文件名
BOOL CSaveToXsl::GetDefaultXlsFileName(CString& sExcelFile)
{
	///默认文件名：yyyymmddhhmmss.xls
	CString timeStr;
	CTime day;
	day=CTime::GetCurrentTime();
	int filenameday,filenamemonth,filenameyear,filehour,filemin,filesec;
	filenameday=day.GetDay();//dd
	filenamemonth=day.GetMonth();//mm月份
	filenameyear=day.GetYear();//yyyy
	filehour=day.GetHour();//hh
	filemin=day.GetMinute();//mm分钟
	filesec=day.GetSecond();//ss
	timeStr.Format("%04d%02d%02d%02d%02d%02d",filenameyear,filenamemonth,filenameday,filehour,filemin,filesec);
	
	sExcelFile =  timeStr + ".xls";
	// prompt the user (with all document templates)
	CFileDialog dlgFile(FALSE,".xls",sExcelFile);
	CString title;
	CString strFilter;
	
	title = "导出";
	strFilter = "Excel文件(*.xls)";
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.xls");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	dlgFile.m_ofn.nFilterIndex = 1;
	// append the "*.*" all files filter
	CString allFilter;
	VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
	strFilter += allFilter;
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.*");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	
	if (dlgFile.DoModal()==IDCANCEL)
		return FALSE; // open cancelled
	sExcelFile.ReleaseBuffer();
	if (MakeSurePathExists(sExcelFile,true)) {
		if(!DeleteFile(sExcelFile)) {    // delete the file
			AfxMessageBox("覆盖文件时出错！");
			return FALSE;
		}
	}
	CString str = dlgFile.GetFileTitle();
	sExcelFile = str + _T(".xls");
	return TRUE;
}