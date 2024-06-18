#include "CubeColliderPhysicsComponent.h"
#include "Game/Components/TransformComponent.h"
#include "Game/Actors/Actor.h"

CubeColliderPhysicsComponent::CubeColliderPhysicsComponent(std::shared_ptr<Actor> owner, float extents, glm::vec3 velocity) :
	PhysicsComponent(owner, false, true, velocity)
{

	m_Extents = extents;

}

bool CubeColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComp)
{
	if (!otherComp)
		return false;

	if (otherComp->GetOwner()->GetName() == "b")
		return false;

	if (std::shared_ptr<CubeColliderPhysicsComponent> otherCubeColliderComponent = std::dynamic_pointer_cast<CubeColliderPhysicsComponent>(otherComp))
	{

		const std::shared_ptr<TransformComponent> currentTransformComponent = m_Owner->FindComponentOfType<TransformComponent>();
		const std::shared_ptr<TransformComponent> otherTransformComponent = otherCubeColliderComponent->GetOwner()->FindComponentOfType<TransformComponent>();

		if (currentTransformComponent == nullptr || otherTransformComponent == nullptr)
		{
			return false;
		}

		const glm::vec3 currentCenter = currentTransformComponent->GetPosition();
		const glm::vec3 otherCenter = otherTransformComponent->GetPosition();

		const glm::vec3 ourMax = glm::vec3(m_Extents) + currentCenter;
		const glm::vec3 otherMax = glm::vec3(otherCubeColliderComponent->m_Extents) + otherCenter;

		const glm::vec3 ourMin = currentCenter - glm::vec3(m_Extents);
		const glm::vec3 otherMin = otherCenter - glm::vec3(m_Extents);

		// Collision check between extents
		if ((ourMin.x <= otherMax.x && ourMax.x >= otherMin.x)
		&& (ourMin.y <= otherMax.y && ourMax.y >= otherMin.y)
		&& (ourMin.z <= otherMax.z && ourMax.z >= otherMin.z)) 
		{
			return true;
		}

	}


	return false;
}
