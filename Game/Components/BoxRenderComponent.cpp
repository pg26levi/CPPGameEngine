#include "BoxRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Actors/Actor.h"
#include "Game/Components/TransformComponent.h"

BoxRenderComponent::BoxRenderComponent(std::shared_ptr<Actor> owner, exColor color, float width, float height, int layer, exVector2 offset)
	: RenderComponent(owner, color, layer, offset),
	m_Width(width),
	m_height(height)
{


}

void BoxRenderComponent::Render(exEngineInterface* engineInterface)
{
	std::shared_ptr<TransformComponent> transformComp = m_Owner->FindComponentOfType<TransformComponent>();

	if (!transformComp)
	{
		return;
	}
	exVector2 centerPosition = transformComp->GetPosition();

	centerPosition += m_Offset;

	exVector2 topLeft = centerPosition + exVector2{m_Width * -1, m_height };
	exVector2 bottomRight = centerPosition + exVector2{m_Width, m_height * -1};

	// TODO: Add suport for layering in render component
	engineInterface->DrawBox(topLeft, bottomRight, m_Color, m_Layer);

	// Outline
	engineInterface->DrawBox({topLeft.x - 5, topLeft.y + 5}, {bottomRight.x + 5, bottomRight.y - 5}, {0, 255, 0, 255}, m_Layer + 1);


}
