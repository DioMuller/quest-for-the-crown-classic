#pragma once
#include "GameObject.h"
#include "Enum.h"

class Weapon : GameObject
{
	private:
		Direction _direction;
		char _projectile[4];
		char _holder[4];

	public:
		Weapon(int x, int y, Direction direction);
		~Weapon();
};

