#pragma once

#include "Game/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"

class Football : public Actor
{


public:

	Football(exColor ballColor, float radius);


	virtual void BeginPlay() override;

	virtual void InitializeActor(const Vector3 spawnPosition) override;

	void SetVelocity(Vector3 velocity);

	void OnCollisionDetected(Vector3 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent);

private:

	exColor mBallColor;
	float mRadius;

};

