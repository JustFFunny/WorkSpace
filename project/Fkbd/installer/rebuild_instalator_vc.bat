set QTDIR=C:\Qt
set QTVER=4.7.1

copy %QTDIR%\%QTVER%\bin\QtCore4.dll  
copy %QTDIR%\%QTVER%\bin\QtGui4.dll   
copy %QTDIR%\%QTVER%\bin\QtSql4.dll   
copy %QTDIR%\%QTVER%\bin\QtScript4.dll   
copy %QTDIR%\%QTVER%\bin\QtNetwork4.dll   
copy %QTDIR%\%QTVER%\bin\QtXmlPatterns4.dll   
copy %QTDIR%\%QTVER%\bin\QtDeclarative4.dll   


mkdir keyboard 
copy ..\bin\keyboard\*.qml keyboard\
copy ..\bin\keyboard\*.html keyboard\
copy ..\bin\keyboard\*.css keyboard\
REM copy ..\bin\keyboard\*.xml keyboard\

mkdir keyboard\icons 
copy ..\bin\keyboard\icons\* keyboard\icons 
 

REM mkdir plugins

REM mkdir plugins\iconengines
REM mkdir plugins\sqldrivers 

REM copy  %QTDIR%\%QTVER%\plugins\iconengines\qsvgicon4.dll plugins\iconengines\
REM copy  %QTDIR%\%QTVER%\plugins\sqldrivers\qsqlite4.dll plugins\sqldrivers\


copy ..\bin\fkbd.exe "fkbd.exe"
copy ..\bin\*.lnk


"C:\Program Files\NSIS\makensis.exe" fkbd_vc.nsi

move /Y "fkbd_install*" ..\
