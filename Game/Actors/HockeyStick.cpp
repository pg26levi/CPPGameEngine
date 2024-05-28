#include "HockeyStick.h"
#include "Game/Singletons/WorldManager.h"

HockeyStick::HockeyStick(exColor color) : mStickColor(color)
{
}

void HockeyStick::BeginPlay()
{
}

void HockeyStick::InitializeActor(const Vector3 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);

	AddComponentOfType<BoxRenderComponent>(mStickColor, 1.0f, 100.0f, 0);

	AddComponentOfType<BoxRenderComponent>(mStickColor, 20.0f, 1.0f, 0, Vector3{ -30.0f, 100.0f });

	//exVector2 newPos = mTransformComponent->GetPosition();
	//newPos.x -= 30.0f;
	//newPos.y += 100.0f;

	//stickBottom = WORLD->SpawnActorOfClass<Actor>(newPos);
	//stickBottom->AddComponentOfType<BoxRenderComponent>(mStickColor, 20.0f, 1.0f, 0);

}
