#include "GameObject.h"
#include "Console.h"
#include "GameManager.h"

GameObject::GameObject(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->_drawn = false;

	_forcedraw = false;
}

GameObject::~GameObject()
{
	//Nothing else to do.
}

void GameObject::Update(double gameTime)
{
	if( _drawn && (_x != _old_x || _y != _old_y) )
	{
		if( _forcedraw ) Clean();
		_old_x = _x;
		_old_y = _y;

		_drawn = false;
	}
}

void GameObject::Draw()
{
	if( _x != _old_x || _y != _old_y || _forcedraw ) 
	{
		Clean();

		mostrar(_x, _y, _color | GameManager::GetBackground(), _sprite);

		_drawn = true;
	}
}

void GameObject::Clean()
{
	if( _old_x != _x || _old_y != _y || _forcedraw )
	{
		mostrar(_old_x, _old_y, GameManager::GetBackground(), " ");
		if( _forcedraw ) mostrar(_x, _y, GameManager::GetBackground(), " ");
	}
}

bool GameObject::CollidesWith(int x, int y)
{
	return (_x == x) && (_y == y);
}

int GameObject::GetX()
{
	return _x;
}

int GameObject::GetY()
{
	return _y;
}