#pragma once

//File			: EntryPoint.h
//Team			: Erik Holmes
//Date Editted  : 03/07/2025
//Description   : This file contains the entry point and main function of our game engine. 

#include <Application.h>


//Defining a function that must be defined by the client app Sandbox 
//extern 
extern Demure::Application* Demure::CreateApplication(); 

int main()
{
    //Call the Demure::CreateApplication() from sandbox 

    
    Demure::Application* app = Demure::CreateApplication(); 
    app->Run();                           
    delete app;
}