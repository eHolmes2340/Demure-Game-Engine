//File				: Application.cpp
//Programmer		: Erik Holmes
//Date Edited		: Aug 20, 2025 
//Description		: This file contains all the functions used in the Window and Application.  


#include <Application.h>
namespace Demure
{
	
	//Constructor: Application::Application()
	//Description: initalizes the window and sets the singleton instance 
	Application::Application()
	{
		

		Log::Init(); 

		m_Window = std::make_unique<Window>(WindowProps("Demure Engine", 1280, 720)); 
		
		//Debugging Info 

		DM_CORE_INFO("OpenGL Vendor   : {}", (const char*)glGetString(GL_VENDOR));
		DM_CORE_INFO("OpenGL Renderer : {}", (const char*)glGetString(GL_RENDERER));
		DM_CORE_INFO("OpenGL Version  : {}", (const char*)glGetString(GL_VERSION));

	}

	//Deconstructor: Application::~Application()
	//Description  : Cleans up the window + ImGui
	Application::~Application() {
			
	}



	//Method     : void Application::Run()
	//Description: This method is the main loop 
	void Application::Run()
	{
		while (m_Running)

		{
			m_Window->OnUpdate(); 
		}
	}


}