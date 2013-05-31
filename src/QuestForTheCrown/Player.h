#pragma once
#include "gameobject.h"
#include "Weapon.h"

#define MOVE_DELAY 2

class Player : public GameObject
{
	private:
		int _actionFrames;

		int _currentHealth;
		int _totalHealth;
		
		int _movementDelayTime;

		int _invencibleTime;

		Weapon* _sword;
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

		void SetX( int pos );
		void SetY( int pos );
};

