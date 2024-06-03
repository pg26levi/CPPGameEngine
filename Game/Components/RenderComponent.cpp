#include "../Components/RenderComponent.h"
#include "Game/Singletons/RenderEngine.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Singletons/WorldManager.h"
#include <algorithm>


RenderComponent::RenderComponent(std::shared_ptr<Actor> owner, exColor color, int layer, glm::vec3 offset)
	: Component(owner),
	m_Color(color),
	m_Layer(layer)
{
	m_Offset.x = offset.x;
	m_Offset.y = offset.y;
	m_Offset.z = offset.z;

	m_shouldTick = true;

}

void RenderComponent::InitializeComponent()
{
	Component::InitializeComponent();

	RENDER_ENGINE->AddRenderingComponent(shared_from_this());
}

exColor RenderComponent::GetColor() const
{
	return m_Color;
}

void RenderComponent::SetColor(exColor inColor)
{
	m_Color = inColor;
}

void RenderComponent::DrawTriangle(exEngineInterface* engineInterface, Triangle tri, bool filled, const exColor& color, int layer)
{
	// @TODO FILLED
	


	//bool draw = false;
	//for (int i = 0; i < 3; i++)
	//{
	//	if ((tri.v[i].x <= kViewportWidth && tri.v[i].x >= 0) && (tri.v[i].y <= kViewportHeight && tri.v[i].y >= 0))
	//	{
	//		draw = true;
	//		break;
	//	}
	//}

	// Cull check on edges of screens. Don't draw if beyond viewport dimensions + a defined threshold
	for (int i = 0; i < 3; i++) 
	{
		if (tri.v[i].x > kViewportWidth + CullThreshold || tri.v[i].y > kViewportHeight + CullThreshold)
			return;
		else if (tri.v[i].x < 0 - CullThreshold || tri.v[i].y < 0 - CullThreshold)
			return;
	}

#pragma region Rasterizing

	//glm::vec3 distance = WORLD->GetActiveCamera().lock()->GetPosition() - GetOwner()->GetPosition();

	//float dist = glm::length(distance);

	//float rasterCountAlpha = dist / 30.0f;

	//int rasterCount = std::lerp(100, 50, rasterCountAlpha);

	//if (dist > 20.0f)
	//	rasterCount = 20;

	////engineInterface->DrawText(0, exVector2{ 0.0f, 150.0f }, std::to_string(rasterCount).c_str(), exColor{ 255, 255 ,255 ,255 }, 0);

	//for (float i = 0; i < rasterCount; i++) 
	//{
	//	exVector2 start = exVector2{ tri.v[2].x, tri.v[2].y };

	//	exVector2 lerpStart = exVector2{ tri.v[0].x, tri.v[0].y };
	//	exVector2 lerpEnd = exVector2{ tri.v[1].x, tri.v[1].y };

	//	float endX, endY;
	//	endX = std::lerp(lerpStart.x, lerpEnd.x, i / rasterCount);
	//	endY = std::lerp(lerpStart.y, lerpEnd.y, i / rasterCount);

	//	exVector2 end = exVector2{ endX, endY };

	//	engineInterface->DrawLine(start, end, color, layer);

	//}
#pragma endregion


	engineInterface->DrawLine(exVector2{ tri.v[0].x, tri.v[0].y }, exVector2{ tri.v[1].x, tri.v[1].y }, color, layer);
	engineInterface->DrawLine(exVector2{ tri.v[1].x, tri.v[1].y }, exVector2{ tri.v[2].x, tri.v[2].y }, color, layer);
	engineInterface->DrawLine(exVector2{ tri.v[2].x, tri.v[2].y }, exVector2{ tri.v[0].x, tri.v[0].y }, color, layer);
	

	//printf("TRIANGLE\n");
	//printf("LINE 1: (%f, %f), (%f, %f)\n", tri.v[0].x, tri.v[0].y, tri.v[1].x, tri.v[1].y);
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD(0, 0));

}

void RenderComponent::DrawActorName(bool draw)
{
	drawActorName = draw;
}

glm::vec3 RenderComponent::NormalizeCoordinates(const glm::vec4& vert) const
{

	glm::vec3 ndc = glm::vec3(vert);
	// Zero divide check
	if (vert.w != 0.0f) 
	{
		// Normalize from clip space to screen space
		ndc /= vert.w;
	}

	glm::vec3 coords;

	coords.x = (ndc.x + 1.0f) * 0.5f * kViewportWidth;
	coords.y = (1.0f - ndc.y) * 0.5f * kViewportHeight;
	coords.z = ndc.z;

	//printf("TRIANGLE\n");
	//printf("NDC: (%f, %f, %f)\n", ndc.x, ndc.y, ndc.z);
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD(0, 0));

	return coords;
}
