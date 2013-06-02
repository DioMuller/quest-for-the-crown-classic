#include "LevelManager.h"
#include "GameManager.h"
#include "Definitions.h"


LevelManager::LevelManager(Level** levels, int levelCount, LevelManager** dungeons, int dungeonCount, Position startPoint)
{
	_levelCount = levelCount;
	_dungeonCount = dungeonCount;

	_levels = levels;
	_dungeons = dungeons;

	_currentLevel = 0;
	_currentDungeon = -1;

	_startPoint = startPoint;
}

LevelManager::~LevelManager()
{
	if( _parent == NULL )
	{
		if( _levels )
		{
			for( int i = 0; i < _levelCount; i++ )
			{
				delete (Level*) _levels[i];
			}

			delete[] _levels;	
		}

		if( _dungeons )
		{
			for( int i = 0; i < _dungeonCount; i++ )
			{
				delete (Level*) _dungeons[i];
			}

			delete[] _dungeons;	
		}
	}
}

Level* LevelManager::GetCurrentLevel()
{
	if( _currentDungeon == NONE )
	{
		return _levels[_currentLevel];
	}
	else
	{
		return _dungeons[_currentDungeon]->GetCurrentLevel();
	}
}

void LevelManager::ChangeLevel(Player* player, Direction direction)
{
	int neighbour = GetCurrentLevel()->GetNeighbour(direction);

	if( neighbour == OUTSIDE )
	{
		BackToMap();
	}
	else
	{
		GetCurrentLevel()->ResetDraw();
		SetCurrentLevel( neighbour );
	
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

void LevelManager::InitializeChildren()
{
	if( _dungeons )
	{
		for( int i = 0; i < _dungeonCount; i++ )
		{
			_dungeons[i]->SetParent(this);
			_dungeons[i]->InitializeChildren();
		}
	}
}

void LevelManager::GoToDungeon(int id)
{
	Position player = GameManager::GetPlayerPosition();
	player.Y++; //Realocate one down

	_oldPoint = player;

	_currentDungeon = id;

	GetCurrentLevel()->ResetDraw();

	GameManager::SetPlayerPosition(_dungeons[_currentDungeon]->GetStart());
}

void LevelManager::BackToMap()
{
	_currentDungeon = NONE;
	GetCurrentLevel()->ResetDraw();

	GameManager::SetPlayerPosition(_oldPoint);
}

Position LevelManager::GetStart()
{
	return _startPoint;
}

void LevelManager::SetCurrentLevel(int level)
{
	if( _currentDungeon == NONE )
	{
		_currentLevel = level;
	}
	else
	{
		_dungeons[_currentDungeon]->SetCurrentLevel(level);
	}
}