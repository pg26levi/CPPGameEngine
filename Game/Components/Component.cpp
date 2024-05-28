#include "Component.h"

Component::Component(std::shared_ptr<Actor> owner) 
	: m_Owner(owner)
{

}

Component::~Component()
{
}

void Component::InitializeComponent()
{
}

void Component::TickComponent(float deltaSeconds)
{
}
