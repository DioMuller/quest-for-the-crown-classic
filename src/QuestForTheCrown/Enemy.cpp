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

	_color = FOREGROUND_RED;

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
		_x += (rand() % 4) - 2; //-1, 0, 1
		_y += (rand() % 4) - 2; //-1, 0, 1

		if( _x < 0 ) _x = 0;
		if( _x > 79 ) _x = 79;

		if( _y < 2 ) _y = 2;
		if( _y > 24 ) _y = 24;

		_nextMovement = _moveCount;
	}

	GameManager::HitPlayer(_x,_y);
	GameObject::Update(gameTime);
}