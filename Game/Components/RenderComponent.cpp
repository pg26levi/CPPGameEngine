#include "../Components/RenderComponent.h"
#include "Game/Singletons/RenderEngine.h"
#include "Engine/Public/EngineInterface.h"

RenderComponent::RenderComponent(std::shared_ptr<Actor> owner, exColor color, int layer, exVector2 offset)
	: Component(owner),
	m_Color(color),
	m_Layer(layer)
{
	m_Offset.x = offset.x;
	m_Offset.y = offset.y;


}

void RenderComponent::InitializeComponent()
{
	Component::InitializeComponent();

	RENDER_ENGINE->AddRenderingComponent(shared_from_this());
}

exColor RenderComponent::GetColor() const
{
	return m_Color;
}

void RenderComponent::SetColor(exColor inColor)
{
	m_Color = inColor;
}

void RenderComponent::DrawTriangle(exEngineInterface* engineInterface, Triangle tri, bool filled, const exColor& color, int layer)
{
	if (!filled) 
	{
		engineInterface->DrawLine(exVector2{ tri.v[0].x, tri.v[0].y }, exVector2{ tri.v[1].x, tri.v[1].y }, color, layer);
		engineInterface->DrawLine(exVector2{ tri.v[1].x, tri.v[1].y }, exVector2{ tri.v[2].x, tri.v[2].y }, color, layer);
		engineInterface->DrawLine(exVector2{ tri.v[2].x, tri.v[2].y }, exVector2{ tri.v[0].x, tri.v[0].y }, color, layer);
	}
	else 
	{
		engineInterface->DrawLine(exVector2{ tri.v[0].x, tri.v[0].y }, exVector2{ tri.v[1].x, tri.v[1].y }, color, layer);
		engineInterface->DrawLine(exVector2{ tri.v[1].x, tri.v[1].y }, exVector2{ tri.v[2].x, tri.v[2].y }, color, layer);
		engineInterface->DrawLine(exVector2{ tri.v[2].x, tri.v[2].y }, exVector2{ tri.v[0].x, tri.v[0].y }, color, layer);
	}
}







