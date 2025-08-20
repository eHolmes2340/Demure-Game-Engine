//File				: Application.cpp
//Programmer		: Erik Holmes
//Date Edited		: Aug 20, 2025 
//Description		: This file contains all the functions used in the Window and Application.  


#include <Application.h>
#include <GLFW/glfw3.h>
#include<spdlog/spdlog.h>





namespace Demure
{
	

	//Function		: WindowSizeCallBack(window,int width, height)
	//Return        : void
	//Description   : Call back function for window resizing. 
	void WindowSizeCallBack(GLFWwindow* window, int width, int height)
	{
		spdlog::info("Window resized: Width = {} Height = {}", width, height);
		glViewport(0, 0, width, height);
	}




	//Constructor: Application::Application()
	//Description: initalizes the window and sets the singleton instance 
	Application::Application()
	{
		if (!glfwInit())
		{
			spdlog::error("Failed initalizing GLFW!!"); 
			return; 
		}

		spdlog::info("Initalized complete"); 

		m_Window = glfwCreateWindow(800, 600, "Demure Engine", nullptr, nullptr); 
		if (!m_Window)
		{
			spdlog::error("GLFW failed to create Window"); 
			glfwTerminate(); 
			return; 
		}

		glfwMakeContextCurrent(m_Window); 

		glfwSetWindowSizeCallback(m_Window, Demure::WindowSizeCallBack);

	}

	//Deconstructor: Application::~Application()
	//Description  : Cleans up the window 
	Application::~Application() {
		
		glfwDestroyWindow(m_Window); 
		glfwTerminate(); 
	}


	//Method     : void Application::Run()
	//Description: This method is the main loop 
	void Application::Run()
	{
		while (!glfwWindowShouldClose(m_Window))
		{
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT); 

			glfwSwapBuffers(m_Window); 
		}
	}


}