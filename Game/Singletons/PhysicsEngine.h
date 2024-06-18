#pragma once
#include "Game/GameCore/Utils.h"

#define PHYSICS_ENGINE PhysicsEngine::GetInstance()

class PhysicsComponent;
class exEngineInterface;

class PhysicsEngine
{

public:

	static PhysicsEngine* GetInstance();

	// Add render components to render list
	void AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd);

	// Render all render components from the list
	void Physics();



	// Todo write a function to remove the rendering component



private:

	PhysicsEngine();

	static PhysicsEngine* sInstance;

	std::list<std::weak_ptr<PhysicsComponent>> mPhysicsComponentList;



};

