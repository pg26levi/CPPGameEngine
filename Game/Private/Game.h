//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game/GameCore/Utils.h"
#include "Game/GameCore/ActorTypes.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

	virtual void Render();
	virtual void Physics();

	virtual void InitConsole();

	virtual void TestFire();

private:

	exEngineInterface*			mEngine;

	int							mFontID;
	// @TODO BITFIELD INPUT HANDLER
	bool						mRight;
	bool						mLeft;
	bool						mForward;
	bool						mBackwards;
	bool						mUp;
	bool						mDown;

	bool						mRotateRight;
	bool						mRotateLeft;
	bool						mRotateUp;
	bool						mRotateDown;

	bool						mFire;

	bool						canRender = true;
	bool						canPhysics = true;

	exVector2					mTextPosition;

	std::shared_ptr<Actor>		player;

	std::shared_ptr<Actor>		GameDesignersHead;

	std::shared_ptr<Football>	Steph;
	std::shared_ptr<Actor>		Henry;

	std::shared_ptr<Actor>		myBox;

	std::shared_ptr<HockeyStick> hockeyStick;

	std::shared_ptr<Actor>		myCube;
	std::shared_ptr<Actor>		myCube2;
	std::shared_ptr<Actor>		myCube3;


	std::thread* RenderThread = nullptr;
	std::thread* PhysicsThread = nullptr;

	glm::vec3 playerPos;
	glm::vec3 playerRot;

	int prevFrameTime = 0;

};
