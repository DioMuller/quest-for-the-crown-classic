#include "LifePickup.h"
#include "GameManager.h"

LifePickup::LifePickup(int x, int y) : GameObject(x,y)
{
    _sprite = "+";
    _color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    _forcedraw = true;
}


LifePickup::~LifePickup()
{
}

void LifePickup::Update(double gameTime)
{
    Position player = GameManager::GetPlayerPosition();

    if( _position.X == player.X && _position.Y == player.Y )
    {
        GameManager::HealPlayer();
        GameManager::RemoveObject(this);
    }
}

bool LifePickup::CollidesWith(int x, int y)
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