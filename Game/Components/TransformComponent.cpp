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

glm::vec3 TransformComponent::GetRotation() const
{
    return m_Rotation;
}

void TransformComponent::SetRotation(const glm::vec3& inValue)
{
    m_Rotation = inValue;
}

void TransformComponent::SetPosition(const glm::vec3& inValue)
{
    m_Position = inValue;
}
