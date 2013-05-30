#include "Player.h"
#include "Console.h"
#include "Input.h"
#include "GameManager.h"


Player::Player(int x, int y) : GameObject(x,y)
{
	_direction = DOWN;
	_actionFrames = 0;

	_totalHealth = 3;
	_currentHealth = 3;

	_invencibleTime = 30;
}

Player::~Player()
{
	//Nothing Else to Do
}

void Player::Update(double gameTime)
{
	if( _invencibleTime > 0 ) _invencibleTime--;

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
		switch (_direction)
		{
		case UP:
			GameManager::TryHit(_x, _y - 1);
			GameManager::TryHit(_x, _y - 2);
			GameManager::TryHit(_x, _y - 3);
			break;
		case DOWN:
			GameManager::TryHit(_x, _y + 1);
			GameManager::TryHit(_x, _y + 2);
			GameManager::TryHit(_x, _y + 3);
			break;
		case LEFT:
			GameManager::TryHit(_x - 1, _y);
			GameManager::TryHit(_x - 2, _y);
			GameManager::TryHit(_x - 3, _y);
			break;
		case RIGHT:
			GameManager::TryHit(_x + 1, _y);
			GameManager::TryHit(_x + 2, _y);
			GameManager::TryHit(_x + 3, _y);
			break;
		default:
			break;
		}



		_actionFrames--;
	}

	GameObject::Update(gameTime);
}

void Player::Draw()
{
	_color = ((_invencibleTime <= 0) ? FOREGROUND_WHITE : FOREGROUND_YELLOW) | FOREGROUND_INTENSITY;
	WORD color = _actionFrames == 0 ? FOREGROUND_WHITE : _color;
	int dist = _actionFrames == 0? 1 : 3;

	mostrar(_x, _y, GameManager::GetBackground() | _color, "@");

	switch (_direction)
	{
		case UP:
			if( _actionFrames > 0 ) mostrar(_x, _y - 1, GameManager::GetBackground() | color, "I");
			if( _actionFrames > 0 ) mostrar(_x, _y - 2, GameManager::GetBackground() | color, "I");
			mostrar(_x, _y - dist, GameManager::GetBackground() | color, "^");
			break;
		case DOWN:
			if( _actionFrames > 0 ) mostrar(_x, _y + 1, GameManager::GetBackground() | color, "I");
			if( _actionFrames > 0 ) mostrar(_x, _y + 2, GameManager::GetBackground() | color, "I");
			mostrar(_x, _y + dist, GameManager::GetBackground() | color, "v");
			break;
		case LEFT:
			if( _actionFrames > 0 ) mostrar(_x - 1, _y, GameManager::GetBackground() | color, "--");
			mostrar(_x - dist, _y, GameManager::GetBackground() | color, "<");
			break;
		case RIGHT:
			if( _actionFrames > 0 ) mostrar(_x + 1, _y, GameManager::GetBackground() | color, "--");
			mostrar(_x + dist, _y, GameManager::GetBackground() | color, ">");
			break;
		default:
			break;
	}
}

void Player::Hit()
{
	if( _invencibleTime <= 0 )
	{
		_currentHealth --;
		_invencibleTime = 30;

		if( _currentHealth <= 0 )
		{
			GameManager::EndGame();
		}
	}
}

int Player::GetTotalHealth()
{
	return _totalHealth;
}

int Player::GetCurrentHealth()
{
	return _currentHealth;
}