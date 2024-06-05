#pragma once
#include "Game/GameCore/Utils.h"
#include "Game/Actors/Player.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"

#define INPUT_MANAGER InputManager::GetInstance()

typedef void(Player::* InputDelegate)();

class InputManager
{

private:

	static std::shared_ptr<InputManager> sInstance;
	// Map for corelating keyboard characters to function calls
	std::map<SDL_Scancode, InputDelegate> inputBindingMap;

	std::weak_ptr<Player> m_BoundPlayer;

public:

	static std::shared_ptr<InputManager> GetInstance();
	static void DestroyInstance();

	void Update();

	void BindInput(SDL_Scancode scanCode, std::shared_ptr<Player> player, InputDelegate func);

	InputManager();
	~InputManager();
};

