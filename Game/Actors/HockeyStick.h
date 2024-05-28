#pragma once
#include "Game/Actors/Actor.h"
#include "Engine/Public/EngineTypes.h"


class HockeyStick : public Actor
{

public:

	HockeyStick(exColor color);

	virtual void BeginPlay() override;

	virtual void InitializeActor(const Vector3 spawnPosition) override;

private:

	exColor mStickColor;

	std::shared_ptr<Actor> stickBottom;

};

