#include "CubeRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include <memory>
#include "Game/Actors/Actor.h"

#include "3rdParty/GLM/glm.hpp"

#include "Engine/Public/EngineTypes.h"

#include "Game/Singletons/WorldManager.h"

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
	glm::mat4 rotation = glm::rotate(identity, glm::radians((float)glm::sin(fTheta) * 100.0f), glm::vec3(1, 1, 1));
	//rotation = glm::rotate(identity, glm::radians(0.0f), glm::vec3(1, 1, 1));
	// SCALE
	glm::mat4 scale = glm::scale(identity, glm::vec3(1.0f, 1.0f, 1.0f));
	// MODEL
	glm::mat4 model = translation * rotation * scale;
	// VIEW
	glm::mat4 view = glm::lookAt(cam.lock()->GetPosition(), cam.lock()->GetPosition() + cam.lock()->GetForwardVector(), glm::vec3(0, 1, 0));
	// PROJECTION
	matProj = glm::perspective(glm::radians(cam.lock()->GetFov()), (float)kViewportWidth / (float)kViewportHeight, cam.lock()->GetNearPlane(), cam.lock()->GetFarPlane());
	// MVP
	glm::mat4 mvp = matProj * view * model;

	bool firstFace = false;

	// Iterate over triangles in mesh
	for (const Triangle& tri : cubeMesh.tris) 
	{
		Triangle newTri;
		int currentVert = 0;

		// Iterate over vertices in triangle
		for (const glm::vec3& vec : tri.v) 
		{

			glm::vec4 vert = glm::vec4(vec.x, vec.y, vec.z, 1.0f);

			vert.x = -vert.x;
			vert.y = -vert.y;

			vert = mvp * vert;
			// Transform coordinates from clip-space to device
			glm::vec3 normalizedVert = NormalizeCoordinates(vert);

			newTri.v[currentVert] = normalizedVert;

			//engineInterface->DrawText(0, exVector2{ newTri.v[currentVert].x, newTri.v[currentVert].y }, "Sigma", exColor{ 255, 0, 0, 255 }, 0);
			//if(firstFace)
			//	engineInterface->DrawText(0, exVector2{ newTri.v[currentVert].x, newTri.v[currentVert].y }, std::to_string(currentVert).c_str(), exColor{255, 0, 0, 255}, 0);
			//else 
			//	engineInterface->DrawText(0, exVector2{ newTri.v[currentVert].x, newTri.v[currentVert].y - 20 }, std::to_string(currentVert).c_str(), exColor{ 0, 255, 0, 255 }, 0);

			currentVert++;

		}

		DrawTriangle(engineInterface, newTri, false, m_Color, 0);

		firstFace = !firstFace;

	}


}

void CubeRenderComponent::InitializeComponent()
{
	RenderComponent::InitializeComponent();
	// S
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, 0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, -0.5f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f)
		});
	// E
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, -0.5f, 0.5f)
		});
	// N
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, 0.5f),
		glm::vec3(-0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, -0.5f, 0.5f)
		});
	// W
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, 0.5f, -0.5f),
		glm::vec3(-0.5f, 0.5f, 0.5f)
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, 0.5f, 0.5f),
		glm::vec3(-0.5f, -0.5f, 0.5f)
		});
	// TOP
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, 0.5f, -0.5f),
		glm::vec3(-0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, 0.5f, -0.5f),
		glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3(0.5f, 0.5f, -0.5f)
		});
	// BOTTOM
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(-0.5f, -0.5f, 0.5f),
		glm::vec3(0.5f, -0.5f, 0.5f),
		});
	cubeMesh.tris.push_back(Triangle{
		glm::vec3(-0.5f, -0.5f, -0.5f),
		glm::vec3(0.5f, -0.5f, 0.5f),
		glm::vec3(0.5f, -0.5f, -0.5f)
		});


}

