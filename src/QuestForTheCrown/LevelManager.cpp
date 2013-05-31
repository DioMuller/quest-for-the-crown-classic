#include "LevelManager.h"
#include "Maps.h"


LevelManager::LevelManager()
{
	_levels = new Level*[9];

	_levels[0] = &map01;
	_levels[1] = &map02;
	_levels[2] = &map03;
	_levels[3] = &map04;
	_levels[4] = &map05;
	_levels[5] = &map06;
	_levels[6] = &map07;
	_levels[7] = &map08;
	_levels[8] = &map09;

	_currentLevel = 0;
}


LevelManager::~LevelManager()
{
	for( int i = 0; i < 9; i++ )
	{
		delete _levels[i];
	}

	delete[] _levels;	
}

Level* LevelManager::GetCurrentLevel()
{
	return _levels[_currentLevel];
}

void LevelManager::ChangeLevel(Player* player, Direction direction)
{
	GetCurrentLevel()->ResetDraw();
	_currentLevel = ( GetCurrentLevel()->GetNeighbour(direction) );
	
	switch (direction)
	{
		case UP:
			player->SetY(23);
			break;
		case DOWN:
			player->SetY(3);
			break;
		case LEFT:
			player->SetX(78);
			break;
		case RIGHT:
			player->SetX(1);
			break;
		default:
			break;
	}
}

void LevelManager::Update(double gameTime)
{
	GetCurrentLevel()->Update(gameTime);
}

void LevelManager::Draw()
{
	GetCurrentLevel()->Draw();
}

bool LevelManager::CheckXY(int x, int y)
{
	return GetCurrentLevel()->CheckXY(x,y);
}

WORD LevelManager::GetLevelBackground()
{
	return GetCurrentLevel()->GetBackground();
}

void LevelManager::TryHit(int x, int y)
{
	GetCurrentLevel()->HitObjects(x,y);
}