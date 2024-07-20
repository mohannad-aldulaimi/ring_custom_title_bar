echo off
IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.2

setlocal enableextensions enabledelayedexpansion
call ..\..\..\language\build\locatevc.bat x64
cls
"%RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\bin\qmake.exe" CustomTitleBar.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
"%RING_QT_DIR%\tools\qtcreator\bin\jom\jom.exe"
copy release\CustomTitleBar.dll ..\..\bin
endlocal