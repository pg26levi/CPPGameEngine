#pragma once

#include "Game/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"

class Football : public Actor
{


public:

	Football(exColor ballColor, float radius);


	virtual void BeginPlay() override;

	virtual void InitializeActor(const glm::vec3 spawnPosition) override;

	void SetVelocity(glm::vec3 velocity);

	void OnCollisionDetected(glm::vec3 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

private:

	exColor mBallColor;
	float mRadius;

};

