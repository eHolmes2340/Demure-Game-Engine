#include "Renderer.h"

namespace Demure
{

	//Method	 : void Renderer::Init() 
	//Description: This method will setup OpenGL State (enables depth testing, blending, etc)
	//             - Load and compiles shaders 
	//             - Creates global objects like vectors/index buffers that are reused. 
    Renderer::SceneData* Renderer::s_SceneData = nullptr;


    void Renderer::BeginScene(const glm::mat4& viewProjection)
    {
        s_SceneData->ViewProjectionMatrix = viewProjection;

        // Clear screen each frame
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::Init()
    {
        s_SceneData = new SceneData();

        // Setup OpenGL defaults (can add more later)
        glEnable(GL_DEPTH_TEST);

        std::cout << "Renderer initialized\n";
    }

    void Renderer::ShutDown()
    {
        delete s_SceneData;
        s_SceneData = nullptr;
        std::cout << "Renderer shutdown\n";
    }

  

    void Renderer::EndScene()
    {
        // For now, nothing — this is where you’d do batching or finalize commands
    }

    void Renderer::Submit(const glm::mat4& transform, unsigned int vao, unsigned int indexCount)
    {
        // Bind your shader (in future you’ll have a Shader class)
        // Example: shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
        //          shader->SetMat4("u_Transform", transform);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    }
}