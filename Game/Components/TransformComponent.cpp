#include "../Components/TransformComponent.h"

TransformComponent::TransformComponent(std::shared_ptr<Actor> owner, exVector2 loc)
    :   Component(owner), 
        m_Location(loc)
{

}

exVector2 TransformComponent::GetPosition() const
{
    return m_Location;
}

void TransformComponent::SetPosition(const exVector2 inValue)
{
    m_Location = inValue;
}
