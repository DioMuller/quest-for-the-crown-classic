#pragma once
#include "gameobject.h"
#include "Enum.h"

class Enemy : public GameObject
{
	protected:
		int _moveCount;
		int _nextMovement;
		EnemyType _type;
	public:
		Enemy(int x, int y, EnemyType type);
		~Enemy();

	public:
		void Update(double gameTime);

		EnemyType GetType();
};

