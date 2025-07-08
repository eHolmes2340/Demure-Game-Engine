outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Demure"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
    location "Demure"


    characterset "Unicode"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Demure/include/**.h",
        "Demure/src/**.cpp",
    }

    includedirs
    {
        "Demure/src",
        "Demure/include",
        "../vendor/glfw/include",
        "../vendor/spdlog/include"
    }

    libdirs
    {
        "../vendor/glfw/lib-vc2022"
    }

    links 
    {
        "glfw3",
        "opengl32"
    }

    defines {
        "_GLFW_WIN32",
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"
        defines {
            "DEMURE_PLATFORM_WINDOWS",
            "DEMURE_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "DEMURE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "DEMURE_RELEASE"
        runtime "Release"
        optimize "on"
