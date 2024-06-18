#pragma once
#include "Game/GameCore/Utils.h"
#include "3rdParty/GLM/glm.hpp"

#define RENDER_ENGINE RenderEngine::GetInstance()

class RenderComponent;
class exEngineInterface;

class RenderEngine
{

public:

	static RenderEngine* GetInstance();

	// Add render components to render list
	void AddRenderingComponent(std::shared_ptr<RenderComponent> componentToAdd);

	// Render all render components from the list
	void Render(exEngineInterface* engineInterface);

	void DrawDebugLine(glm::vec3 start, glm::vec3 dir, float distance);


	// Todo write a function to remove the rendering component

private:

	RenderEngine();

	static RenderEngine* sInstance;

	std::list<std::weak_ptr<RenderComponent>> mRenderComponentList;



};

