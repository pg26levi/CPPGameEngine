#include "PhysicsEngine.h"
#include "Game/Components/PhysicsComponent.h"
#include "Engine/Public/EngineInterface.h"

PhysicsEngine* PhysicsEngine::sInstance = nullptr;

PhysicsEngine* PhysicsEngine::GetInstance()
{
	if (!sInstance)
		sInstance = new PhysicsEngine;

	return sInstance;
}

void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> componentToAdd)
{
	mPhysicsComponentList.push_back(componentToAdd);
}

void PhysicsEngine::Physics()
{
	for (std::weak_ptr<PhysicsComponent> physicsComp : mPhysicsComponentList)
	{
		if (!physicsComp.expired())
		{
			physicsComp.lock()->Physics();

			for (std::weak_ptr<PhysicsComponent> otherPhysicsComponent : mPhysicsComponentList) 
			{
				if (otherPhysicsComponent.lock() != physicsComp.lock()) 
				{
					if (physicsComp.lock()->IsCollisionDetected(otherPhysicsComponent.lock())) 
					{
						// TODO change resolution based on requirement
						const glm::vec3 newVelocity = physicsComp.lock()->GetVelocity() * -1.0f;
						physicsComp.lock()->SetVelocity(newVelocity);

						// call collision events
						for (CollisionEventSignature& collisionEvents : physicsComp.lock()->mCollisionEvents) 
						{
							// @TODO write function to calculate normal

							collisionEvents(glm::vec3(0.0f, 0.0f, 0.0f), otherPhysicsComponent.lock()->GetOwner(), otherPhysicsComponent.lock());

						}
					}



				}


			}
		}
	}
}

PhysicsEngine::PhysicsEngine()
{

}
