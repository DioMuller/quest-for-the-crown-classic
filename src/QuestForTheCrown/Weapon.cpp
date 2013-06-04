#include "Weapon.h"


Weapon::Weapon(int x, int y, char* holder[4], char* projectile[4], int speed, int frames)
{
	_hold = new WeaponPart(x, y, holder, 0, frames, false, false);
	_projectile = new WeaponPart(x, y, projectile, speed, frames, false, false);
}


Weapon::~Weapon()
{
	delete _hold;
	delete _projectile;
}

void Weapon::Show(int x, int y, Direction direction)
{
	_hold->Show(x,y,direction);
	_projectile->Show(_hold->GetPosition().X, _hold->GetPosition().Y, direction);
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