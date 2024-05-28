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
    RenderComponent(std::shared_ptr<Actor> owner, exColor color, int layer, exVector2 offset = exVector2{0.0f, 0.0f});

    virtual void InitializeComponent() override;


    exColor GetColor() const;
    void SetColor(exColor inColor);

protected:
    exColor m_Color;
    int m_Layer;

    exVector2 m_Offset;

    virtual void Render(exEngineInterface* engineInterface) = 0;
};

