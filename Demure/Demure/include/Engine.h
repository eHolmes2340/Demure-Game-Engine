#pragma once

#define DEBUG


// Standard Library
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

//Engine 
#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>




//Logging 
#ifdef DEBUG
	#include<spdlog/spdlog.h>
#endif // DEBUG


