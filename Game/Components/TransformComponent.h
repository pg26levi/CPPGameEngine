#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class TransformComponent : public Component
{
public:

	TransformComponent() = delete;
	TransformComponent(std::shared_ptr<Actor> owner, Vector3 loc);

	Vector3 GetPosition() const;
	void SetPosition(const Vector3 inValue);

private:

	Vector3 m_Rotation;
	Vector3 m_Scale;
	Vector3 m_Position;

};

