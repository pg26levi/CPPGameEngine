#include "CircleRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Actors/Actor.h"
#include "Game/Components/TransformComponent.h"

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<Actor> owner, exColor color, float radius, int layer)
	: RenderComponent(owner, color, layer),
	m_Radius(radius)
{
}

void CircleRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp =  m_Owner->FindComponentOfType<TransformComponent>();

	if (!transformComp) 
	{
		return;
	}
	const exVector2 centerPosition = transformComp->GetPosition();
	// TODO: Add suport for layering in render component
	engineInterface->DrawCircle(centerPosition, m_Radius, m_Color, m_Layer);
}

void CircleRenderComponent::SetColor(exColor inColor)
{
}

exColor CircleRenderComponent::GetColor() const
{
	return m_Color;
}
