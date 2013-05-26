#include "GameManager.h"
#include "Helpers.h"

GameManager instance;

GameManager::GameManager()
{
	_player = new Player(10,10);

	_background = BACKGROUND_GREEN;

	_objects.push_back(new Enemy(15, 15, 15));
	_objects.push_back(new Enemy(12, 19, 15));
	_objects.push_back(new Enemy(70, 5, 15));
	_objects.push_back(new Enemy(2, 2, 15));
	_objects.push_back(new Enemy(49, 21, 15));
	_objects.push_back(new Enemy(5, 20, 15));
	_objects.push_back(new Enemy(15, 23, 15));

	_isRunning = true;
	_initialized = true;
}

GameManager::~GameManager()
{
	//Delete all elements from objects?
}

void GameManager::UpdateGame()
{
		instance._currentTime = current_time();

		//For each Game Object -> Update
		instance._player->Update(instance._currentTime);

		for( instance._iterator = instance._objects.begin(); instance._iterator != instance._objects.end(); instance._iterator++  )
		{
			(*instance._iterator)->Update(instance._currentTime);
		}
}

void GameManager::DrawGame()
{
		//Clear Screen
		clrscr(instance._background);

		//For each Game Object -> Draw
		instance._player->Draw();

		for( instance._iterator = instance._objects.begin(); instance._iterator != instance._objects.end(); instance._iterator++  )
		{
			(*instance._iterator)->Draw();
		}
		
		//Draw GUI Bar
		mostrar(0,0,FOREGROUND_WHITE, "Life                                                                            ");
		mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");
		
		for( int i = 0; i < instance._player->GetTotalHealth(); i++ )
		{
			WORD color = instance._player->GetCurrentHealth() > i  ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_WHITE;
			mostrar( 6 + i, 0, color, "@");
		}
}

void GameManager::TryHit(int x, int y)
{
  	std::list<Enemy*> toRemove;

	for( instance._iterator = instance._objects.begin(); instance._iterator != instance._objects.end(); instance._iterator++  )
	{
		Enemy* obj = (Enemy*) (*instance._iterator);

		if( obj != NULL )
		{
			if( obj->CollidesWith(x,y) )
			{
				toRemove.push_back(obj);
			}
		}
	}

	for( std::list<Enemy*>::iterator iterator = toRemove.begin(); iterator != toRemove.end(); iterator++ )
	{
		instance._objects.remove((*iterator));
	}

	if( instance._objects.empty() ) EndGame();
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

WORD GameManager::GetBackground()
{
	return instance._background;
}

void GameManager::EndGame()
{
	instance._isRunning = false;
}
