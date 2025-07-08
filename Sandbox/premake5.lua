outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
    location "Sandbox"

    characterset "Unicode"
    buildoptions { "/utf-8" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Sandbox/include/**.h",
        "Sandbox/src/**.cpp",
        "Sandbox/src/**.h"
    }

    includedirs
    {
        "../Demure/Demure/include",   
        "Sandbox/include", 
        "Sandbox/src",      -- Include Demure headers
        "../vendor/glfw/include",
        "../vendor/spdlog/include" -- If you also need glfw headers here
    }

    links
    {
        "Demure",            -- Link Demure shared library
        "opengl32"
    }
    dependson
    {
        "Demure"
    }

   filter "system:windows"
    systemversion "latest"
    defines { "SANDBOX_PLATFORM_WINDOWS" }

    postbuildcommands {
        'if exist "..\\..\\Demure\\bin\\' .. outputdir .. '\\Demure\\Demure.dll" (',
        '    echo Copying Demure.dll...',
        '    copy /Y "..\\..\\Demure\\bin\\' .. outputdir .. '\\Demure\\Demure.dll" "$(TargetDir)"',
        ')'
    }


    filter "configurations:Debug"
        defines "SANDBOX_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SANDBOX_RELEASE"
        runtime "Release"
        optimize "on"
