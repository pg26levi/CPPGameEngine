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

	int renderedObjects = 0;
	for (std::weak_ptr<RenderComponent> componentToRender : mRenderComponentList) 
	{

		if (!componentToRender.expired()) 
		{
			componentToRender.lock()->Render(engineInterface);
			renderedObjects++;
		}

	}

	engineInterface->DrawText(0, exVector2{ 0.0f, 125.0f }, ("Objects in scene: " + std::to_string(renderedObjects)).c_str(), exColor{255, 255 ,255 ,255}, 0);

}

RenderEngine::RenderEngine() 
{

}