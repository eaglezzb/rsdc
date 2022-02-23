REM --------------------------------------------------------------------
REM This program is free software: you can redistribute it and/or modify
REM it under the terms of the GNU General Public License as published by
REM the Free Software Foundation, either version 3 of the License, or
REM (at your option) any later version.
REM 
REM This program is distributed in the hope that it will be useful,
REM but WITHOUT ANY WARRANTY; without even the implied warranty of
REM MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM GNU General Public License for more details.
REM 
REM You should have received a copy of the GNU General Public License
REM along with this program.  If not, see <http://www.gnu.org/licenses/>.
REM ---------------------------------------------------------------------

set QT_DIR=..\Qt-sankore3.1
set QT_BIN=%QT_DIR%\bin

set VS_BIN="C:\Program Files\Microsoft Visual Studio 9.0\VC\bin"
set WIN_SDK_BIN="C:\Program Files\Microsoft SDKs\Windows\v6.1\Bin"
set INNO_EXE="C:\Program Files\Inno Setup 5\iscc.exe "
set BUILD_DIR=build\win32\release

set PATH=%QT_BIN%;%PATH%;%WIN_SDK_BIN%

call %VS_BIN%\vcvars32.bat

REM this checks if the custom qt directory path
REM is correct. This is important because installer
REM pick up dll from this directory
IF NOT EXIST "..\Qt-sankore3.1\lib\QtCore4.dll" GOTO EXIT_WITH_ERROR

rmdir /S /Q %BUILD_DIR%


"%QT_BIN%\qmake.exe"

nmake release

set INSTALLER_NAME=Sankore App Toolkit

set INSTALLER_PATH=.\install\win32\%INSTALLER_NAME%.exe

call %INNO_EXE% "SankoreAppToolkit.iss" /F"%INSTALLER_NAME%"

:EXIT_WITH_ERROR
	echo ERROR
