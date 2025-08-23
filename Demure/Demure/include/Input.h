//File      :
//Programmer:


#pragma once
#include<Core.h>
#include<Engine.h>

namespace Demure
{

    //Class      :Input
    //Description:
    class DEMURE_API Input
    {
    public:
        static bool IsKeyPressed(int keycode);
        static bool IsMouseButtonPressed(int button);
        static std::pair<double, double> GetMousePosition();

    private:
        static GLFWwindow* GetWindow(); // Internal helper
    };
}


