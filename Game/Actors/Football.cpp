#include "Football.h"

Football::Football(exColor ballColor, float radius)
{
	mRadius = radius;
	mBallColor = ballColor;
}

void Football::BeginPlay()
{
}

void Football::InitializeActor(const exVector2 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<CircleRenderComponent>(mBallColor, mRadius, 0);
	std::shared_ptr<CircleColliderPhysicsComponent> colliderComp = AddComponentOfType<CircleColliderPhysicsComponent>(mRadius, exVector2{0.0f, 1.0f});

	CollisionEventSignature collisionDelegate = std::bind(&Football::OnCollisionDetected, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	colliderComp->ListenForCollision(collisionDelegate);
}

void Football::SetVelocity(exVector2 newVelocity)
{

	std::shared_ptr<PhysicsComponent> physicsComp = FindComponentOfType<PhysicsComponent>();
	if (physicsComp)
	{
		physicsComp->SetVelocity(newVelocity);
	}

}

void Football::OnCollisionDetected(exVector2 normal, std::weak_ptr<Actor> otherActor, std::weak_ptr<PhysicsComponent> otherComponent)
{

	if (std::shared_ptr<RenderComponent> renderComp = FindComponentOfType<RenderComponent>())
	{
		renderComp->SetColor(exColor{ 255, 0, 0, 255 });
	}

}
