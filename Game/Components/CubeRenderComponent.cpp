#include "CubeRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include <memory>
#include "Game/Actors/Actor.h"

#include "3rdParty/GLM/glm.hpp"

#include "Engine/Public/EngineTypes.h"

#include "Game/Singletons/WorldManager.h"

Mesh* CubeRenderComponent::cubeMesh = nullptr;

CubeRenderComponent::CubeRenderComponent(std::shared_ptr<Actor> owner, exColor color, float scale, glm::vec3 offset)
	: RenderComponent(owner, color, 0, offset),
	matProj(0.0f)
{
	m_Scale = scale;


}

void CubeRenderComponent::Render(exEngineInterface* engineInterface)
{

	fTheta += 1.0f * Time::DeltaTime;

	std::weak_ptr<CameraComponent> cam = WORLD->GetActiveCamera();
	// Return if no active camera
	if (!cam.lock())
		return;

	// TRANSLATION
	glm::mat4 translation = glm::translate(identity, -GetOwner()->FindComponentOfType<TransformComponent>()->GetPosition() + m_Offset);
	// ROTATION
	matRot = glm::rotate(identity, glm::radians((float)glm::sin(fTheta) * 100.0f), glm::vec3(1, 1, 1));
	//rotation = glm::rotate(identity, glm::radians(0.0f), glm::vec3(1, 1, 1));
	// SCALE
	glm::mat4 scale = glm::scale(identity, glm::vec3(1.0f, 1.0f, 1.0f));
	// MODEL
	glm::mat4 model = translation * matRot * scale;
	// VIEW
	glm::mat4 view = glm::lookAt(cam.lock()->GetPosition(), cam.lock()->GetPosition() + cam.lock()->GetForwardVector(), glm::vec3(0, 1, 0));
	// PROJECTION
	matProj = glm::perspective(glm::radians(cam.lock()->GetFov()), (float)kViewportWidth / (float)kViewportHeight, cam.lock()->GetNearPlane(), cam.lock()->GetFarPlane());
	// MVP
	glm::mat4 mvp = matProj * view * model;

	bool shouldDraw = true;

	// Iterate over triangles in mesh
	for (const Triangle& tri : cubeMesh->tris) 
	{
		Triangle projectedTri;

		// Iterate over vertices in triangle
		for (int i = 0; i < 3; i++) 
		{
			glm::vec4 vert = glm::vec4(tri.v[i].x, tri.v[i].y, tri.v[i].z, 1.0f); 

			// Vertex transformation by MVP
			vert = mvp * vert;

			// Transform coordinates from clip-space to device
			glm::vec3 normalizedVert = NormalizeCoordinates(vert);

			// Behind camera cull check
			if (normalizedVert.z < 1.0f)
			{
				shouldDraw = false;
				break;
			}

			projectedTri.v[i] = normalizedVert;

		}

		if(shouldDraw)
			DrawTriangle(engineInterface, projectedTri, false, m_Color, 0);

	}

	if (drawActorName) {

		glm::vec4 textPos = glm::vec4(GetOwner()->GetPosition(), 1.0f);
		textPos.y = -textPos.y;
		textPos.x = -textPos.x;
		textPos = matProj * view * textPos;
		glm::vec3 normalizedTextPos = NormalizeCoordinates(textPos);
		if (normalizedTextPos.z < 1.0f)
		{
			return;
		}
		engineInterface->DrawText(0, exVector2{ normalizedTextPos.x, normalizedTextPos.y}, GetOwner()->GetName().c_str(), exColor{255, 255, 255, 255}, 0);
	}

}

void CubeRenderComponent::InitializeComponent()
{
	RenderComponent::InitializeComponent();

	// Only initialize our cubeMesh once because all cubes are using the same static data for its vertex positions
	if (CubeRenderComponent::cubeMesh == nullptr) 
	{
		CubeRenderComponent::cubeMesh = new Mesh();
		// S
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, -0.5f)
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, -0.5f),
			glm::vec3(0.5f, -0.5f, -0.5f)
			});
		// E
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(0.5f, -0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f)
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(0.5f, -0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.5f, -0.5f, 0.5f)
			});
		// N
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, 0.5f),
			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f)
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, 0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.5f, -0.5f, 0.5f)
			});
		// W
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(-0.5f, 0.5f, 0.5f)
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(-0.5f, -0.5f, 0.5f)
			});
		// TOP
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(-0.5f, 0.5f, 0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f),
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, 0.5f, -0.5f),
			glm::vec3(0.5f, 0.5f, 0.5f),
			glm::vec3(0.5f, 0.5f, -0.5f)
			});
		// BOTTOM
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(-0.5f, -0.5f, 0.5f),
			glm::vec3(0.5f, -0.5f, 0.5f),
			});
		cubeMesh->tris.push_back(Triangle{
			glm::vec3(-0.5f, -0.5f, -0.5f),
			glm::vec3(0.5f, -0.5f, 0.5f),
			glm::vec3(0.5f, -0.5f, -0.5f)
			});

	}


}

