//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Game/Gamecore/ActorTypes.h"
#include "Game/GameCore/ComponentTypes.h"
#include "Game/Singletons/RenderEngine.h"
#include "Game/Singletons/PhysicsEngine.h"
#include "Game/Singletons/WorldManager.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "W Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "Build/Kanit-Regular.ttf", 32 );

	mTextPosition.x = 50.0f;
	mTextPosition.y = 50.0f;

	GameDesignersHead = WORLD->SpawnActorOfClass<Football>(exVector2{ 500.0f, 500.0f }, exColor{ 255, 255, 0, 255 }, 30.0f);

	Steph = WORLD->SpawnActorOfClass<Football>(exVector2{ 700.0f, 400.0f }, exColor{ 155, 255, 0, 255 }, 10.0f);
	//Steph->AddComponentOfType<CircleRenderComponent>(exColor{ 155, 255, 0, 255 }, 10.0f, 0);
	//Steph->AddComponentOfType<CircleColliderPhysicsComponent>(10.0f, exVector2{ -1.0f, 0.0f });

	Henry = WORLD->SpawnActorOfClass<Actor>(exVector2{ 200.0f, 400.0f });
	Henry->AddComponentOfType<CircleRenderComponent>(exColor{ 0, 0, 0, 255 }, 30.0f, 0);
	Henry->AddComponentOfType<CircleColliderPhysicsComponent>(30.0f, exVector2{ 1.0f, 0.0f });
	
	myBox = WORLD->SpawnActorOfClass<Actor>(exVector2{ 400.0f, 300.0f });
	myBox->AddComponentOfType<BoxRenderComponent>(exColor{255, 255, 0, 255}, 100.0f, 50.0f, 0);

	hockeyStick = WORLD->SpawnActorOfClass<HockeyStick>(exVector2{ 700.0f, 200.0f }, exColor{ 0, 255, 55, 255 });


}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mUp = pState[SDL_SCANCODE_LEFT];
	mDown = pState[SDL_SCANCODE_RIGHT];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	if ( mUp )
	{
		Steph->SetVelocity(exVector2{ 0.0f, -1.0f });
		mTextPosition.y -= 40.0f * fDeltaT;
	}
	else if ( mDown )
	{
		Steph->SetVelocity(exVector2{ 0.0f, 1.0f });
		mTextPosition.y += 40.0f * fDeltaT;
	}

	exVector2 p1, p2;
	exColor c;
	float r;

	c.mColor[0] = 255;
	c.mColor[1] = 0;
	c.mColor[2] = 255;
	c.mColor[3] = 255;

	p1.x = 175.0f;
	p1.y = 175.0f;

	r = 25.0f;

	mEngine->DrawLineCircle( p1, r, c, 0 );

	//mEngine->DrawCircle({ kViewportWidth * 0.5f, kViewportHeight * 0.5f }, 50.0f, { 255,0,0,255 }, 1);

	mEngine->DrawLine({ kViewportWidth * 0.5f - 25.0f, kViewportHeight * 0.5f - 25.0f },
		{ kViewportWidth * 0.5f + 25.0f, kViewportHeight * 0.5f - 25.0f }, { 255,0,0,255 }, 1);

	mEngine->DrawLine({ kViewportWidth * 0.5f - 25.0f, kViewportHeight * 0.5f - 25.0f },
		{ kViewportWidth * 0.5f, kViewportHeight * 0.5f + 25.0f }, { 255,0,0,255 }, 1);

	mEngine->DrawLine({kViewportWidth * 0.5f + 25.0f, kViewportHeight * 0.5f - 25.0f },
		{kViewportWidth * 0.5f, kViewportHeight * 0.5f + 25.0f }, { 255,0,0,255 }, 1);


	mEngine->DrawLineCircle({ kViewportWidth * 0.5f, kViewportHeight * 0.5f }, 150.0f, { 255,0,0,255 }, 1);

	// Eyes
	mEngine->DrawLineCircle({ kViewportWidth * 0.5f + 50, kViewportHeight * 0.5f - 50 }, 25.0f, { 255,0,0,255 }, 1);
	mEngine->DrawLineCircle({ kViewportWidth * 0.5f + 50, kViewportHeight * 0.5f - 50 }, 10.0f, { 255,0,0,255 }, 1);

	mEngine->DrawLineCircle({ kViewportWidth * 0.5f - 50, kViewportHeight * 0.5f - 50 }, 25.0f, { 255,0,0,255 }, 1);
	mEngine->DrawLineCircle({ kViewportWidth * 0.5f - 50, kViewportHeight * 0.5f - 50 }, 10.0f, { 255,0,0,255 }, 1);


	mEngine->DrawLine({ kViewportWidth * 0.5f + 50.0f, kViewportHeight * 0.5f + 50.0f },
		{ kViewportWidth * 0.5f - 50.0f, kViewportHeight * 0.5f + 50.0f }, { 255,0,0,255 }, 1);


	//p1.x = 100.0f;
	//p1.y = 100.0f;

	//p2.x = 200.0f;
	//p2.y = 200.0f;

	//c.mColor[0] = 255;
	//c.mColor[1] = 0;
	//c.mColor[2] = 0;

	//mEngine->DrawBox( p1, p2, c, 1 );

	//p1.x = 400.0f;
	//p1.y = 400.0f;

	//p2.x = 500.0f;
	//p2.y = 500.0f;

	//mEngine->DrawLineBox( p1, p2, c, 1 );

	//p1.x = 400.0f;
	//p1.y = 400.0f;

	//c.mColor[0] = 0;
	//c.mColor[1] = 0;
	//c.mColor[2] = 0;

	//mEngine->DrawCircle( p1, r, c, 2 );

	mEngine->DrawText( mFontID, mTextPosition, "VFS", c, 0 );

	//if (std::shared_ptr<RenderComponent> renderComp = GameDesignersHead->FindComponentOfType<RenderComponent>()) 
	//{
	//	renderComp->Render(mEngine);
	//}

	if(mEngine)
		RENDER_ENGINE->Render(mEngine);

	PHYSICS_ENGINE->Physics();

	if (std::shared_ptr<PhysicsComponent> physicsComponents = GameDesignersHead->FindComponentOfType<PhysicsComponent>()) 
	{
		//physicsComponents->Physics();
	}
}
