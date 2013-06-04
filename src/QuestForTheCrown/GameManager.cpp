#include "GameManager.h"
#include "Helpers.h"
#include "Maps.h"

GameManager instance;

GameManager::GameManager()
{
	//Initialize the player
	_player = new Player(10,10);

	//Initialize Level Manager
	_manager = overworldMap;
	_manager->InitializeChildren();

	//Initialize Game State
	_isRunning = true;
	_initialized = true;
	_success = false;
}

GameManager::~GameManager()
{
	//Delete all elements from objects?
	delete _player;
}

void GameManager::UpdateGame()
{
		instance._currentTime = current_time();

		//For each Game Object -> Update
		instance._player->Update(instance._currentTime);

		//Updates Level
		instance._manager->Update(instance._currentTime);
}

void GameManager::DrawGame()
{
		//For each Game Object -> Draw
		instance._player->Draw();

		//TODO: DRAW LEVEL
		instance._manager->Draw();
		
		//Draw GUI Bar
		mostrar(0,0,FOREGROUND_WHITE, "Life                                                                            ");
		mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");
		
		for( int i = 0; i < instance._player->GetTotalHealth(); i++ )
		{
			WORD color = instance._player->GetCurrentHealth() > i  ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_WHITE;
			mostrar( 6 + i, 0, color, "@");
		}
}

void GameManager::HitPlayer(int x, int y)
{
	if( instance._player->CollidesWith(x,y) )
	{
		instance._player->Hit();
	}
}

bool GameManager::IsRunning()
{
	return instance._initialized && instance._isRunning;
}

void GameManager::TryHit(int x, int y)
{
	instance._manager->TryHit(x,y);
}

WORD GameManager::GetBackground()
{
	return instance._manager->GetLevelBackground();
}

void GameManager::EndGame(bool success)
{
	instance._success = success;
	instance._isRunning = false;
}

bool GameManager::CanMoveTo(int x, int y, bool isProjectile)
{
	if( x < 0 || x > 79 || y < 2 || y > 24 ) return false;

	return instance._manager->CheckXY(x, y, isProjectile);
}


void GameManager::ChangeLevel(Direction direction)
{
	instance._manager->ChangeLevel(instance._player, direction);
}

bool GameManager::WasSuccessful()
{
	return instance._success;
}

Position GameManager::GetPlayerPosition()
{
	return instance._player->GetPosition();
}

void GameManager::SetPlayerPosition(Position position)
{
	instance._player->SetX(position.X);
	instance._player->SetY(position.Y);
}

void GameManager::GoToDungeon(int dungeon)
{
	instance._manager->GoToDungeon(dungeon);
}

void GameManager::AddObject(GameObject* object)
{
	instance._manager->AddObject(object);
}

void GameManager::RemoveObject(GameObject* object)
{
	instance._manager->RemoveObject(object);
}