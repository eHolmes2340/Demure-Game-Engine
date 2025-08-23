#include  <Window.h>

namespace Demure
{
	Window::Window(const WindowProps& props)
	{
		Init(props); 
	}


	Window::~Window()
	{
		ShutDown(); 
	}

    void Window::Init(const WindowProps& props)
    {
        
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if (!glfwInit())
        {
            DM_CORE_ERROR("Failed to initialize GLFW!");
            m_Window = nullptr;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            DM_CORE_ERROR("Failed to create GLFW Window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1); // Enable vsync


       
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


	void Window::ShutDown()
	{
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
            m_Window = nullptr; 
        }
		
		glfwTerminate(); 
	}


	void Window::OnUpdate()
	{
        if (!m_Window) return; 
		glfwPollEvents(); 
		glfwSwapBuffers(m_Window); 
	}
}