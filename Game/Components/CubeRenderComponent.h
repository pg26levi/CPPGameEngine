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

	static Mesh* cubeMesh;
	glm::mat4 matProj;

	glm::mat4 matRot;

	glm::mat4 identity = glm::mat4(1.0f);

	//Matrix4 matMVP;

	float fTheta = 0.0f;

};

