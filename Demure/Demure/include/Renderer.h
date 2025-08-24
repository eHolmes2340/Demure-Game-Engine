#pragma once
#include <Engine.h>
namespace Demure
{
	//Class		 : Renderer
	//Description:  
	class DEMURE_API Renderer
	{

	public:
		static void Init(); 
		static void ShutDown();//Cleanup 
		
		static void BeginScene(const glm::mat4& viewProjection); 
		static void EndScene();
		
		static void Submit(const glm::mat4& transform, unsigned int vao, unsigned int indexCount);
	
	
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* s_SceneData;
	};
}


