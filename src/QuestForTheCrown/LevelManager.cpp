#include "LevelManager.h"
#include "Definitions.h"


LevelManager::LevelManager(Level** levels, int levelCount, LevelManager** dungeons, int dungeonCount)
{
	_levelCount = levelCount;
	_dungeonCount = dungeonCount;

	_levels = levels;
	_dungeons = dungeons;

	_currentLevel = 0;
	_currentDungeon = -1;
}

LevelManager::~LevelManager()
{
	if( _levels )
	{
		for( int i = 0; i < _levelCount; i++ )
		{
			delete _levels[i];
		}

		delete[] _levels;	
	}

	if( _dungeons )
	{
		for( int i = 0; i < _dungeonCount; i++ )
		{
			delete _dungeons[i];
		}

		delete[] _dungeons;	
	}
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

void LevelManager::SetParent(LevelManager* parent)
{
	_parent = parent;
}

void LevelManager::InitializeChild()
{
	if( _dungeons )
	{
		for( int i = 0; i < _levelCount; i++ )
		{
			_dungeons[i]->SetParent(this);
		}
	}
}