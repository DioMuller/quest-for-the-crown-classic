#include "Weapon.h"


Weapon::Weapon(int x, int y, char* holder[4], char* projectile[4], int speed, int frames)
{
	_hold = new WeaponPart(x, y, holder, 0, frames);
	_projectile = new WeaponPart(x, y, projectile, speed, frames);
}


Weapon::~Weapon()
{
	delete _hold;
	delete _projectile;
}

void Weapon::Show(int x, int y, Direction direction)
{
	_hold->Show(x,y,direction);
	_projectile->Show(_hold->GetX(), _hold->GetY(), direction);
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