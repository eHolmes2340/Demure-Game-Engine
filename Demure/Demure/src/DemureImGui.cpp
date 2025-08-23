
#include <DemureImGui.h>


namespace Demure
{
	//Constructor: DearImGui
	//Description: 
	DemureImGui::DemureImGui(GLFWwindow* window)
	{
		IMGUI_CHECKVERSION(); 
		ImGui::CreateContext(); 
		ImGuiIO& io = ImGui::GetIO(); 
		(void)io; 

		ImGui::StyleColorsDark(); 


		//Setup Platform/Render backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);

	}


	DemureImGui::~DemureImGui()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}


