#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include "Enemy.h"
#include "GameManager.h"
#include "Helpers.h"
#include "Definitions.h"

char* enemyArrows[4] = {"-", "|", "-", "|"};

Enemy::Enemy(int x, int y, EnemyType type) : GameObject(x,y)
{
	int moveCount = 0;
	_type = type;

	switch (_type)
	{
		case SLIME:
			moveCount = 15;
			break;
		case GOON:
			moveCount = 15;
			break;
		case BAT:
			moveCount = 10;
			break;
		case WORM:
			moveCount = 5;
			break;
		case WIZARD:
			moveCount = 150;
			break;
		default:
			break;
	}

	_color = FOREGROUND_RED | FOREGROUND_INTENSITY;

	_sprite = new char[2];
	_sprite[0] = _type;
	_sprite[1] = '\0';

	_moveCount = moveCount;
	_nextMovement = moveCount;

	_direction = LEFT;

	_timeUntilNextAttack = 0;

	//Initialize Weapon
	if( _type == GOON )
	{
		_weapon = new WeaponPart( _position.X, _position.Y, enemyArrows, 1, INDEFINITE, true, true );
	}
	else
	{
		_weapon = NULL;
	}
}


Enemy::~Enemy()
{
	//Nothing else to do.
}

void Enemy::Update(double gameTime)
{
	_nextMovement--;
	double moved = false; //To be used by enemies with patterns

	Position player = GameManager::GetPlayerPosition();
	int diff_x = player.X - _position.X;
	int diff_y = player.Y - _position.Y;

	if( _nextMovement <= 0 )
	{
		int new_x = _position.X;
		int new_y = _position.Y;

		switch (_type)
		{
			case SLIME:
				new_x = _position.X + (rand() % 3) - 1; //-1, 0, 1
				new_y = _position.Y + (rand() % 3) - 1; //-1, 0, 1
				break;
			case GOON:
			case BAT:
				if( abs(diff_x) >= abs(diff_y) )
				{
					if( diff_x < 0 ) new_x--; //If less, but not equal to zero
					else if (diff_x > 0 ) new_x++; //If more, but not equal to zero
				}
				else
				{
					if( diff_y < 0 ) new_y--; //If less, but not equal to zero
					else if (diff_y > 0 ) new_y++; //If more, but not equal to zero
				}
				break;
			case WORM:
				do
				{
					switch (_direction)
					{
						case UP:
							new_y--;
							break;
						case DOWN:
							new_y++;
							break;
						case LEFT:
							new_x--;
							break;
						case RIGHT:
							new_x++;
							break;
						default:
							break;
					}

					if( !GameManager::CanMoveTo(new_x, new_y, false) )
					{
						new_x = _position.X;
						new_y = _position.Y;

						switch( _direction )
						{
							case LEFT:
								_direction = UP;
								break;
							case UP:
								_direction = RIGHT;
								break;
							case RIGHT:
								_direction = DOWN;
								break;
							case DOWN:
								_direction = LEFT;
								break;
						}
					}
					else
					{
						moved = true;
					}
				} 
				while( !moved );
				break;
			case WIZARD:
				do
				{
					new_x = rand() % 80;
					new_y = rand() % 25;
				} 
				while( !GameManager::CanMoveTo(new_x, new_y, false) );
				break;
			default:
				break;
		}

		
		if( GameManager::CanMoveTo(new_x, new_y, false ) )
		{
			_position.X = new_x;
			_position.Y = new_y;
		}

		//Attack
		if( _weapon != NULL )
		{
			if( _timeUntilNextAttack > 0 ) 
			{
				_timeUntilNextAttack--;
			}
			else
			{
				if( _position.X == player.X )
				{
					_timeUntilNextAttack = ATTACK_DELAY;

					GameManager::AddObject( _weapon );
					_weapon->Show(_position.X, _position.Y, (player.Y > _position.Y) ? DOWN : UP);
				}
				else if( _position.Y == player.Y )
				{
					_timeUntilNextAttack = ATTACK_DELAY;

					GameManager::AddObject( _weapon );
     				_weapon->Show(_position.X, _position.Y, (player.X > _position.X) ? RIGHT : LEFT);
				}


			}
		}

		_nextMovement = _moveCount;
	}

	GameManager::HitPlayer(_position.X,_position.Y);
	GameObject::Update(gameTime);
}

EnemyType Enemy::GetType()
{
	return _type;
}