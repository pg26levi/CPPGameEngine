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

#include "Game/GameCore/Utils.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "W Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

double Time::DeltaTime = 0.0f;
double Time::ElapsedTime = 0.0f;

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mRight( false )
	, mLeft( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{

	delete RenderThread;
	delete PhysicsThread;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "Build/Kanit-Regular.ttf", 24 );

	mTextPosition.x = 50.0f;
	mTextPosition.y = 50.0f;


	//GameDesignersHead = WORLD->SpawnActorOfClass<Football>(exVector2{ 500.0f, 500.0f }, exColor{ 255, 255, 0, 255 }, 30.0f);

	//Steph = WORLD->SpawnActorOfClass<Football>(exVector2{ 700.0f, 400.0f }, exColor{ 155, 255, 0, 255 }, 10.0f);
	////Steph->AddComponentOfType<CircleRenderComponent>(exColor{ 155, 255, 0, 255 }, 10.0f, 0);
	////Steph->AddComponentOfType<CircleColliderPhysicsComponent>(10.0f, exVector2{ -1.0f, 0.0f });

	//Henry = WORLD->SpawnActorOfClass<Actor>(exVector2{ 200.0f, 400.0f });
	//Henry->AddComponentOfType<CircleRenderComponent>(exColor{ 0, 0, 0, 255 }, 30.0f, 0);
	//Henry->AddComponentOfType<CircleColliderPhysicsComponent>(30.0f, exVector2{ 1.0f, 0.0f });
	//
	//myBox = WORLD->SpawnActorOfClass<Actor>(exVector2{ 400.0f, 300.0f });
	//myBox->AddComponentOfType<BoxRenderComponent>(exColor{255, 255, 0, 255}, 100.0f, 50.0f, 0);

	//hockeyStick = WORLD->SpawnActorOfClass<HockeyStick>(exVector2{ 700.0f, 200.0f }, exColor{ 0, 255, 55, 255 });



	playerPos = glm::vec3(0.0f, 0.0f, -5.0f);
	Player = WORLD->SpawnActorOfClass<Actor>(playerPos);
	Player->AddComponentOfType<CameraComponent>(90.0f, 0.1f, 1000.0f);

	WORLD->SetActiveCamera(Player);

	myCube = WORLD->SpawnActorOfClass<Actor>(glm::vec3(-5.0f, 0.0f, 0.0f));
	myCube->AddComponentOfType<CubeRenderComponent>(exColor{ 255, 0, 0, 255 }, 0.0f);

	myCube2 = WORLD->SpawnActorOfClass<Actor>(glm::vec3(0.0f, 0.0f, 0.0f));
	myCube2->AddComponentOfType<CubeRenderComponent>(exColor{ 0, 255, 0, 255 }, 0.0f);

	myCube3 = WORLD->SpawnActorOfClass<Actor>(glm::vec3(5.0f, 0.0f, 0.0f));
	myCube3->AddComponentOfType<CubeRenderComponent>(exColor{ 0, 0, 255, 255 }, 0.0f);

	exColor col;

	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) {
			// SMILEY FACE
			if ((j == 1 && (i >= 2 && i <= 7)) || ((j == 2 || j == 3) && (i == 1 || i == 8)) || ((i == 3 || i == 6) && (j == 5 || j == 6 || j == 7))) 
			{
				col = exColor{ 0, 0, 255, 255 };
			}
			else 
				col = exColor{ 255, 0, 255, 255 };
			

			WORLD->SpawnActorOfClass<Actor>(glm::vec3( i * 2, j * 2, -10.0f ))->AddComponentOfType<CubeRenderComponent>(col, 0.0f);;
		}
	}

	//SDL_SetRelativeMouseMode(SDL_TRUE);

	prevFrameTime = SDL_GetTicks();


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
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
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

	mRight = pState[SDL_SCANCODE_D];
	mLeft = pState[SDL_SCANCODE_A];
	mBackwards = pState[SDL_SCANCODE_S];
	mForward = pState[SDL_SCANCODE_W];

	mUp = pState[SDL_SCANCODE_Q];
	mDown = pState[SDL_SCANCODE_E];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{


	Uint32 currentFrameTime = SDL_GetTicks();
	float deltaTime = (currentFrameTime - prevFrameTime) / 1000.0f;
	prevFrameTime = currentFrameTime;

	Time::DeltaTime = deltaTime;


	if ( mRight )
	{
		playerPos.x -= 10.0f * Time::DeltaTime;
	}
	if ( mLeft )
	{
		playerPos.x += 10.0f * Time::DeltaTime;
	}
	if (mForward) 
	{
		playerPos.z += 10.0f * Time::DeltaTime;
	}
	if (mBackwards)
	{
		playerPos.z -= 10.0f * Time::DeltaTime;
	}
	if (mUp) 
	{
		playerPos.y += 10.0f * Time::DeltaTime;
	}
	if (mDown) 
	{
		playerPos.y -= 10.0f * Time::DeltaTime;
	}


	Player->FindComponentOfType<TransformComponent>()->SetPosition(playerPos);

	//exVector2 p1, p2;
	exColor c;
	//float r;
	//c.mColor[1] = 0;
	//c.mColor[0] = 255;
	//c.mColor[2] = 255;
	//c.mColor[3] = 255;
	
	//p1.x = 175.0f;
	//p1.y = 175.0f;

	//r = 25.0f;

	//mEngine->DrawLineCircle( p1, r, c, 0 );

	////mEngine->DrawCircle({ kViewportWidth * 0.5f, kViewportHeight * 0.5f }, 50.0f, { 255,0,0,255 }, 1);

	//mEngine->DrawLine({ kViewportWidth * 0.5f - 25.0f, kViewportHeight * 0.5f - 25.0f },
	//	{ kViewportWidth * 0.5f + 25.0f, kViewportHeight * 0.5f - 25.0f }, { 255,0,0,255 }, 1);

	//mEngine->DrawLine({ kViewportWidth * 0.5f - 25.0f, kViewportHeight * 0.5f - 25.0f },
	//	{ kViewportWidth * 0.5f, kViewportHeight * 0.5f + 25.0f }, { 255,0,0,255 }, 1);

	//mEngine->DrawLine({kViewportWidth * 0.5f + 25.0f, kViewportHeight * 0.5f - 25.0f },
	//	{kViewportWidth * 0.5f, kViewportHeight * 0.5f + 25.0f }, { 255,0,0,255 }, 1);


	//mEngine->DrawLineCircle({ kViewportWidth * 0.5f, kViewportHeight * 0.5f }, 150.0f, { 255,0,0,255 }, 1);

	//// Eyes
	//mEngine->DrawLineCircle({ kViewportWidth * 0.5f + 50, kViewportHeight * 0.5f - 50 }, 25.0f, { 255,0,0,255 }, 1);
	//mEngine->DrawLineCircle({ kViewportWidth * 0.5f + 50, kViewportHeight * 0.5f - 50 }, 10.0f, { 255,0,0,255 }, 1);

	//mEngine->DrawLineCircle({ kViewportWidth * 0.5f - 50, kViewportHeight * 0.5f - 50 }, 25.0f, { 255,0,0,255 }, 1);
	//mEngine->DrawLineCircle({ kViewportWidth * 0.5f - 50, kViewportHeight * 0.5f - 50 }, 10.0f, { 255,0,0,255 }, 1);


	//mEngine->DrawLine({ kViewportWidth * 0.5f + 50.0f, kViewportHeight * 0.5f + 50.0f },
	//	{ kViewportWidth * 0.5f - 50.0f, kViewportHeight * 0.5f + 50.0f }, { 255,0,0,255 }, 1);


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

	c.mColor[0] = 255;
	c.mColor[1] = 255;
	c.mColor[2] = 255;


	//mEngine->DrawCircle( p1, r, c, 2 );

	//mEngine->DrawText( mFontID, mTextPosition, "rizz", c, 0 );

	double fps = 1000.0f / Time::DeltaTime;

	mEngine->DrawText(mFontID, exVector2{ 0.0f, 0.0f }, (std::to_string(fps) + "FPS").c_str(), c, 0);
	mEngine->DrawText(mFontID, exVector2{ 0.0f, 25.0f }, (std::to_string(Time::DeltaTime) + "ms / frame").c_str(), c, 0);


	PhysicsThread = new std::thread(&MyGame::Physics, this);
	RenderThread = new std::thread(&MyGame::Render, this);

	//canRender = true;
	//canPhysics = true;

	RenderThread->join();
	PhysicsThread->join();

	//canRender = false;
	//canPhysics = false;

	Time::ElapsedTime += Time::DeltaTime;

	glm::vec3 pos = Player->GetPosition();
	std::string posString = "Camera Pos: " + std::to_string(pos.x).substr(0, 5) + ", " + std::to_string(pos.y).substr(0, 5) + ", " + std::to_string(pos.z).substr(0, 5);
	mEngine->DrawText(0, exVector2{ 0.0f, 50.0f }, posString.c_str(), exColor{ 255, 0, 0, 255 }, 0);

}

void MyGame::Render() 
{
	if (!canRender)
		return;

	if (mEngine) 
	{
		RENDER_ENGINE->Render(mEngine);
	}
}

void MyGame::Physics() 
{
	if(!canPhysics)
		PHYSICS_ENGINE->Physics();
}
