#pragma once
#include "WeaponPart.h"
#include "Enum.h"

class Weapon
{
	private:
		Direction _direction;
		
		WeaponPart* _hold;
		WeaponPart* _projectile;
		bool _isProjectile;

	public:
		Weapon(int x, int y, char* holder[4], char* projectile[4], int speed, int frames);
		~Weapon();

	public:
		void Show(int x, int y, Direction direction);

		void Update(double gameTime);
		void Draw();
};

