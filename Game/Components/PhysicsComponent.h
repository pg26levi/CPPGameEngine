#pragma once
#include "Game/Components/Component.h"
#include "Engine/Public/EngineTypes.h"

class PhysicsComponent;

typedef std::function<void(glm::vec3, std::weak_ptr<Actor>, std::weak_ptr<PhysicsComponent>)> CollisionEventSignature;

class PhysicsComponent : public Component,
						 public std::enable_shared_from_this<PhysicsComponent>
{

	friend class PhysicsEngine;

public:

	PhysicsComponent() = delete;
	PhysicsComponent(std::shared_ptr<Actor> owner, bool isStatic, bool isGravityEnabled, glm::vec3 velocity);

	// TODO
	// float GetSpeed() const;

	// Physics function
	
	virtual void InitializeComponent() override;

	// Getter and Setters
	glm::vec3 GetVelocity() const;
	void SetVelocity(const glm::vec3 inVelocity);

	virtual bool IsCollisionDetected(std::shared_ptr<PhysicsComponent> otherComponent);

	void ListenForCollision(CollisionEventSignature& delegateToAdd);

protected:

	bool mIsStatic;
	bool mIsGravityEnabled;

	glm::vec3 mVelocity;

	virtual void Physics();

private:

	std::list<CollisionEventSignature> mCollisionEvents;

};

