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
    RenderComponent(std::shared_ptr<Actor> owner, exColor color, int layer, glm::vec3 offset = glm::vec3{ 0.0f });

    virtual void InitializeComponent() override;

    exColor GetColor() const;
    void SetColor(exColor inColor);

protected:
    exColor m_Color;
    int m_Layer;

    glm::vec3 m_Offset;

    float m_Scale;

    virtual void Render(exEngineInterface* engineInterface) = 0;

    void DrawTriangle(exEngineInterface* engineInterface, Triangle tri, bool filled, const exColor& color, int layer = 0);

};

