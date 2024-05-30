#include "CubeRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include <memory>
#include "Game/Actors/Actor.h"

CubeRenderComponent::CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, Vector3 offset)
	: RenderComponent(owner, color, 0, offset)
{
	m_Scale = scale;

}

void CubeRenderComponent::Render(exEngineInterface* engineInterface)
{

	fTheta += 1.0f * Time::DeltaTime;
	// Temp rotation stuff
	matRotZ.m[0][0] = cosf(fTheta);
	matRotZ.m[0][1] = sinf(fTheta);
	matRotZ.m[1][0] = -sinf(fTheta);
	matRotZ.m[1][1] = cosf(fTheta);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(fTheta * 0.5f);
	matRotX.m[1][2] = sinf(fTheta * 0.5f);
	matRotX.m[2][1] = -sinf(fTheta * 0.5f);
	matRotX.m[2][2] = cosf(fTheta * 0.5f);
	matRotX.m[3][3] = 1;


	matRot = matRotZ * matRotX;

	matMVP = matRot * matProj;

	for (const Triangle& tri : cubeMesh.tris) 
	{

		// rotation stuff

		Triangle triRotated = tri;

		triRotated.v[0] *= matRot;
		triRotated.v[1] *= matRot;
		triRotated.v[2] *= matRot;

		//

		Triangle triTranslated = triRotated;

		Vector3 ownerPos = GetOwner()->FindComponentOfType<TransformComponent>()->GetPosition();

		triTranslated.v[0] += ownerPos;
		triTranslated.v[1] += ownerPos;
		triTranslated.v[2] += ownerPos;

		Triangle triProjected = triTranslated;

		triProjected.v[0] *= matProj;
		triProjected.v[1] *= matProj;
		triProjected.v[2] *= matProj;

		triProjected.v[0].x += 1.0f; triProjected.v[0].y += 1.0f;
		triProjected.v[1].x += 1.0f; triProjected.v[1].y += 1.0f;
		triProjected.v[2].x += 1.0f; triProjected.v[2].y += 1.0f;

		triProjected.v[0].x *= 0.5f * (float)kViewportWidth;
		triProjected.v[0].y *= 0.5f * (float)kViewportHeight;
		triProjected.v[1].x *= 0.5f * (float)kViewportWidth;
		triProjected.v[1].y *= 0.5f * (float)kViewportHeight;
		triProjected.v[2].x *= 0.5f * (float)kViewportWidth;
		triProjected.v[2].y *= 0.5f * (float)kViewportHeight;


		DrawTriangle(engineInterface, triProjected, false, m_Color, 0);

	}

}

void CubeRenderComponent::InitializeComponent()
{
	RenderComponent::InitializeComponent();

	cubeMesh.tris =
	{
		// S
		{0.0f, 0.0f, 0.0f,		0.0f, 1.0f, 0.0f,		1.0f, 1.0f, 0.0f },
		{0.0f, 0.0f, 0.0f,		1.0f, 1.0f, 0.0f,		1.0f, 0.0f, 0.0f },
		// E
		{1.0f, 0.0f, 0.0f,		1.0f, 1.0f, 0.0f,		1.0f, 1.0f, 1.0f },
		{1.0f, 0.0f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f, 1.0f },
		// N
		{1.0f, 0.0f, 1.0f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, 1.0f },
		{1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 1.0f,		0.0f, 0.0f, 1.0f },
		// W
		{0.0f, 0.0f, 1.0f,		0.0f, 1.0f, 1.0f,		0.0f, 1.0f, 0.0f },
		{1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,		0.0f, 0.0f, 0.0f },
		// TOP
		{0.0f, 1.0f, 0.0f,		0.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f },
		{0.0f, 1.0f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, 0.0f },
		// BOTTOM
		{1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, 0.0f },
		{1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f, 0.0f },

	};

	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = (float)kViewportHeight / (float)kViewportWidth;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * PI);

	matProj.m[0][0] = fAspectRatio * fFovRad;
	matProj.m[1][1] = fFovRad;
	matProj.m[2][2] = fFar / (fFar - fNear);
	matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	matProj.m[2][3] = 1.0f;
	matProj.m[3][3] = 0.0f;

}

