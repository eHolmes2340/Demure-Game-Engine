
//File			: Sandbox.cpp
//Team			: Erik Holmes
//Date Editted  : 07/03/2025
//Description   :

#include <Application.h>
#include <spdlog/spdlog.h>


//Method     : SandboxApp
//Description: This
class SandboxApp :public Demure::Application
{
public:

	SandboxApp() {};
	~SandboxApp() {}; 


	//Method	 : void OnUpdate 
	//Description: This function overrides the OnUpdate method found in the 
	//             Application class Demure/include/Application.h


};


//Function		: Demure::Application * Demure::CreateApplication()
//Description   : This function will create a new SandboxApp 
Demure::Application* Demure::CreateApplication() {
	return new SandboxApp(); 
}
