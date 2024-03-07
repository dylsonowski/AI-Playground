local rootDir = "../"

workspace("AI-Playground") -- Title of the whole project is temporary. IT WILL CHANGE IN THE FUTURE!!!!
    architecture("x64")
    configurations({ "Debug", "Release" })

    prebuildcommands({
        "git submodule update --init --recursive"
    })

    filter({ "system:windows", "action:vs*" })
        startproject("Playground") -- When real project structure will be configure, change it to game project. !IMPORTANT: Only for Visual Studio building!
        location(rootDir)
        flags({ "MultiProcessorCompile", "NoMinimalRebuild" })

    filter("system:linux or system:macosx")
        location(rootDir .. "bin")

    filter("system:windows")
        defines({ "PLATFORM_WINDOWS" })

    filter("system:linux")
        defines({ "PLATFORM_LINUX" })

    filter("system:macosx")
        defines({ "PLATFORM_MACOS" })

    filter("configurations:Debug")
        defines({ "_DEBUG_" })
        runtime("Debug")
        symbols("on")

    filter("configurations:Release")
        defines({ "_RELEASE_" })
        runtime("Release")
        optimize("on")

include(rootDir .. "Pale-Engine")
include(rootDir .. "Playground")
include(rootDir .. "AI-Instances")

newaction {
    trigger = "clean",
    description = "Remove all binaries and generated files.",
    execute = function()
        print("Removing binaries...")
        os.rmdir("../bin")
        print("Removing intermediate binaries")
        os.rmdir("../bin-int")
        print("Removing project files")
        os.rmdir("../.vs")
        os.remove("../**.sln")
        os.remove("../**.vcxproj")
        os.remove("../**.vcxproj.filters")
        os.remove("../**.vcxproj.user")
        os.remove("../**Makefile")
        os.remove("../**.make")
        print("Done!")
    end
}