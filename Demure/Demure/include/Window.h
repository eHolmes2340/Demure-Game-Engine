#pragma once


#include <Engine.h>


namespace Demure
{

	struct WindowProps
	{
		std::string Title; 
		unsigned int Width; 
		unsigned int Height; 

		//Struct constructor
		WindowProps(const std::string& title = "Demure Game Engine", 
			unsigned int width = 1280,
			unsigned int height=720)
			:Title(title), Width(width), Height(height) {}
	};


	class DEMURE_API Window
	{
	public: 
		Window(const WindowProps& props); 
		~Window(); 

		void OnUpdate(); 
		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height;  }


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