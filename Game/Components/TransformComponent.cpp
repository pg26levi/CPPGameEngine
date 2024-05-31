#include "../Components/TransformComponent.h"

TransformComponent::TransformComponent(std::shared_ptr<Actor> owner, glm::vec3 loc)
    :   Component(owner), 
        m_Position(loc)
{

}

glm::vec3 TransformComponent::GetPosition() const
{
    return m_Position;
}

void TransformComponent::SetPosition(const glm::vec3 inValue)
{
    m_Position = inValue;
}
