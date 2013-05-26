#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "Enemy.h"


Enemy::Enemy(int x, int y) : GameObject(x,y)
{
	_lastX = -1;
	_lastY = -1;
	//Nothing else to do.
}


Enemy::~Enemy()
{
	//Nothing else to do.
}

void Enemy::Update(double gameTime)
{
	_lastX = _x;
	_lastY = _y;

	srand(clock());

	_x += (rand() % 3) - 2; //-1, 0, 1
	_y += (rand() % 3) - 2; //-1, 0, 1
}

void Enemy::Draw()
{
	if( _lastX != _x && _lastY != _y )
	{
		//Clean up last position
		if( _lastX != -1 ) mostrar(_lastX, _lastY, BACKGROUND_CYAN, " ");

		//Draw new position
		mostrar(_x, _y, FOREGROUND_RED | BACKGROUND_CYAN, "o");
	}
}