outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "../vendor/imgui/premake5.lua"

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

    includedirs
    {
        "Demure/src",
        "Demure/include",

         
        --Glad Header files
        "../vendor/glad/include",
        -- Window GLFW
        "../vendor/glfw/include",
        --Logging 
        "../vendor/spdlog/include",
        --DearImGui
        "../vendor/imgui",
        "../vendor/imgui/backends"

       
    }

    files
    {
        "Demure/include/**.h",
        "Demure/src/**.cpp",
        "../vendor/glad/src/gl.c"
    }
    libdirs
    {
        --Where the lib file is found
        "../vendor/glfw/lib-vc2022"
    }

    links 
    {
        "ImGui",
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
