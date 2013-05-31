#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "Enemy.h"
#include "GameManager.h"


Enemy::Enemy(int x, int y, EnemyType type) : GameObject(x,y)
{
	int moveCount = 0;
	_type = type;

	switch (_type)
	{
		case SLIME:
			moveCount = 10;
			break;
		case GOON:
			moveCount = 15;
			break;
		case WIZARD:
			moveCount = 20;
			break;
		default:
			break;
	}

	_color = FOREGROUND_RED | FOREGROUND_INTENSITY;

	_sprite = new char[2];
	_sprite[0] = _type;
	_sprite[1] = '\0';

	_moveCount = moveCount;
	_nextMovement = moveCount;

}


Enemy::~Enemy()
{
	//Nothing else to do.
}

void Enemy::Update(double gameTime)
{
	_nextMovement--;

	if( _nextMovement <= 0 )
	{
		int new_x = _x + (rand() % 4) - 1; //-1, 0, 1
		int new_y = _y + (rand() % 4) - 1; //-1, 0, 1
		
		if( GameManager::CanMoveTo(new_x, new_y ) )
		{
			_x = new_x;
			_y = new_y;
		}

		_nextMovement = _moveCount;
	}

	GameManager::HitPlayer(_x,_y);
	GameObject::Update(gameTime);
}