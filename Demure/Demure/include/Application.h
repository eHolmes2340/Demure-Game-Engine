
//File			: Application.h 
//Team			: Erik Holmes
//Date Editted  : 07/03/2025
//Description   : This header file contains the Application object. 
#pragma once

#include<Engine.h>
#include <DemureImGui.h>
#include <Window.h>

namespace Demure {

	//Class	     : Application
	//Description: Defines the Core application class that runs the engine loop. 
	//				Holds the window, and manages engine lifetime
	class DEMURE_API Application
	{
	public:
		Application();
		virtual ~Application(); 
		void Run(); 

	private:
		
		bool m_Running = true; 
		std::unique_ptr<Window> m_Window=nullptr; 

	
	};


	//This will defined in the sandbox. 
	Application* CreateApplication(); 

}


