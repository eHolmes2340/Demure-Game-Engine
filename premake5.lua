workspace "Demure"
    configurations{"Debug","Release"}
    architecture "x64"
    startproject "Sandbox"

    
dofile("Demure/premake5.lua") --Demure/premake5.lua script file 
dofile("Sandbox/premake5.lua")-- Sandbox/premake5.lua script file 
