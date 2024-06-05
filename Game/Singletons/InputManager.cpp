#include "InputManager.h"

std::shared_ptr<InputManager> InputManager::sInstance = nullptr;

InputManager::InputManager() 
{

}

InputManager::~InputManager()
{

}

std::shared_ptr<InputManager> InputManager::GetInstance()
{
	if (!sInstance) {
		sInstance = std::make_shared<InputManager>();
	}

	return sInstance;
}

void InputManager::DestroyInstance()
{

}

void InputManager::Update()
{

}

void InputManager::BindInput(SDL_Scancode scanCode, std::shared_ptr<Player> player, InputDelegate func)
{
	inputBindingMap[scanCode] = func;

	m_BoundPlayer = player;
}
