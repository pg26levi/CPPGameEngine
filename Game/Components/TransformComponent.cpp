#include "../Components/TransformComponent.h"

TransformComponent::TransformComponent(std::shared_ptr<Actor> owner, Vector3 loc)
    :   Component(owner), 
        m_Position(loc)
{

}

Vector3 TransformComponent::GetPosition() const
{
    return m_Position;
}

void TransformComponent::SetPosition(const Vector3 inValue)
{
    m_Position = inValue;
}
