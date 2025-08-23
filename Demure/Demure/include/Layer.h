#pragma once
namespace {

	//Class		 : Layer
	//Description: kl 
	class Layer
	{

	public:
		virtual ~Layer();
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float deltaTime) {}
		virtual void OnImGuiRender() {}
	};
}


