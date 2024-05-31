#pragma once
#include "RenderComponent.h"
#include "3rdParty/GLM/glm.hpp"

class CubeRenderComponent : public RenderComponent
{

public:

	CubeRenderComponent() = delete;

	CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, glm::vec3 offset = glm::vec3{ 0.0f, 0.0f, 0.0f });

	virtual void Render(exEngineInterface* engineInterface) override;

	virtual void InitializeComponent() override;


private:

	Mesh cubeMesh;
	//Matrix4 matProj;
	glm::mat4 matRotZ;
	glm::mat4 matRotX;
	glm::mat4 matProj;

	glm::mat4 matRot;

	//Matrix4 matMVP;

	float fTheta = 0.0f;




};

