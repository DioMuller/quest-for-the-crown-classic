#include "GameObject.h"

GameObject::GameObject(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

GameObject::~GameObject()
{
	//Nothing else to do.
}

void GameObject::Update(double gameTime){}
void GameObject::Draw(){}