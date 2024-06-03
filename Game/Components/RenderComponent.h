#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class exEngineInterface;

class RenderComponent : public Component, 
                        public std::enable_shared_from_this<RenderComponent>
{
    friend class RenderEngine;
public:

    RenderComponent() = delete;
    RenderComponent(std::shared_ptr<Actor> owner, exColor color, int layer, glm::vec3 offset = glm::vec3(0.0f));

    virtual void InitializeComponent() override;

    exColor GetColor() const;
    void SetColor(exColor inColor);

    void DrawActorName(bool draw);

protected:
    exColor m_Color;
    int m_Layer;

    glm::vec3 m_Offset;

    float m_Scale;

    virtual void Render(exEngineInterface* engineInterface) = 0;

    void DrawTriangle(exEngineInterface* engineInterface, Triangle tri, bool filled, const exColor& color, int layer = 0);

    glm::vec3 NormalizeCoordinates(const glm::vec4& vert) const;

    // Threshold for culling triangles outside NDC range (-1) - (1)
    // @TODO SCALE THIS ON A PER OBJECT BASIS BASED ON DISTANCE FROM CAMERA
    // Value can be low for far away entities, needs to be higher when closer up as the vertices stick further off screen due to perspective
    const int CullThreshold = 2250;

    bool drawActorName = false;

};

