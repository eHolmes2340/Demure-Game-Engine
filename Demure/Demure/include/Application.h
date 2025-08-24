
//File			: Application.h 
//Team			: Erik Holmes
//Date Editted  : 07/03/2025
//Description   : This header file contains the Application object. 
#pragma once

#include<Engine.h>
#include <Window.h>
#include <Input.h>
#include <Renderer.h>

namespace Demure
{

	//Class	     : Application
	//Description: Defines the Core application class that runs the engine loop. 
	//				Holds the window, and manages engine lifetime
	class DEMURE_API Application
	{
	public:
		Application();
		virtual ~Application(); 
		void Run(); 

		//Get 
		static Application& Get() { return *s_Instance;  }

		//Fetch the Window 
		Window& GetWindow() { return *m_Window;  }

	private:
		
		bool m_Running = true; 

		std::unique_ptr<Window> m_Window=nullptr; 
		

		//Use to get current s_Instance
		static Application* s_Instance; 
	
	};


	//This will defined in the sandbox. 
	Application* CreateApplication(); 

}


