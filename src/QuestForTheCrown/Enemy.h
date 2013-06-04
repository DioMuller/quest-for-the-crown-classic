#pragma once
#include "gameobject.h"
#include "Enum.h"
#include "WeaponPart.h"

#define ATTACK_DELAY 120

class Enemy : public GameObject
{
	protected:
		int _moveCount;
		int _nextMovement;
		EnemyType _type;
		//Will be used only with enemies with pattern movements.
		Direction _direction;

		WeaponPart* _weapon;

		int _timeUntilNextAttack;
	public:
		Enemy(int x, int y, EnemyType type);
		~Enemy();

	public:
		void Update(double gameTime);

		EnemyType GetType();
};

