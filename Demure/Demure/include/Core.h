//File		 : Core.h
//Programmer : Erik Holmes
//Date		 : Aug 18, 2025
//Description: This file will contain the macro used to export the sandbox.exe


#pragma once



#ifdef _WIN32
#ifdef DEMURE_BUILD_DLL
// When building the DLL, export symbols
#define DEMURE_API __declspec(dllexport)
#else
// When using the DLL, import symbols
#define DEMURE_API __declspec(dllimport)
#endif
#else
// On non-Windows platforms, define as empty or use GCC visibility attributes if desired
#define DEMURE_API
#endif
