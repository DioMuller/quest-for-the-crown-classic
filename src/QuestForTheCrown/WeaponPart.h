#pragma once
#include "gameobject.h"
#include "Enum.h"

class WeaponPart :	public GameObject
{
	private:
		char* _appearance[4];
		int _speed;
		int _frames;
		Direction _direction;

		int _speedX;
		int _speedY;

		int _active;
		bool _isProjectile;
		bool _isEnemy;

	public:
		WeaponPart(int x, int y, char* appearance[4], int speed, int frames, bool isProjectile, bool isEnemy);
		WeaponPart(WeaponPart* toClone);
		~WeaponPart();

	public: 		
		bool Show(int x, int y, Direction direction);
		void Hide();

		void Update(double gameTime);
		void Draw();
};

