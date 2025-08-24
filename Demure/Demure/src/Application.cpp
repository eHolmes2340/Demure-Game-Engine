//File				: Application.cpp
//Programmer		: Erik Holmes
//Date Edited		: Aug 23, 2025 
//Description		: This file contains all the functions used in the Window and Application.  


#include <Application.h>

namespace Demure
{
	Application* Application::s_Instance = nullptr;

	//Prototyping 
	void TestMouseLocation(); 
	
	//Constructor: Application::Application()
	//Description: initalizes the window and sets the singleton instance 
	Application::Application()
	{
	
		Log::Init(); //Lets us use the logging lib. 

		s_Instance = this; 
		m_Window = std::make_unique<Window>(WindowProps("Demure Engine", 1280, 720)); 
		
		//Debugging Info 

		DM_CORE_INFO("OpenGL Vendor   : {}", (const char*)glGetString(GL_VENDOR));
		DM_CORE_INFO("OpenGL Renderer : {}", (const char*)glGetString(GL_RENDERER));
		DM_CORE_INFO("OpenGL Version  : {}", (const char*)glGetString(GL_VERSION));

	}

	//Deconstructor: Application::~Applicattion()
	//Description  : 
	Application::~Application() {
			
	}



	//Method     : void Application::Run()
	//Description: This method is the main loop 
	void Application::Run()
	{
		Renderer::Init(); 

		while (m_Running)
		{

			glm::mat4 vp = glm::mat4(1.0f); 
			Renderer::BeginScene(vp); 
			

			
			Renderer::EndScene(); 
			m_Window->OnUpdate(); 
		}
		Renderer::ShutDown(); 
	}


	void TestMouseLocation()
	{
		if (Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			auto [x, y] = Input::GetMousePosition();

			DM_CORE_INFO("Mouse Position x:{0} Mouse Position y:{1}", x, y);
		}
	}


}