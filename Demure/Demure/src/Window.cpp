//File        : Window.cpp 
//Programmer  : Erik Holmes
//Last Editted: Aug 23, 2025
//Description : This file contains all the Window class Methods

#include  <Window.h>
namespace Demure
{

    //Constructor: Window(const WindowProps& props) 
    //Description: This constructor will take in the address of WindowProps struct. This struct can be found in the Window.h 
	Window::Window(const WindowProps& props)
	{
		Init(props); 
	}


    //Destructor : ~Window()
    //Description: The Destructor calls the ShutDown method
	Window::~Window()
	{
		ShutDown(); 
	}


    //Method       : Window::Init(const WindowProps& props)
    //Parameters   : const WindowProps& props 
    //Description  : This method will initalize GLFW and GLAD 
    void Window::Init(const WindowProps& props)
    {
        
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        //GLFW Initalize 
        if (!glfwInit())
        {
            DM_CORE_ERROR("Failed to initialize GLFW!");
            m_Window = nullptr;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        //Create the window 
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            DM_CORE_ERROR("Failed to create GLFW Window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1); // Enable vsync

        //Load Glad 
        if (gladLoaderLoadGL() == 0)
        {
            DM_CORE_ERROR("Failed to intialize GLAD!"); 
            glfwDestroyWindow(m_Window);
            m_Window = nullptr; 
            glfwTerminate(); 
            return;
            
        }

        DM_CORE_TRACE("Created window {} ({} x {})", props.Title, props.Width, props.Height);
    }

    //Method     : ShutDown()
    //Description: This method will shutdown GLFW 
	void Window::ShutDown()
	{
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            m_Window = nullptr; 
        }
		
		glfwTerminate(); 
	}

    //Method     : Window::OnUpdate
    //Description: This function will update our window. 
	void Window::OnUpdate()
	{
        if (!m_Window) return; 
		glfwPollEvents(); 
		glfwSwapBuffers(m_Window); 
	}
}