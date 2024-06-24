include "dependencies/conandeps.premake5.lua"

workspace "Client-Server"
    conan_setup()

    configurations { "Debug", "Release" }
    architecture "x64"
    location "build"
    language "C++"
    cppdialect "C++20"
    

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        filter{}

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        filter{}


    project "Client"
        kind "ConsoleApp"

        targetdir   "build/%{prj.name}/%{cfg.buildcfg}/bin"
        objdir      "build/%{prj.name}/%{cfg.buildcfg}/obj"

        files { "./src/client/**.h", "./src/client/**.cpp" }

        
    project "Server"
        kind "ConsoleApp"

        targetdir   "build/%{prj.name}/%{cfg.buildcfg}/bin"
        objdir      "build/%{prj.name}/%{cfg.buildcfg}/obj"

        files { "./src/server/**.h", "./src/server/**.cpp" }
        