#pragma once
#include "Game/GameCore/ComponentTypes.h"
#include <type_traits>

class Actor : public std::enable_shared_from_this<Actor>
{

private:

	template<std::derived_from<Actor> ActorType, typename ...Args>
	static std::shared_ptr<ActorType> MakeActor(Args... arguments) 
	{
		return std::move(std::make_shared<ActorType>(arguments...));
	}

protected:

	friend class WorldManager;
	ComponentList m_Components;

public:

	Actor();
	~Actor();

	virtual void BeginPlay();
	virtual void EndPlay();
	virtual void Tick(float deltaSeconds);

	virtual void InitializeActor(const Vector3 spawnPosition);

	// Variadic Arguments
	template<std::derived_from<Component> ComponentType, typename ...Args>
	std::shared_ptr<ComponentType> AddComponentOfType(Args... arguments)
	{
		std::shared_ptr<ComponentType> newComponent = std::make_shared<ComponentType>(shared_from_this(), arguments...);
		m_Components.push_back(newComponent);
		newComponent->InitializeComponent();

		return newComponent;
	}

	template<std::derived_from<Component> ComponentType>
	std::shared_ptr<ComponentType> FindComponentOfType()
	{
		for (std::shared_ptr<Component> component : m_Components) {

			if (std::shared_ptr<ComponentType> foundComponent = std::dynamic_pointer_cast<ComponentType>(component)) 
			{
				return foundComponent;
			}

		}
		return nullptr;
	}

protected:

	std::shared_ptr<TransformComponent> mTransformComponent;

};

