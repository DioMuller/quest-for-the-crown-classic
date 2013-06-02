#include "GameObject.h"
#include "Console.h"
#include "GameManager.h"

GameObject::GameObject(int x, int y)
{
	this->_position.X = x;
	this->_position.Y = y;
	this->_drawn = false;

	_forcedraw = false;
}

GameObject::~GameObject()
{
	//Nothing else to do.
}

void GameObject::Update(double gameTime)
{
	if( _drawn && (_position.X != _oldPosition.X || _position.Y != _oldPosition.Y) )
	{
		if( _forcedraw ) Clean();
		_oldPosition.X = _position.X;
		_oldPosition.Y = _position.Y;

		_drawn = false;
	}
}

void GameObject::Draw()
{
	if( _position.X != _oldPosition.X || _position.Y != _oldPosition.Y || _forcedraw ) 
	{
		Clean();

		mostrar(_position.X, _position.Y, _color | GameManager::GetBackground(), _sprite);

		_drawn = true;
	}
}

void GameObject::Clean()
{
	if( _oldPosition.X != _position.X || _oldPosition.Y != _position.Y || _forcedraw )
	{
		mostrar(_oldPosition.X, _oldPosition.Y, GameManager::GetBackground(), " ");
		if( _forcedraw ) mostrar(_position.X, _position.Y, GameManager::GetBackground(), " ");
	}
}

bool GameObject::CollidesWith(int x, int y)
{
	return (_position.X == x) && (_position.Y == y);
}

Position GameObject::GetPosition()
{
	return _position;
}