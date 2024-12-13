workspace "Rend"
    architecture "x64"
    startproject "Sandbox"

    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
copydllfrom = "$(SolutionDir)bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Rend/Rend.dll"
copydllto = "$(SolutionDir)bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox"

project "Rend"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",

    }

    includedirs
    {
        "vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines 
        {
            "RD_PLATFORM_WINDOWS",
            "RD_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPYFILE} %{cfg.buildtarget.relpath} $(SolutionDir)/bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "RD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RD_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "RD_DIST"
        symbols "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "vendor/spdlog/include",
        "src"
    }
    
    links
    {
        "Rend"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines 
        {
            "RD_PLATFORM_WINDOWS",
            "_WINDLL"
        }

    filter "configurations:Debug"
        defines "RD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RD_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "RD_DIST"
        symbols "On"