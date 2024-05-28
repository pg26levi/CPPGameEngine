#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class TransformComponent : public Component
{
public:

	TransformComponent() = delete;
	TransformComponent(std::shared_ptr<Actor> owner, exVector2 loc);

	exVector2 GetPosition() const;
	void SetPosition(const exVector2 inValue);

private:
	
	exVector2 m_Location;

};

