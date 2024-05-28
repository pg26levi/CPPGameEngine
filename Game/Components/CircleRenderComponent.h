#pragma once
#include "Game/Components/RenderComponent.h"
class CircleRenderComponent : public RenderComponent
{


public:

	CircleRenderComponent() = delete;
	CircleRenderComponent(std::shared_ptr<Actor> owner, exColor color, float radius, int layer);

	virtual void Render(exEngineInterface* engineInterface) override;

	void SetColor(exColor inColor);
	exColor GetColor() const;


private:

	float m_Radius;



};

