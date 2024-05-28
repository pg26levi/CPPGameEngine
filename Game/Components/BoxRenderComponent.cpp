#include "BoxRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Actors/Actor.h"
#include "Game/Components/TransformComponent.h"

BoxRenderComponent::BoxRenderComponent(std::shared_ptr<Actor> owner, exColor color, float width, float height, int layer, Vector3 offset)
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
	Vector3 centerPosition = transformComp->GetPosition();

	centerPosition += m_Offset;

	Vector3 topLeft = centerPosition + Vector3{m_Width * -1, m_height, 0.0f};
	Vector3 bottomRight = centerPosition + Vector3{m_Width, m_height * -1, 0.0f};

	// TODO: Add suport for layering in render component
	engineInterface->DrawBox(exVector2{ topLeft.x, topLeft.y }, exVector2{ bottomRight.x, bottomRight.y }, m_Color, m_Layer);

	// Outline
	engineInterface->DrawBox({topLeft.x - 5, topLeft.y + 5}, {bottomRight.x + 5, bottomRight.y - 5}, {0, 255, 0, 255}, m_Layer + 1);

}
