#include "Player.h"
#include "Console.h"
#include "Input.h"
#include "GameManager.h"


Player::Player(int x, int y) : GameObject(x,y)
{
	_direction = DOWN;
	_actionFrames = 0;
}

Player::Player() : GameObject(39,12)
{
	_direction = DOWN;
	_actionFrames = 0;
}

Player::~Player()
{
	//Nothing Else to Do
}

void Player::Update(double gameTime)
{
	//Get keyboard input and update player position.
	if( _actionFrames == 0 )
	{
		char key = Input::GetInput();

		switch (key)
		{
			case KEY_UP:
				_y -= 1;
				_direction = UP;
				break;
			case KEY_DOWN:
				_y += 1;
				_direction = DOWN;
				break;
			case KEY_LEFT:
				_x -= 1;
				_direction = LEFT;
				break;
			case KEY_RIGHT:
				_x += 1;
				_direction = RIGHT;
				break;
			case KEY_ACTION:
				_actionFrames = 15;
				break;
			default:
				break;
		}

		if( _x < 1 ) _x = 1;
		if( _x > 78 ) _x = 78;

		if( _y < 3 ) _y = 3;
		if( _y > 23 ) _y = 23;
	}
	else
	{
		_actionFrames--;
	}
}

void Player::Draw()
{
	WORD color = _actionFrames == 0 ? FOREGROUND_WHITE | FOREGROUND_INTENSITY : FOREGROUND_WHITE;
	int dist = _actionFrames == 0? 1 : 2;

	mostrar(_x, _y, GameManager::GetBackground() | FOREGROUND_WHITE | FOREGROUND_INTENSITY, "@");

	switch (_direction)
	{
		case UP:
			if( _actionFrames > 0 ) mostrar(_x, _y - 1, GameManager::GetBackground() | color, "I");
			mostrar(_x, _y - dist, GameManager::GetBackground() | color, "^");
			break;
		case DOWN:
			if( _actionFrames > 0 ) mostrar(_x, _y + 1, GameManager::GetBackground() | color, "I");
			mostrar(_x, _y + dist, GameManager::GetBackground() | color, "v");
			break;
		case LEFT:
			if( _actionFrames > 0 ) mostrar(_x - 1, _y, GameManager::GetBackground() | color, "-");
			mostrar(_x - dist, _y, GameManager::GetBackground() | color, "<");
			break;
		case RIGHT:
			if( _actionFrames > 0 ) mostrar(_x + 1, _y, GameManager::GetBackground() | color, "-");
			mostrar(_x + dist, _y, GameManager::GetBackground() | color, ">");
			break;
		default:
			break;
	}
}