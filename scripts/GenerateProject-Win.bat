@echo off

if "%~1" == "" goto :PrintHelp
if "%~1" == "clean" goto :Clean

call ..\vendor\Premake\premake5-windows.exe %1
goto Done

:PrintHelp
echo.
echo Enter 'GenerateProject-Win.bat action'. Premake help:
echo.
call ..\vendor\Premake\premake5-windows.exe --help
goto Done

:Clean
call ..\vendor\Premake\premake5-windows.exe clean
goto Done

:Done