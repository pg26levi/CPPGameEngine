#include "Football.h"

Football::Football(exColor ballColor, float radius)
{
	mRadius = radius;
	mBallColor = ballColor;
}

void Football::BeginPlay()
{
}

void Football::InitializeActor(const glm::vec3 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<CircleRenderComponent>(mBallColor, mRadius, 0);
	std::shared_ptr<CircleColliderPhysicsComponent> colliderComp = AddComponentOfType<CircleColliderPhysicsComponent>(mRadius, glm::vec3{0.0f, 1.0f, 0.0f});

	CollisionEventSignature collisionDelegate = std::bind(&Football::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	colliderComp->ListenForCollision(collisionDelegate);
}

void Football::SetVelocity(glm::vec3 newVelocity)
{

	std::shared_ptr<PhysicsComponent> physicsComp = FindComponentOfType<PhysicsComponent>();
	if (physicsComp)
	{
		physicsComp->SetVelocity(newVelocity);
	}

}

void Football::OnCollisionDetected(glm::vec3 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{

	if (std::shared_ptr<RenderComponent> renderComp = FindComponentOfType<RenderComponent>())
	{
		renderComp->SetColor(exColor{ 255, 0, 0, 255 });
	}

}
