
//File			: Application.h 
//Team			: Erik Holmes
//Date Editted  : 07/03/2025
//Description   : This header file contains the Application object. 
#pragma once
#include<Core.h>


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
		class Window* m_Window; 
		bool m_Running = true; 
	};



	Application* CreateApplication(); 

}


