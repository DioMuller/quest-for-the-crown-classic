#pragma once
#include "gameobject.h"
#include "Weapon.h"

#define MOVE_DELAY 1
#define NUM_WEAPONS 2

class Player : public GameObject
{
	private:
		int _actionFrames;

		int _currentHealth;
		int _totalHealth;
		
		int _movementDelayTime;

		int _invencibleTime;

        int _totalWeapons;

		WeaponType _currentWeapon;
		Weapon* _weapons[NUM_WEAPONS];
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
        void RestoreHealth();
        void UpgradeHealth();


		void SetX( int pos );
		void SetY( int pos );

		WeaponType GetCurrentWeapon();

        void AddWeapon();
        bool HasWeapon(WeaponType type);
};

