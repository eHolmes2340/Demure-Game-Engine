//File		  : Window,h
//Programmer  : Erik Holmes
//Last Editted: Aug 23,2025
//Description : This file contains the window class. 


#pragma once
#include <Engine.h>


namespace Demure
{

	//Struct	 : WindowProps
	//Description: This struct contains the Window Properties 
	struct WindowProps
	{
		std::string Title; 
		unsigned int Width; 
		unsigned int Height; 

		//Struct constructor: 
		WindowProps(const std::string& title = "Demure Game Engine", 
			unsigned int width = 1280,
			unsigned int height=720)
			:Title(title), Width(width), Height(height)
		{}
	};

	//Class		 : Window
	//Description: This class contains the Window Object 
	class DEMURE_API Window
	{
	public: 
		Window(const WindowProps& props); 
		~Window(); 

		void OnUpdate(); 
		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height;  }

		//App/Input can access the GLFW window
		inline GLFWwindow* GetNativeWindow()const { return m_Window; }

	//Private methods 
	private:
		void Init(const WindowProps& props); 
		void ShutDown(); 


	//Private members 
	private: 
		GLFWwindow* m_Window=nullptr; 

		struct WindowData
		{
			std::string Title = ""; 
			unsigned int Width = 0; 
			unsigned int Height = 0; 
		}; 
	
		WindowData m_Data; 
 
	};
}