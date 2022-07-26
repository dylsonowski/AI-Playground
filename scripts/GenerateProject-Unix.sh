#!bin/sh

PrintHelp() {
    echo .
    echo Enter 'GenerateProject-Unix.sh action'. Premake help:
    echo .
    ../vendor/Premake/premake5-linux --help
}

Clean() {
    ../vendor/Premake/premake5-linux clean
}

if [ "$1" = "" ]; then
    PrintHelp
    exit
fi

if [ "$1" = "clean" ]; then
    Clean
    exit
fi

if [ "$1" = "linux" ]; then
    ../vendor/Premake/premake5-linux $2
    exit
elif [ "$1" = "mac" ]; then
    ../vendor/Premake/premake5-macos $2
    exit
else
    echo Action did not recognized. This script allows building only Linux or MacOS projects.
    exit
fi