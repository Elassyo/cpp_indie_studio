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

Section "Core" SecCore

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

Section "OpenAL" SecOAL

  SetOutPath "$INSTDIR\redist"

  File "redist\oalinst.exe"

  ExecWait "$INSTDIR\redist\oalinst.exe /S"
  IfErrors failed
  Goto done

  failed:
    Abort "Failed to install OpenAL"

  done:

SectionEnd

Section "Misc" SecMisc

  CreateShortCut "$DESKTOP\BomberMario.lnk" "$INSTDIR\bombermario.exe" "" "$INSTDIR\bombermario.exe" 0

  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

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
