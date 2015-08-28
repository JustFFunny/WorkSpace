;NSIS Modern User Interface
;MTS Tester install script
;Written by Tomasz Ziobrowski

!define REVISION "ProFace"
!define PRONAME "Fkbd" 

;--------------------------------
;Include Modern UI

  !include "MUI.nsh"

;--------------------------------
;General

  ;Name and file
  Name "${PRONAME} (rev. ${REVISION})"
  OutFile "${PRONAME}_install_${REVISION}.exe"

  ;Default installation folder
  InstallDir "$PROGRAMFILES\3electrons\${PRONAME}"
  
  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "3electrons\${PRONAME}" ""
 
  ;Commpression Method 
  SetCompressor	/SOLID lzma

;--------------------------------
;Interface Configuration

  !define MUI_HEADERIMAGE
  !define MUI_HEADERIMAGE_BITMAP "inst_resources\3e_header.bmp" ; optional
  !define MUI_ABORTWARNING
 ; !define MUI_WELCOMEFINISHPAGE_BITMAP "inst_resources\welcome.bmp" ; 
;--------------------------------
;Pages

  !insertmacro MUI_PAGE_WELCOME
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
     
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH
  
  
;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Installer Sections

Section "Dummy Section" SecDummy

  SetOutPath "$INSTDIR"


  ; --- Updating login database 


  File /r keyboard
  File mingwm10.dll
  File libgcc_s_dw2-1.dll
  File QtCore4.dll
  File QtSql4.dll 
  File QtGui4.dll
  File QtDeclarative4.dll 
  File QtXmlPatterns4.dll 
  File QtScript4.dll 
  File QtNetwork4.dll 
  File *.lnk 
  File "${PRONAME}.exe"




  ;Store installation folder
  WriteRegStr HKCU "Software\3electrons\${PRONAME}" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

   
  createShortcuts:

  CreateDirectory "$SMPROGRAMS\3electrons"
  CreateShortCut  "$SMPROGRAMS\3electrons\${PRONAME}.lnk" "$INSTDIR\${PRONAME}.exe"
  CreateShortCut "$DESKTOP\${PRONAME}.lnk" "$INSTDIR\${PRONAME}.exe"

  CreateShortCut  "$SMPROGRAMS\3electrons\Uninstall.lnk"  "$INSTDIR\Uninstall.exe"



  
 ; write uninstall strings
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRONAME}" "DisplayName" "${PRONAME}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRONAME}" "UninstallString" '"$INSTDIR\uninstall.exe"'


 

;ADD YOUR OWN FILES HERE...
  

SectionEnd

;--------------------------------
;Descriptions

  ;Language strings
  LangString DESC_SecDummy ${LANG_POLISH} "Sekcja testowa."

  ;Assign language strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecDummy} $(DESC_SecDummy)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END
 
;--------------------------------
;Uninstaller Section

Section "Uninstall"

  ;ADD YOUR OWN FILES HERE...

   Delete "$INSTDIR\Uninstall.exe"
   Delete "$INSTDIR\*.dll"
   Delete "$INSTDIR\*.exe" 
   Delete "$INSTDIR\*.TXT"
   Delete "$INSTDIR\*.lnk" 
   Delete "$INSTDIR\${PRONAME}.exe"
   Delete "$DESKTOP\${PRONAME}.lnk" 


   RMDIR  /r "$INSTDIR\plugins" 
   RMDIR  /r "$SMPROGRAMS\3electrons"
   RMDIR  /r "$INSTDIR"
;  RMDir "$INSTDIR"

  DeleteRegKey HKCU "Software\3electorns\Fkbd"
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRONAME}"


SectionEnd
