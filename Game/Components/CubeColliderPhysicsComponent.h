#pragma once
#include "PhysicsComponent.h"
class CubeColliderPhysicsComponent : public PhysicsComponent
{

public:

	CubeColliderPhysicsComponent() = delete;
	CubeColliderPhysicsComponent(std::shared_ptr<Actor> owner, float extents, glm::vec3 velocity);

protected:

	virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComp) override;

	float m_Extents;

};

