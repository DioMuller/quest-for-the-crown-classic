#include "Player.h"
#include "Console.h"


Player::Player(int x, int y) : GameObject(x,y)
{
	//Nothing Else to Do
}


Player::~Player()
{
	//Nothing Else to Do
}

void Player::Update(double gameTime)
{
	//Get keyboard input and update player position.
}

void Player::Draw()
{
	mostrar(_x, _y, BACKGROUND_CYAN | FOREGROUND_WHITE | FOREGROUND_INTENSITY, "@");
}