#pragma once
#include "GameObject.h"

class AmmoPickup : public GameObject
{
public:
    AmmoPickup(int x, int y);
    ~AmmoPickup();

    void Update(double gameTime);
    bool CollidesWith(int x, int y);
};

