local rootDir = "../"

project("AI-Instances")
    location(rootDir .. "AI-Instances")
    kind("StaticLib")
    language("C++")
    cppdialect("C++20")
    staticruntime("on")
    -- toolset("v143") -- Hopefully it wont be necessary. If yes, it needs to be specify per platform!

    targetdir(rootDir .. "bin/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")
    objdir(rootDir .. "bin-int/%{prj.name}_%{cfg.architecture}/%{cfg.buildcfg}")

    pchheader("palepch.h")
    pchsource(rootDir .. "%{prj.name}/src/palepch.cpp")

    files({
        rootDir .. "%{prj.name}/src/**.h",
        rootDir .. "%{prj.name}/src/**.cpp"
    })

    includedirs({
        rootDir .. "%{prj.name}/src",
        rootDir .. "%{prj.name}/vendor/Spdlog/include"
    })

    links({ "Pale-Engine" })

    filter("files:**.tpp")
        flags({ "ExcludeFromBuild" })
