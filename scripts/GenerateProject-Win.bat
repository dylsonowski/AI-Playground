@echo off

if "%~1" == "" goto :PrintHelp
if "%~1" == "clean" goto :Clean
if "%~1" == "help" goto :PremakeHelp

call "%~dp0\..\vendor\Premake\premake5-windows.exe" %1
goto :Done

:PrintHelp
echo.
echo Enter 'GenerateProject-Win.bat action'.
echo.
echo ACTIONS
echo.
echo help              Print Premake help 
echo clean             Remove all binaries and generated files
echo codelite          Generate CodeLite project files
echo gmake             Generate GNU makefiles for POSIX, MinGW, and Cygwin
echo gmake2            Generate GNU makefiles for POSIX, MinGW, and Cygwin
echo vs2005            Generate Visual Studio 2005 project files
echo vs2008            Generate Visual Studio 2008 project files
echo vs2010            Generate Visual Studio 2010 project files
echo vs2012            Generate Visual Studio 2012 project files
echo vs2013            Generate Visual Studio 2013 project files
echo vs2015            Generate Visual Studio 2015 project files
echo vs2017            Generate Visual Studio 2017 project files
echo vs2019            Generate Visual Studio 2019 project files
echo vs2022            Generate Visual Studio 2022 project files
echo xcode4            Generate Apple Xcode 4 project files
echo.
goto :Done

:Clean
call "%~dp0\..\vendor\Premake\premake5-windows.exe" clean
goto :Done

:PremakeHelp
call "%~dp0\..\vendor\Premake\premake5-windows.exe" --help
goto :Done

:Done