#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::BeginPlay()
{
}

void Actor::EndPlay()
{
}

void Actor::Tick(float deltaSeconds)
{
}

void Actor::InitializeActor(const Vector3 spawnPosition)
{
	mTransformComponent = AddComponentOfType<TransformComponent>(spawnPosition);
}
