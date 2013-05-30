#include "Player.h"
#include "Console.h"
#include "Input.h"
#include "GameManager.h"


Player::Player(int x, int y) : GameObject(x,y)
{
	_actionFrames = 0;

	_totalHealth = 3;
	_currentHealth = 3;

	_invencibleTime = 30;

	_sprite = "@";
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

		int new_x = _x;
		int new_y = _y;

		switch (key)
		{
			case KEY_UP:
				new_y -= 1;
				break;
			case KEY_DOWN:
				new_y += 1;
				break;
			case KEY_LEFT:
				new_x -= 1;
				break;
			case KEY_RIGHT:
				new_x += 1;
				break;
			case KEY_ACTION:
				_actionFrames = 15;
				break;
			default:
				break;
		}

		if( GameManager::CanMoveTo(new_x, new_y) )
		{
			_x = new_x;
			_y = new_y;

			if( _x == 0 ) GameManager::ChangeLevel(LEFT);
			if( _x == 79 ) GameManager::ChangeLevel(RIGHT);
			if( _y == 2 ) GameManager::ChangeLevel(UP);
			if( _y == 24 ) GameManager::ChangeLevel(DOWN);
		}
	}
	else
	{
		_actionFrames--;
	}

	GameObject::Update(gameTime);
}

void Player::Draw()
{
	_color = ((_invencibleTime <= 0) ? FOREGROUND_WHITE : FOREGROUND_YELLOW) | FOREGROUND_INTENSITY;
	WORD color = _actionFrames == 0 ? FOREGROUND_WHITE : _color;
	int dist = _actionFrames == 0? 1 : 3;

	GameObject::Draw();
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

void Player::SetX( int pos )
{
	_x = pos;
}

void Player::SetY( int pos )
{
	_y = pos;
}