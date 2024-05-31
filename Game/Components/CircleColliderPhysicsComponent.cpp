#include "CircleColliderPhysicsComponent.h"
#include "TransformComponent.h"
#include "Game/Actors/Actor.h"
#include "math.h"

CircleColliderPhysicsComponent::CircleColliderPhysicsComponent(std::shared_ptr<Actor> owner, float radius, glm::vec3 velocity) :
	PhysicsComponent(owner, false, true, velocity)
{
	m_Radius = radius;


}

bool CircleColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComp)
{
	if (!otherComp)
		return false;

	if (std::shared_ptr<CircleColliderPhysicsComponent> otherCircleColliderComponent = std::dynamic_pointer_cast<CircleColliderPhysicsComponent>(otherComp))
	{

		const std::shared_ptr<TransformComponent> currentTransformComponent = m_Owner->FindComponentOfType<TransformComponent>();
		const std::shared_ptr<TransformComponent> otherTransformComponent = otherCircleColliderComponent->GetOwner()->FindComponentOfType<TransformComponent>();

		if(currentTransformComponent == nullptr || otherTransformComponent == nullptr)
		{
			return false;
		}

		const glm::vec3 currentCenter = currentTransformComponent->GetPosition();
		const glm::vec3 otherCenter = otherTransformComponent->GetPosition();

		const glm::vec3 distanceVector = currentCenter - otherCenter;

		float distX = distanceVector.x;
		float distY = distanceVector.y;

		const float distance = sqrt((pow(distX, 2) + pow(distY, 2)));

		return (distance <= (m_Radius + otherCircleColliderComponent->m_Radius));

	}

	return false;
}
