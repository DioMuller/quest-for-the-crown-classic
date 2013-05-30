#include "GameManager.h"
#include "Helpers.h"

GameManager instance;

GameManager::GameManager()
{
	_player = new Player(10,10);

	//TODO: Initialize level manager here!
	char level[23][81] = {
		"###############################################################################",
		"1                        ######################################################",
		"1                                 #############################################",
		"1                                         #####################################",
		"1                                              ################################",
		"1                 o                                     #######################",
		"1                                                 o            ################",
		"1                                                                     #########",
		"1                                                                         #####",
		"1                                o                                       ######",
		"1           o                                                              ####",
		"1                                                         o               #####",
		"1                                                                         #####",
		"1                                                                          ####",
		"1                                                                         #####",
		"1                                                  o                     ######",
		"1                  o              o                                           3",
		"1                                                                             3",
		"1                                                             #################",
		"1                                                   ###########################",
		"1       ######################              ###################################",
		"1    #############################      #######################################",
		"####################################55#########################################"
	};

	_level = new Level(level, BACKGROUND_GREEN);

	_isRunning = true;
	_initialized = true;
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

		//TODO: UPDATE LEVEL
		instance._level->Update(instance._currentTime);
}

void GameManager::DrawGame()
{
		//For each Game Object -> Draw
		instance._player->Draw();

		//TODO: DRAW LEVEL
		instance._level->Draw();
		
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
	//TODO: CHECK LEVEL HITS.
}

WORD GameManager::GetBackground()
{
	//TODO: GET LEVEL BG COLOR
	return BACKGROUND_GREEN;//instance._background;
}

void GameManager::EndGame()
{
	instance._isRunning = false;
}
