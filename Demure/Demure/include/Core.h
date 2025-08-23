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
