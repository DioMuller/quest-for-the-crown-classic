#pragma once
#include "gameobject.h"

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Player : public GameObject
{
	private:
		Direction _direction;
		int _actionFrames;
	public:
		Player(int x, int y);
		Player();
		~Player();

	public:
		void Update(double gameTime);
		void Draw();
};

