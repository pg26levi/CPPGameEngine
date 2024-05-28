#pragma once
#include "RenderComponent.h"
class CubeRenderComponent : public RenderComponent
{

public:

	CubeRenderComponent() = delete;

	CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, Vector3 offset = Vector3{ 0.0f, 0.0f, 0.0f });

	virtual void Render(exEngineInterface* engineInterface) override;

	virtual void InitializeComponent() override;


private:

	Mesh cubeMesh;
	Matrix4 matProj;
	Matrix4 matRotZ;
	Matrix4 matRotX;

	Matrix4 matRot;

	Matrix4 matMVP;

	float fTheta = 0.0f;
};

