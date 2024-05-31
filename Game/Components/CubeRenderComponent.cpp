#include "CubeRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include <memory>
#include "Game/Actors/Actor.h"

#include "3rdParty/GLM/glm.hpp"

#include "Engine/Public/EngineTypes.h"

CubeRenderComponent::CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, glm::vec3 offset)
	: RenderComponent(owner, color, 0, offset)
{
	m_Scale = scale;


}

void CubeRenderComponent::Render(exEngineInterface* engineInterface)
{

	fTheta += 1.0f * Time::DeltaTime;
	// Temp rotation stuff
	matRotZ[0][0] = cosf(fTheta);
	matRotZ[0][1] = sinf(fTheta);
	matRotZ[1][0] = -sinf(fTheta);
	matRotZ[1][1] = cosf(fTheta);
	matRotZ[2][2] = 1;
	matRotZ[3][3] = 1;

	matRotX[0][0] = 1;
	matRotX[1][1] = cosf(fTheta * 0.5f);
	matRotX[1][2] = sinf(fTheta * 0.5f);
	matRotX[2][1] = -sinf(fTheta * 0.5f);
	matRotX[2][2] = cosf(fTheta * 0.5f);
	matRotX[3][3] = 1;

	matRot = matRotZ * matRotX;

	for (const Triangle& tri : cubeMesh.tris) 
	{

		glm::vec4 vert1 = glm::vec4(tri.v[0].x, tri.v[0].y, tri.v[0].z, 1.0f);
		glm::vec4 vert2 = glm::vec4(tri.v[1].x, tri.v[1].y, tri.v[1].z, 1.0f);
		glm::vec4 vert3 = glm::vec4(tri.v[2].x, tri.v[2].y, tri.v[2].z, 1.0f);

		//rotation stuff


		//vert1 *= matRot;
		//vert2 *= matRot;
		//vert3 *= matRot;

		glm::vec4 translatedvert1 = vert1 * matProj * matRot;
		glm::vec4 translatedvert2 = vert2 * matProj * matRot;
		glm::vec4 translatedvert3 = vert3 * matProj * matRot;

		Triangle newTri = Triangle{ glm::vec3(translatedvert1.x,translatedvert1.y,translatedvert1.z),
		glm::vec3(translatedvert2.x,translatedvert2.y,translatedvert2.z) ,
		glm::vec3(translatedvert3.x,translatedvert3.y,translatedvert3.z) };
		//

		//Triangle triTranslated = triRotated;

		//glm::vec3 ownerPos = GetOwner()->FindComponentOfType<TransformComponent>()->GetPosition();

		//triTranslated.v[0] += ownerPos;
		//triTranslated.v[1] += ownerPos;
		//triTranslated.v[2] += ownerPos;

		Triangle triProjected = newTri;

		//triProjected.v[0] *= matProj;
		//triProjected.v[1] *= matProj;
		//triProjected.v[2] *= matProj;

		//triProjected.v[0].x += 1.0f; triProjected.v[0].y += 1.0f;
		//triProjected.v[1].x += 1.0f; triProjected.v[1].y += 1.0f;
		//triProjected.v[2].x += 1.0f; triProjected.v[2].y += 1.0f;

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

	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 0.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f)
		});
	// E
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 1.0f)
		});
	// N
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 1.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
		});
	// W
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
		});
	// TOP
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 0.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 0.0f)
		});
	// BOTTOM
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(1.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f)
		});


	//float fNear = 0.1f;
	//float fFar = 1000.0f;
	//float fFov = 90.0f;
	//float fAspectRatio = (float)kViewportHeight / (float)kViewportWidth;
	//float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * PI);

	//matProj[0][0] = fAspectRatio * fFovRad;
	//matProj[1][1] = fFovRad;
	//matProj[2][2] = fFar / (fFar - fNear);
	//matProj[3][2] = (-fFar * fNear) / (fFar - fNear);
	//matProj[2][3] = 1.0f;
	//matProj[3][3] = 0.0f;

	matProj = glm::perspective(glm::radians(45.0f), (float)kViewportWidth / (float)kViewportHeight, 0.1f, 1000.0f);
}

