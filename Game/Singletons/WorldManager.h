#pragma once
#include "Game/GameCore/ActorTypes.h"

#define WORLD WorldManager::GetInstance()

class WorldManager
{

public:

	static WorldManager* GetInstance();

	template<std::derived_from<Actor> ActorType, typename ...Args>
	std::shared_ptr<ActorType> SpawnActorOfClass(glm::vec3 spawnLocation, Args... arguments)
	{
		//std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(arguments...);
		std::shared_ptr<ActorType> newActor = Actor::MakeActor<ActorType>(arguments...);

		newActor->InitializeActor(spawnLocation);
		m_Actors.push_back(newActor);
		return newActor;
	}

	std::weak_ptr<CameraComponent> GetActiveCamera() const { return m_ActiveCamera; }

	void SetActiveCamera(std::shared_ptr<Actor> inActor);

	void Tick();

private:

	WorldManager();

	static WorldManager* sInstance;

	std::list<std::shared_ptr<Actor>> m_Actors;

	std::weak_ptr<CameraComponent> m_ActiveCamera;

};

