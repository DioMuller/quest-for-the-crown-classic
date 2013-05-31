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

	public:
		WeaponPart(int x, int y, char* appearance[4], int speed, int frames);
		~WeaponPart(void);

	public: 		
		void Show(int x, int y, Direction direction);

		void Update(double gameTime);
		void Draw();
};

