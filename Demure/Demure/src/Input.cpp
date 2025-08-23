//File		  : Input.cpp 
//Programmer  : Erik Holmes
//Last Editted: Aug 23, 2025 
//Description : This file contains all the methods from the Input class found in the Input.h file

#include <Input.h>
#include <Application.h>

namespace Demure
{

	//Method	 : Input::GetWindow()
	//Description: This method will include 
	GLFWwindow* Input::GetWindow()
	{
		return static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	}

	//Method	 : bool Input::IsKeyPressed(int keycode) 
	//Description: This method will return the keypressed
	bool Input::IsKeyPressed(int keycode)
	{
		auto window = GetWindow(); 
		auto state = glfwGetKey(window, keycode); 
		return state == GLFW_PRESS || state == GLFW_RELEASE; 
	}

	//Method	 : bool Input::IsMouseButtonPressed(int button) 
	//Description: This method will get which mouse button is pressed
	bool Input::IsMouseButtonPressed(int button)
	{
		auto window = GetWindow(); 
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	//Method	 : std::pair<double,double> Input::GetMousePosition() 
	//Description: This method will get the mouse position for the screen
	std::pair<double, double> Input::GetMousePosition()
	{
		auto window = GetWindow(); 
		double xpos; 
		double ypos; 
		glfwGetCursorPos(window, &xpos, &ypos); 

		return { xpos,ypos }; 
	}
}