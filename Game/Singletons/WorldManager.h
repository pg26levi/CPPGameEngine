#pragma once
#include "Game/GameCore/ActorTypes.h"

#define WORLD WorldManager::GetInstance()

class WorldManager
{

public:

	static WorldManager* GetInstance();

	template<std::derived_from<Actor> ActorType, typename ...Args>
	std::shared_ptr<ActorType> SpawnActorOfClass(Vector3 spawnLocation, Args... arguments)
	{
		//std::shared_ptr<ActorType> newActor = std::make_shared<ActorType>(arguments...);
		std::shared_ptr<ActorType> newActor = Actor::MakeActor<ActorType>(arguments...);

		newActor->InitializeActor(spawnLocation);
		
		return newActor;
	}


private:

	WorldManager();

	static WorldManager* sInstance;

};

