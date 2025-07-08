#include <Application.h>



namespace Demure
{
	//Constructor: Application::Application()
	//Description: initalizes the window and sets the singleton instance 
	Application::Application()
	{
		
	}

	//Deconstructor: Application::~Application()
	//Description  : Cleans up the window 
	Application::~Application() {
		delete m_Window;
	}


	//Method     : void Application::Run()
	//Description: This method is the main loop 
	void Application::Run()
	{
		
	}
}