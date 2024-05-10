local rootDir = "../"

project("Pale-Engine")
    location(rootDir .. "Pale-Engine")
    kind("StaticLib")
    language("C++")
    cppdialect("C++latest")
    staticruntime("on")
    toolset("gcc") -- Hopefully it wont be necessary. If yes, it needs to be specify per platform!

    targetdir(rootDir .. "bin/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")
    objdir(rootDir .. "bin-int/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")

    pchheader("palepch.hpp")
    pchsource(rootDir .. "%{prj.name}/src/palepch.cpp")

    files({
        rootDir .. "%{prj.name}/src/**.h",
        rootDir .. "%{prj.name}/src/**.cpp"
    })

    includedirs({
        rootDir .. "%{prj.name}/src",
        rootDir .. "%{prj.name}/vendor/Spdlog/include"
    })

    filter("files:**.tpp")
        flags({ "ExcludeFromBuild" })