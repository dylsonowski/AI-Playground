#!bin/sh

PrintHelp() {
    echo
    echo Enter 'GenerateProject-Unix.sh platform action'
    echo
    echo PLATFORM
    echo
    echo "unix               Execute chosen action for Unix system type configuration"
    echo "macosx             Execute chosen action for MacOS system type configuration"
    echo
    echo ACTIONS
    echo
    echo "help              Print Premake help"
    echo "clean             Remove all binaries and generated files"
    echo "codelite          Generate CodeLite project files"
    echo "gmake             Generate GNU makefiles for POSIX, MinGW, and Cygwin"
    echo "gmake2            Generate GNU makefiles for POSIX, MinGW, and Cygwin"
    echo "vs2005            Generate Visual Studio 2005 project files"
    echo "vs2008            Generate Visual Studio 2008 project files"
    echo "vs2010            Generate Visual Studio 2010 project files"
    echo "vs2012            Generate Visual Studio 2012 project files"
    echo "vs2013            Generate Visual Studio 2013 project files"
    echo "vs2015            Generate Visual Studio 2015 project files"
    echo "vs2017            Generate Visual Studio 2017 project files"
    echo "vs2019            Generate Visual Studio 2019 project files"
    echo "vs2022            Generate Visual Studio 2022 project files"
    echo "xcode4            Generate Apple Xcode 4 project files"
    echo
}

if [ "$1" = "" ]; then
    PrintHelp
    exit
fi

if [ "$1" = "unix" ]; then
    if [ "$2" = "clean" ]; then
        "$(dirname "$0")/../vendor/Premake/premake5-linux" clean
    elif [ "$2" = "help" ]; then
        "$(dirname "$0")/../vendor/Premake/premake5-linux" --help
    else
        "$(dirname "$0")/../vendor/Premake/premake5-linux" $2
    fi
    exit
elif [ "$1" = "mac" ]; then
    if [ "$2" = "clean" ]; then
        "$(dirname "$0")/../vendor/Premake/premake5-macosx" clean
    elif [ "$2" = "help" ]; then
        "$(dirname "$0")/../vendor/Premake/premake5-macosx" --help
    else
        "$(dirname "$0")/../vendor/Premake/premake5-macosx" $2
    fi
    exit
else
    echo "ERROR: Action did not recognized. This script allows building only Linux or MacOS projects"
    exit
fi