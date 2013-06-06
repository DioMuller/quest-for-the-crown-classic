#pragma once
#include "GameObject.h"

class WeaponPickup : public GameObject
{
    public:
        WeaponPickup(int x, int y);
        ~WeaponPickup();

    public:
        void Update(double gameTime);
};

