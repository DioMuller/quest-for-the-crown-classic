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

		int _currentHealth;
		int _totalHealth;
		
		int _invencibleTime;
	public:
		Player(int x, int y);
		~Player();

	public:
		void Update(double gameTime);
		void Draw();

	public: 
		void Hit();
		int GetTotalHealth();
		int GetCurrentHealth();
};

