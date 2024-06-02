#include "Player.h"

void Player::BeginPlay()
{
}

void Player::InitializeActor(const glm::vec3 spawnPosition)
{
	Actor::InitializeActor(spawnPosition);
	m_Camera = AddComponentOfType<CameraComponent>(90.0f, 0.1f, 1000.0f);

}

void Player::Tick(float deltaSeconds)
{
	Actor::Tick(deltaSeconds);
}
