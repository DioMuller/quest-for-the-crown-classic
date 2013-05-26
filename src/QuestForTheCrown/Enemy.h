#pragma once
#include "gameobject.h"
class Enemy : public GameObject
{
	private:
		int _lastX;
		int _lastY;
	public:
		Enemy(int x, int y);
		~Enemy();

	public:
		void Update(double gameTime);
		void Draw();
};

