#pragma once
#include "GameObject.h"

class LifePickup : public GameObject
{
    public:
        LifePickup(int x, int y);
        ~LifePickup();

    public:
        void Update(double gameTime);
        bool CollidesWith(int x, int y);
};

