#pragma once
#include "PhysicsComponent.h"
class CircleColliderPhysicsComponent :
    public PhysicsComponent
{

public:

    CircleColliderPhysicsComponent() = delete;

    CircleColliderPhysicsComponent(std::shared_ptr<Actor> owner, float radius, Vector3 velocity);

protected:

    virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComp) override;

    float m_Radius;

};

