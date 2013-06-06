#include "WeaponPickup.h"
#include "GameManager.h"


WeaponPickup::WeaponPickup(int x, int y) : GameObject(x,y)
{
    _sprite = "D";
    _color = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
}


WeaponPickup::~WeaponPickup()
{
    //Nothing else to do.
}

void WeaponPickup::Update(double gameTime)
{
    GameObject::Update(gameTime);

    Position player = GameManager::GetPlayerPosition();

    if( _position.X == player.X && _position.Y == player.Y )
    {
        GameManager::AddPlayerWeapon();
        GameManager::RemoveObject(this);

        //TODO: Show Message or Cutscene?
    } 
}