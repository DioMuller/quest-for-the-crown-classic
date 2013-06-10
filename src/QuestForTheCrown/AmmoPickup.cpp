#include "AmmoPickup.h"


#include "GameManager.h"

AmmoPickup::AmmoPickup(int x, int y) : GameObject(x,y)
{
    _sprite = "=";
    _color = FOREGROUND_WHITE | FOREGROUND_INTENSITY;

    _forcedraw = true;
}


AmmoPickup::~AmmoPickup()
{
}

void AmmoPickup::Update(double gameTime)
{
    Position player = GameManager::GetPlayerPosition();

    if( _position.X == player.X && _position.Y == player.Y )
    {
        GameManager::AddAmmo(BOW, 5);
        GameManager::RemoveObject(this);
    }
}

bool AmmoPickup::CollidesWith(int x, int y)
{
    Position player = GameManager::GetPlayerPosition();

    if( _position.X == player.X && _position.Y == player.Y )
    {
        return GameObject::CollidesWith(x,y);
    }
    else
    {
        return false;
    }
}