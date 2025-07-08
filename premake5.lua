workspace "Demure"
    configurations{"Debug","Release"}
    architecture "x64"
    startproject "Sandbox"

    
dofile("Demure/premake5.lua")
dofile("Sandbox/premake5.lua")