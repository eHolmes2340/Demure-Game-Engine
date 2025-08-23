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

		if (!glfwInit())
		{
			DM_CORE_ERROR("Failed initalizing GLFW!");
			return; 
		}


		m_Window = glfwCreateWindow(800, 600, "Demure Engine", nullptr, nullptr); 
		if (!m_Window)
		{
			spdlog::error("GLFW failed to create Window"); 
			glfwTerminate(); 
			return; 
		}

		

		glfwMakeContextCurrent(m_Window); 
		glfwSwapInterval(1); // Enable vsync

		
		if (!gladLoadGL(glfwGetProcAddress))
		{
			spdlog::error("Failed to init Glad!"); 
			return; 
		}
		
		//Found 
		DM_CORE_INFO("OpenGL Vendor   : {}", (const char*)glGetString(GL_VENDOR));
		DM_CORE_INFO("OpenGL Renderer : {}", (const char*)glGetString(GL_RENDERER));
		DM_CORE_INFO("OpenGL Version  : {}", (const char*)glGetString(GL_VERSION));

		//Setup ImGui using the DemureImGui class
		m_UI = new DemureImGui(m_Window); 

	
	}

	//Deconstructor: Application::~Application()
	//Description  : Cleans up the window + ImGui
	Application::~Application() {
		
		delete m_UI; 
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
			
			//Create a ImGui frame
			ImGui_ImplOpenGL3_NewFrame(); 
			ImGui_ImplGlfw_NewFrame(); 
			ImGui::NewFrame(); 

			ImGui::Begin("Hello"); 
			ImGui::Text("Test"); 
			ImGui::End();


			//Render ImGui
			ImGui::Render();

			int display_w, display_h;
			glfwGetFramebufferSize(m_Window, &display_w, &display_h);
			glViewport(0, 0, display_w, display_h);

			// Clear background (dark grey-blue instead of black)
			glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(m_Window);
		}
	}


}