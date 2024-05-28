#include "../Components/RenderComponent.h"
#include "Game/Singletons/RenderEngine.h"

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
