#pragma once
#include "gameobject.h"
class Player : public GameObject
{
	public:
		Player(int x, int y);
		~Player();

	public:
		void Update(double gameTime);
		void Draw();
};

