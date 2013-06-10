#include "Weapon.h"


Weapon::Weapon(int x, int y, char* holder[4], char* projectile[4], int speed, int frames)
{
	_isProjectile = (speed != 0);
	_hold = new WeaponPart(x, y, holder, 0, frames, false, false);
	_projectile = new WeaponPart(x, y, projectile, speed, frames, _isProjectile, false);

    if( _isProjectile )
    {
        _ammo = 30;
    }
    else
    {
        _ammo = 0;
    }
}


Weapon::~Weapon()
{
	delete _hold;
	delete _projectile;
}

void Weapon::Show(int x, int y, Direction direction)
{
	if( _hold->Show(x,y,direction) && (!_isProjectile || _ammo > 0) )
    {
        _projectile->Show(_hold->GetPosition().X, _hold->GetPosition().Y, direction);
        if( _isProjectile ) _ammo--;
    }
}

void Weapon::Update(double gameTime)
{
	_hold->Update(gameTime);
	_projectile->Update(gameTime);
}

void Weapon::Draw()
{
    _hold->Draw();
    _projectile->Draw();
}

int Weapon::GetAmmo()
{
    return _ammo;
}

void Weapon::AddAmmo(int toAdd)
{
    _ammo += toAdd;

    if( _ammo > 100 ) _ammo = 100;
}