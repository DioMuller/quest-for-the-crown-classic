#include "WeaponPart.h"
#include "GameManager.h"


WeaponPart::WeaponPart(int x, int y, char* appearance[4], int speed, int frames) : GameObject(x,y)
{
	for( int i = 0; i < 4; i++ )
	{
		_appearance[i] = _appearance[i];
	}

	_speed = speed;
	_frames = frames;

	_active = 0;
}


WeaponPart::~WeaponPart()
{
	for( int i = 0; i < 4; i++ )
	{
		delete _appearance[i];
	}
}
	
void WeaponPart::Show(int x, int y, Direction direction)
{
	int x_diff = direction == LEFT ? -1 : direction == RIGHT ? 1 : 0;
	int y_diff = direction == DOWN ? -1 : direction == UP ? 1 : 0;

	_x = x + x_diff;
	_y = y + y_diff;

	_speedX = x_diff * _speed;
	_speedX = y_diff * _speed;

	_direction = direction;

	_active = _frames;

	_sprite = _appearance[_direction];
}

void WeaponPart::Update(double gameTime)
{
	if( _active > 0 )
	{
		int new_x = _x + _speedX;
		int new_y = _y + _speedY;

		if( GameManager::CanMoveTo( new_x, new_y ) )
		{
			_x = new_x;
			_y = new_y;
		}
		else
		{
			_active = 0;
		}

		GameManager::TryHit(_x,_y);

		GameObject::Update(gameTime);

		_active--;

		if( _active == 0 ) GameObject::Clean();
	}
}

void WeaponPart::Draw()
{
	if( _active > 0 )
	{
		GameObject::Draw();
	}
}