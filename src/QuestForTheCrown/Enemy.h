#pragma once
#include "gameobject.h"
class Enemy : public GameObject
{
	protected:
		int _moveCount;
		int _nextMovement;
	public:
		Enemy(int x, int y, int moveCount);
		~Enemy();

	public:
		void Update(double gameTime);
		void Draw();
};

