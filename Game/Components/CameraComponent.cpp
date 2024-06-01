#include "CameraComponent.h"
#include "Game/Actors/Actor.h"


CameraComponent::CameraComponent(std::shared_ptr<Actor> owner, float inFov, float nearPlane, float farPlane)
	: Component(owner),
	m_Fov(inFov),
	m_nearPlane(nearPlane),
	m_farPlane(farPlane),
	m_Offset(0.0f),
	m_ForwardVector(0.0f, 0.0f, -1.0f)
{


}

glm::vec3 CameraComponent::GetPosition() const
{
	return GetOwner()->GetPosition() + m_Offset;
}
