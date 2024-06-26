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

private:

	exEngineInterface*			mEngine;

	int							mFontID;

	bool						mUp;
	bool						mDown;

	exVector2					mTextPosition;

	std::shared_ptr<Actor>		GameDesignersHead;

	std::shared_ptr<Football>	Steph;
	std::shared_ptr<Actor>		Henry;

	std::shared_ptr<Actor>		myBox;

	std::shared_ptr<HockeyStick> hockeyStick;

};
