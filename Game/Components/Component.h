#pragma once
#include "Game/GameCore/Utils.h"

class Actor;

class Component 
{

public:

	Component() = delete;
	Component(std::shared_ptr<Actor> owner);
	virtual ~Component();

	// game functions
	virtual void InitializeComponent();
	virtual void TickComponent(float deltaSeconds);
	bool ShouldTick() const { return m_shouldTick; }
	void SetShouldTick(bool tick) { m_shouldTick = tick; };

	std::shared_ptr<Actor> GetOwner() const { return m_Owner; }


protected:

	std::shared_ptr<Actor> m_Owner;

	bool m_shouldTick = false;


};

typedef std::list<std::shared_ptr<Component>> ComponentList;

