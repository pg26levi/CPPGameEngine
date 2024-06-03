#pragma once
#include "Game/GameCore/Utils.h"
#include "Game/Actors/Player.h"

#define INPUT_MANAGER InputManager::GetInstance()

typedef void(Player::* InputDelegate)();

class InputManager
{

private:


	static std::shared_ptr<InputManager> sInstance;
	// Map for corellating keyboard characters to function calls
	std::map<char, InputDelegate> inputBindingMap;

	std::weak_ptr<Player> m_BoundPlayer;

public:

	static std::shared_ptr<InputManager> GetInstance();
	static void DestroyInstance();

	void Update();

	void BindInput(char key, std::shared_ptr<Player> player, InputDelegate func);

	InputManager();
	~InputManager();
};

