#include "RenderEngine.h"
#include "Game/Components/RenderComponent.h"
#include "Engine/Public/EngineInterface.h"

RenderEngine* RenderEngine::sInstance = nullptr;

RenderEngine* RenderEngine::GetInstance()
{
	if (!sInstance)
		sInstance = new RenderEngine;

	return sInstance;
}

void RenderEngine::AddRenderingComponent(std::shared_ptr<RenderComponent> component)
{
	mRenderComponentList.push_back(component);
}

void RenderEngine::Render(exEngineInterface* engineInterface)
{
	for (std::weak_ptr<RenderComponent> componentToRender : mRenderComponentList) 
	{

		if (!componentToRender.expired()) 
		{
			componentToRender.lock()->Render(engineInterface);
		}

	}

}

RenderEngine::RenderEngine() 
{

}