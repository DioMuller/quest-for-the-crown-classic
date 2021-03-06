﻿#include "Player.h"
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

    _totalWeapons = 1;

	_sprite = "@";

	char* swordHolder[4] = {"=", "I", "=", "I"};
	char* swordPoint[4] = {"<", "v", ">", "^"};

	char* bowHolder[4] = {"(", "v", ")", "^"};
	char* bowArrow[4] = {"-", "|", "-", "|"};

	_weapons[SWORD] = new Weapon(x, y, swordHolder, swordPoint, 0, 15);
	_weapons[BOW] = new Weapon(x,y, bowHolder, bowArrow, 1, 15);

	_currentWeapon = SWORD;

	_forcedraw = true;
    _updateGUI = true;
}

Player::~Player()
{
	for( int i = 0; i < NUM_WEAPONS; i++ )
		delete _weapons[i];
}

void Player::Update(double gameTime)
{
	if( _invencibleTime > 0 ) _invencibleTime--;

	//Get keyboard input and update player position.
	if( _actionFrames == 0 && _movementDelayTime == 0 )
	{
		char key = Input::GetInput();

		int new_x = _position.X;
		int new_y = _position.Y;

		int weapon = (int) _currentWeapon;

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
				_weapons[_currentWeapon]->Show(_position.X,_position.Y, LEFT );
				_actionFrames = 15;
                SetUpdateGui(true);
				break;
			case KEY_UP_ACTION:
				_weapons[_currentWeapon]->Show(_position.X,_position.Y, UP );
				_actionFrames = 15;
                SetUpdateGui(true);
				break;
			case KEY_RIGHT_ACTION:
				_weapons[_currentWeapon]->Show(_position.X,_position.Y, RIGHT );
				_actionFrames = 15;
                SetUpdateGui(true);
				break;
			case KEY_DOWN_ACTION:
				_weapons[_currentWeapon]->Show(_position.X,_position.Y, DOWN );
				_actionFrames = 15;
                SetUpdateGui(true);
				break;
			case KEY_NEXT_WEAPON:
				if(  weapon != (_totalWeapons - 1) )
				{
					_currentWeapon = (WeaponType) (weapon+1);
                    SetUpdateGui(true);
				}
				break;
			case KEY_PREV_WEAPON:
				if(  weapon != 0 )
				{
					_currentWeapon = (WeaponType) (weapon-1);
                    SetUpdateGui(true);
				}
				break;
			default:
				break;
		}

		if( new_x != _position.X || new_y != _position.Y )
		{
			if( GameManager::CanMoveTo(new_x, new_y, false) )
			{
				_position.X = new_x;
				_position.Y = new_y;

				if( _position.X == 0 ) GameManager::ChangeLevel(LEFT);
				if( _position.X == 79 ) GameManager::ChangeLevel(RIGHT);
				if( _position.Y == 2 ) GameManager::ChangeLevel(UP);
				if( _position.Y == 24 ) GameManager::ChangeLevel(DOWN);

				_movementDelayTime = MOVE_DELAY;
			}
		}
	}
	else
	{
		if( _actionFrames > 0 ) _actionFrames--;
		if( _movementDelayTime > 0 ) _movementDelayTime--;
	}

	_weapons[_currentWeapon]->Update(gameTime);

	GameObject::Update(gameTime);
}

void Player::Draw()
{
	_color = ((_invencibleTime <= 0) ? FOREGROUND_WHITE : FOREGROUND_YELLOW) | FOREGROUND_INTENSITY;
	WORD color = _actionFrames == 0 ? FOREGROUND_WHITE : _color;
	int dist = _actionFrames == 0? 1 : 3;

	_weapons[_currentWeapon]->Draw();

	GameObject::Draw();
}

void Player::Hit()
{
	if( _invencibleTime <= 0 )
	{
        Input::Rumble(100);
		_currentHealth --;
		_invencibleTime = 60;
        SetUpdateGui(true);

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
	_position.X = pos;
}

void Player::SetY( int pos )
{
	_position.Y = pos;
}

WeaponType Player::GetCurrentWeapon()
{
	return _currentWeapon;
}

void Player::AddWeapon()
{
    _totalWeapons++;

    if( _totalWeapons > NUM_WEAPONS ) _totalWeapons = NUM_WEAPONS;

    SetUpdateGui(true);
}

bool Player::HasWeapon(WeaponType type)
{
    return (_totalWeapons - 1) >= ((int) type);
}

void Player::RestoreHealth()
{
    if( _currentHealth < _totalHealth ) _currentHealth++;
    SetUpdateGui(true);
}
void Player::UpgradeHealth()
{
    _totalHealth++;
    SetUpdateGui(true);
}

int Player::GetAmmo(WeaponType weapon)
{
    return _weapons[weapon]->GetAmmo();
}

void Player::AddAmmo(WeaponType weapon, int toAdd)
{
    _weapons[weapon]->AddAmmo(toAdd);
    SetUpdateGui(true);
}

bool Player::GetUpdateGui()
{
    return _updateGUI;
}

void Player::SetUpdateGui(bool value)
{
    _updateGUI = value;
}