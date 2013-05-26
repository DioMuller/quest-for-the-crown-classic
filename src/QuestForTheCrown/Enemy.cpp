#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "Enemy.h"
#include "GameManager.h"


Enemy::Enemy(int x, int y, int moveCount) : GameObject(x,y)
{
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
}

void Enemy::Draw()
{
	//Draw new position
	mostrar(_x, _y, FOREGROUND_RED | GameManager::GetBackground(), "o");
}