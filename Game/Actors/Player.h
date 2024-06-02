#pragma once
#include "Actor.h"
#include "Game/Singletons/WorldManager.h"

class Player : public Actor
{

public:

	Player() = default;

	virtual void BeginPlay() override;

	virtual void InitializeActor(const glm::vec3 spawnPosition) override;

	virtual void Tick(float deltaSeconds) override;

protected:

	std::shared_ptr<CameraComponent> m_Camera;

};

