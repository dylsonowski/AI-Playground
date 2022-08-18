local rootDir = "../"

project("Untitled-Pokemon-Game")
    location(rootDir .. "Untitled-Pokemon-Game")
    kind("ConsoleApp")
    language("C++")
    cppdialect("C++20")
    staticruntime("on")
    -- toolset("v143") -- Hopefully it wont be necessary. If yes, it needs to be specify per platform!

    targetdir(rootDir .. "bin/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")
    objdir(rootDir .. "bin-int/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")

    files({
        rootDir .. "%{prj.name}/src/**.h",
        rootDir .. "%{prj.name}/src/**.cpp"
    })

    includedirs({
        rootDir .. "Pale-Engine/src"
    })

    links({"Pale-Engine"})

    filter("files:**.tpp")
        flags({ "ExcludeFromBuild" })