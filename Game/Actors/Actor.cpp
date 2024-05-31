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

void Actor::InitializeActor(const glm::vec3 spawnPosition)
{
	mTransformComponent = AddComponentOfType<TransformComponent>(spawnPosition);
}
