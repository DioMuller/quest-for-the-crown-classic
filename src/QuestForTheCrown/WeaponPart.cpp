#include "WeaponPart.h"
#include "GameManager.h"


WeaponPart::WeaponPart(int x, int y, char* appearance[4], int speed, int frames, bool isProjectile, bool isEnemy) : GameObject(x,y)
{
	for( int i = 0; i < 4; i++ )
	{
		_appearance[i] = appearance[i];
	}

	_speed = speed;
	_frames = frames;

	_color = isEnemy? (FOREGROUND_RED | FOREGROUND_INTENSITY) : FOREGROUND_WHITE;

	_active = 0;
	_isProjectile = isProjectile;
	_isEnemy = isEnemy;
}

WeaponPart::WeaponPart(WeaponPart* toClone) : GameObject( toClone->_position.X, toClone->_position.Y) 
{
	for( int i = 0; i < 4; i++ )
	{
		this->_appearance[i] = toClone->_appearance[i];
	}
	
	this->_speed = toClone->_speed;
	this->_frames = toClone->_frames;

	_color = toClone->_isEnemy? (FOREGROUND_RED | FOREGROUND_INTENSITY) : FOREGROUND_WHITE;
	_isProjectile = toClone->_isProjectile;
	_isEnemy = toClone->_isEnemy;

	_active = 0;
}

WeaponPart::~WeaponPart()
{
}
	
void WeaponPart::Show(int x, int y, Direction direction)
{
	int x_diff = direction == LEFT ? -1 : direction == RIGHT ? 1 : 0;
	int y_diff = direction == DOWN ? -1 : direction == UP ? 1 : 0;

	_position.X = x + x_diff;
	_position.Y = y + y_diff;

	_speedX = x_diff * _speed;
	_speedY = y_diff * _speed;

	_direction = direction;

	_active = _frames;

	_sprite = _appearance[_direction];
}

void WeaponPart::Update(double gameTime)
{
	if( _active > 0 )
	{
		GameObject::Update(gameTime);

		int new_x = _position.X + _speedX;
		int new_y = _position.Y + _speedY;

		if( GameManager::CanMoveTo( new_x, new_y, _isProjectile ) )
		{
			_position.X = new_x;
			_position.Y = new_y;
		}
		else
		{
			_active = 0;

			if( _isProjectile )
			{
				GameManager::RemoveObject(this);
			}
		}

		if( _isEnemy )
		{
			GameManager::HitPlayer(_position.X, _position.Y);
		}
		else
		{
			GameManager::TryHit(_position.X,_position.Y);
		}

		_active--;

		if( _active == 0 )
		{
			Clean();
			mostrar(_position.X, _position.Y, GameManager::GetBackground(), " ");
		}
	}
}

void WeaponPart::Draw()
{
	if( _active > 0 )
	{
		GameObject::Draw();
	}
}

void WeaponPart::Hide()
{
	_active = 0;
}