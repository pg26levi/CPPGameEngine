#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class TransformComponent : public Component
{
public:

	TransformComponent() = delete;
	TransformComponent(std::shared_ptr<Actor> owner, glm::vec3 loc);

	glm::vec3 GetPosition() const;
	glm::vec3 GetRotation() const;

	void SetPosition(const glm::vec3& inValue);
	void SetRotation(const glm::vec3& inValue);

private:

	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;
	glm::vec3 m_Position;

};

