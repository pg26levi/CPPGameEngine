#include "CameraComponent.h"
#include "Game/Actors/Actor.h"


CameraComponent::CameraComponent(std::shared_ptr<Actor> owner, float inFov, float nearPlane, float farPlane)
	: Component(owner),
	m_Fov(inFov),
	m_nearPlane(nearPlane),
	m_farPlane(farPlane),
	m_Offset(0.0f),
	m_ForwardVector(0.0f, 0.0f, -1.0f),
	m_Rotation(0.0f, -90.0f, 0.0f)
{


}

glm::vec3 CameraComponent::GetPosition() const
{
	return GetOwner()->GetPosition() + m_Offset;
}

void CameraComponent::InitializeComponent()
{
}

void CameraComponent::TickComponent(float deltaSeconds)
{
	CalculateForwardVector();
}

void CameraComponent::CalculateForwardVector()
{
	m_Rotation = GetOwner()->GetRotation();

	if (m_Rotation.y > 360 || m_Rotation.y < -360)
		m_Rotation.y = 0;

	if (m_Rotation.x > 89.0f)
		m_Rotation.x = 89.0f;
	if (m_Rotation.x < -89.0f)
		m_Rotation.x = -89.0f;

	glm::vec3 direction;

	direction.x = cos(glm::radians(m_Rotation.y)) * cos(glm::radians(m_Rotation.x));
	direction.y = sin(glm::radians(m_Rotation.x));
	direction.z = sin(glm::radians(m_Rotation.y)) * cos(glm::radians(m_Rotation.x));

	m_ForwardVector = glm::normalize(direction);

}
