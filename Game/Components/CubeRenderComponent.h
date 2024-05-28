#pragma once
#include "RenderComponent.h"
class CubeRenderComponent : public RenderComponent
{

public:

	CubeRenderComponent() = delete;

	CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, exVector2 offset = exVector2{ 0.0f, 0.0f });

	virtual void Render(exEngineInterface* engineInterface) override;

	virtual void InitializeComponent() override;


private:

	Mesh cubeMesh;
	Matrix4 matProj;
	Matrix4 matRotZ;
	Matrix4 matRotX;

	float fTheta = 0.0f;
};

