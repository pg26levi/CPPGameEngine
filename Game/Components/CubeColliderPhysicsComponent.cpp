#include "CubeColliderPhysicsComponent.h"

CubeColliderPhysicsComponent::CubeColliderPhysicsComponent(std::shared_ptr<Actor> owner, float extents, glm::vec3 velocity) :
	PhysicsComponent(owner, false, true, velocity)
{



}

bool CubeColliderPhysicsComponent::IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComp)
{
	return false;
}
