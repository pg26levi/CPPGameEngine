#pragma once
#include "Actor.h"
#include "Game/Singletons/WorldManager.h"

class Player : public Actor
{

public:

	Player();
	Player(std::string& name);
	~Player();

	virtual void BeginPlay() override;

	virtual void InitializeActor(const glm::vec3 spawnPosition) override;

	virtual void Tick(float deltaSeconds) override;

	std::shared_ptr<CameraComponent> GetCamera() { return m_Camera; };

protected:

	std::shared_ptr<CameraComponent> m_Camera;

};

