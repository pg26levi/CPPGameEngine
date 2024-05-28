#include "WorldManager.h"

WorldManager* WorldManager::sInstance = nullptr;

WorldManager* WorldManager::GetInstance()
{
	if (!sInstance) 
	{
		sInstance = new WorldManager();
	}
	return sInstance;
}

WorldManager::WorldManager()
{

}
