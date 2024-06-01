#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class CameraComponent : public Component
{

public:

	CameraComponent() = delete;
	CameraComponent(std::shared_ptr<Actor> owner, float inFov, float nearPlane, float farPlane);

	void SetFov(float inFov) { m_Fov = inFov; }
	void SetNearPlane(float inPlane) { m_nearPlane = inPlane; }
	void SetFarPlane(float inPlane) { m_farPlane = inPlane; }

	float GetFov() const { return m_Fov; }
	float GetFarPlane() const { return m_farPlane; }
	float GetNearPlane() const { return m_nearPlane; }

	glm::vec3 GetPosition() const;
	glm::vec3 GetForwardVector() const { return m_ForwardVector; }

private:

	float m_Fov;
	float m_nearPlane;
	float m_farPlane;

	glm::vec3 m_Offset;
	glm::vec3 m_ForwardVector;

};

