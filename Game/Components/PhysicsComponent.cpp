#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Actors/Actor.h"
#include "Game/Singletons/PhysicsEngine.h"

PhysicsComponent::PhysicsComponent(std::shared_ptr<Actor> owner, bool isStatic, bool isGravityEnabled, glm::vec3 velocity) :
	Component::Component(owner)
{
	mIsStatic = isStatic;
	mIsGravityEnabled = isGravityEnabled;
	mVelocity = velocity;
}

void PhysicsComponent::Physics()
{
	if (m_Owner) 
	{
		if (mIsStatic)
			return;

		if (std::shared_ptr<TransformComponent> transformComponent = m_Owner->FindComponentOfType<TransformComponent>()) 
		{
			const glm::vec3 newPosition = transformComponent->GetPosition() + mVelocity * (float)Time::DeltaTime * 10.0f;
			// TODO add gravity
			transformComponent->SetPosition(newPosition);
		}
	}

}

void PhysicsComponent::InitializeComponent()
{
	Component::InitializeComponent();
	// TODO Add to your physics engine

	PHYSICS_ENGINE->AddPhysicsComponent(shared_from_this());

}

glm::vec3 PhysicsComponent::GetVelocity() const
{
	return mVelocity;
}

void PhysicsComponent::SetVelocity(const glm::vec3 inVelocity)
{
	mVelocity = inVelocity;
}

bool PhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent)
{
	return false;
}

void PhysicsComponent::ListenForCollision(CollisionEventSignature& delegateToAdd)
{
	mCollisionEvents.push_back(delegateToAdd);
}
