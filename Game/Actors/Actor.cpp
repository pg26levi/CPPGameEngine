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
	for (std::shared_ptr<Component> comp : m_Components) 
	{
		comp->TickComponent(Time::DeltaTime);
	}

}

void Actor::InitializeActor(const glm::vec3 spawnPosition)
{
	mTransformComponent = AddComponentOfType<TransformComponent>(spawnPosition);
}
