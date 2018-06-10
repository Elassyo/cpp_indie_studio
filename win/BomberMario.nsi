;;
;; EPITECH PROJECT, 2018
;; cpp_indie_studio
;; File description:
;; NSIS (un)install script
;;

;--------------------------------
;Include Modern UI

  !include "MUI2.nsh"

;--------------------------------
;General

  ;Name and file
  Name "BomberMario"
  OutFile "bombermario-setup.exe"

  ;Default installation folder
  InstallDir "$LOCALAPPDATA\BomberMario"

  ;Request application privileges for Windows Vista
  RequestExecutionLevel admin

;--------------------------------
;Interface Settings

  !define MUI_ICON "bombermario.ico"
  !define MUI_ABORTWARNING

;--------------------------------
;Pages

  !insertmacro MUI_PAGE_WELCOME
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !define MUI_FINISHPAGE_RUN
  !define MUI_FINISHPAGE_RUN_FUNCTION LaunchGame
  !insertmacro MUI_PAGE_FINISH

  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;--------------------------------
;Languages

  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Installer Sections

Section "BomberMario" SecBomb
  SectionIn RO

  SetOutPath "$INSTDIR"

  File "bombermario.exe"

  File "Irrlicht.dll"
  File "libvorbis.dll"
  File "libvorbisfile.dll"

  File /r "..\assets\*"

SectionEnd

Section "Microsoft Visual C/C++ 2017 Redistributable" SecVCRedist

  SetOutPath "$INSTDIR\redist"

  File "redist\VC_redist.x64.exe"

  ExecWait "$INSTDIR\redist\VC_redist.x64.exe /install /quiet"
  IfErrors failed
  Goto done

  failed:
    Abort "Failed to install Microsoft Visual C/C++ 2017 Redistributable"

  done:

SectionEnd

Section "OpenAL Driver" SecOAL

  SetOutPath "$INSTDIR\redist"

  File "redist\oalinst.exe"

  ExecWait "$INSTDIR\redist\oalinst.exe /S"
  IfErrors failed
  Goto done

  failed:
    Abort "Failed to install OpenAL"

  done:

SectionEnd

Section "Desktop Shortcut" SecDeskLnk

  CreateShortCut "$DESKTOP\BomberMario.lnk" "$INSTDIR\bombermario.exe" "" "$INSTDIR\bombermario.exe" 0

SectionEnd

Section "Uninstaller" SecUninst
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

;--------------------------------
;Sections descriptions

LangString DESC_SecBomb ${LANG_ENGLISH} "The BomberMario game"
LangString DESC_SecVCRedist ${LANG_ENGLISH} "The Microsoft Visual C/C++ 2017 Redistributable required to run the game"
LangString DESC_SecOAL ${LANG_ENGLISH} "The OpenAL Driver required to play music and sound effects in the game"
LangString DESC_SecDeskLnk ${LANG_ENGLISH} "Create a shortcut to the game on your desktop"
LangString DESC_SecUninst ${LANG_ENGLISH} "Create an uninstaller"

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SecBomb} $(DESC_SecBomb)
  !insertmacro MUI_DESCRIPTION_TEXT ${SecVCRedist} $(DESC_SecVCRedist)
  !insertmacro MUI_DESCRIPTION_TEXT ${SecOAL} $(DESC_SecOAL)
  !insertmacro MUI_DESCRIPTION_TEXT ${SecDeskLnk} $(DESC_SecDeskLnk)
  !insertmacro MUI_DESCRIPTION_TEXT ${SecUninst} $(DESC_SecUninst)
!insertmacro MUI_FUNCTION_DESCRIPTION_END


;--------------------------------
;Uninstaller Section

Section "Uninstall"

  RMDir /r "$INSTDIR"

  Delete "$DESKTOP\BomberMario.lnk"

SectionEnd

;--------------------------------
;Functions

Function LaunchGame
  ExecShell "" "$INSTDIR\bombermario.exe"
FunctionEnd
