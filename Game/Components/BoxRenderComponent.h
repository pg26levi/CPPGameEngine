#pragma once
#include "RenderComponent.h"
class BoxRenderComponent :	public RenderComponent
{

public:
	BoxRenderComponent() = delete;
	BoxRenderComponent(std::shared_ptr<Actor> owner, exColor color, float width, float height, int layer, Vector3 offset = Vector3{0.0f, 0.0f, 0.0f});

	virtual void Render(exEngineInterface* engineInterface) override;

private:

	float m_Width;
	float m_height;

};

