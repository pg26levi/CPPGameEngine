#include "WorldManager.h"

WorldManager* WorldManager::sInstance = nullptr;

WorldManager* WorldManager::GetInstance()
{
	if (!sInstance) 
	{
		sInstance = new WorldManager();
	}
	return sInstance;
}

void WorldManager::SetActiveCamera(std::shared_ptr<Actor> inActor)
{

	std::shared_ptr<CameraComponent> camera = inActor->FindComponentOfType<CameraComponent>();

	if (camera)
		m_ActiveCamera = camera;
	else
		throw "Error! Tried to assign actor without camera component to world camera";

}

void WorldManager::Tick()
{
	int tickingActors = 0;
	for (std::shared_ptr<Actor> actor : m_Actors) 
	{
		if (actor->shouldTick) 
		{
			actor->Tick(Time::DeltaTime);
			tickingActors++;
		}

	}

}

WorldManager::WorldManager()
{

}
