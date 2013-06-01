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

	_movementDelayTime = 0;

	_sprite = "@";

	char* swordHolder[4] = {"=", "I", "=", "I"};
	char* swordPoint[4] = {"<", "v", ">", "^"};

	_sword = new Weapon(x, y, swordHolder, swordPoint, 0, 15);

	_forcedraw = true;
}

Player::~Player()
{
	delete _sword;
}

void Player::Update(double gameTime)
{
	if( _invencibleTime > 0 ) _invencibleTime--;

	//Get keyboard input and update player position.
	if( _actionFrames == 0 && _movementDelayTime == 0 )
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
			case KEY_LEFT_ACTION:
				_sword->Show(_x,_y, LEFT );
				_actionFrames = 15;
				break;
			case KEY_UP_ACTION:
				_sword->Show(_x,_y, UP );
				_actionFrames = 15;
				break;
			case KEY_RIGHT_ACTION:
				_sword->Show(_x,_y, RIGHT );
				_actionFrames = 15;
				break;
			case KEY_DOWN_ACTION:
				_sword->Show(_x,_y, DOWN );
				_actionFrames = 15;
				break;
			default:
				break;
		}

		if( new_x != _x || new_y != _y )
		{
			if( GameManager::CanMoveTo(new_x, new_y) )
			{
				_x = new_x;
				_y = new_y;

				if( _x == 0 ) GameManager::ChangeLevel(LEFT);
				if( _x == 79 ) GameManager::ChangeLevel(RIGHT);
				if( _y == 2 ) GameManager::ChangeLevel(UP);
				if( _y == 24 ) GameManager::ChangeLevel(DOWN);

				_movementDelayTime = MOVE_DELAY;
			}
		}
	}
	else
	{
		if( _actionFrames > 0 ) _actionFrames--;
		if( _movementDelayTime > 0 ) _movementDelayTime--;
	}

	_sword->Update(gameTime);

	GameObject::Update(gameTime);
}

void Player::Draw()
{
	_color = ((_invencibleTime <= 0) ? FOREGROUND_WHITE : FOREGROUND_YELLOW) | FOREGROUND_INTENSITY;
	WORD color = _actionFrames == 0 ? FOREGROUND_WHITE : _color;
	int dist = _actionFrames == 0? 1 : 3;

	_sword->Draw();

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
			GameManager::EndGame(false);
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