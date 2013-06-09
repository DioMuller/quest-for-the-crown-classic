#include "Level.h"
#include "GameManager.h"
#include "Waypoint.h"
#include "WeaponPickup.h"
#include "LifePickup.h"


Level::Level(char map[LEVEL_HEIGHT][LEVEL_WIDTH], int neighbours[4], WORD background)
{
	_background = background;

    _isDungeon = -1;

	for( int i = 0; i < LEVEL_HEIGHT; i++ )
	{
		//Yes, I could use memcpy(_level[i], map[i], LEVEL_WIDTH);
		//But with that way I can check for enemies.
		//Since this will be called only once per game, 
		for( int j = 0; j < LEVEL_WIDTH; j++ )
		{
			switch( map[i][j] )
			{
				case '#':
					_level[i][j] = (char) 219;
					break;
				case '~':
					_level[i][j] = '~';
					break;
				case 'G':
					_level[i][j] = '#';
					break;
                case 'D':
                    _objects.push_back(new WeaponPickup(j, i+2));
                    _level[i][j] = ' ';
                    break;
                case 'L':
                    _level[i][j] = ']';
                    _locks.push_back(Position(j,i));
                    break; 
   				case (char) WORM:
                    _isDungeon = 0;
				case (char) SLIME:
				case (char) GOON:
				case (char) BAT:
				case (char) WIZARD:
					_objects.push_back(new Enemy( j, i + 2, (EnemyType) map[i][j]));
					_level[i][j] = ' ';
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					_objects.push_back(new Waypoint(j, i+2, map[i][j] - '1'));
					_level[i][j] = ' ';
					break;
				default:
					_level[i][j] = ' ';
					break;
			}
		}
	}

	_neighbours[LEFT] = neighbours[LEFT];
	_neighbours[UP] = neighbours[UP];
	_neighbours[RIGHT] = neighbours[RIGHT];
	_neighbours[DOWN] = neighbours[DOWN];


	_redraw = true;
}

Level::~Level()
{
}

void Level::Draw()
{
	if( _redraw )
	{
		for( int i = 0; i < LEVEL_HEIGHT; i++ )
		{
			if( _level[i][0] == '~' )
			{
				mostrar(0, i + 2, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_INTENSITY, _level[i]);
			}
			else
			{
				mostrar(0, i + 2, _background | FOREGROUND_WHITE, _level[i]);
			}
		}

		_redraw = false;
	}

	for( std::list<GameObject*>::iterator iterator = _objects.begin(); iterator != _objects.end(); iterator++  )
	{
		(*iterator)->Draw();
	}
}

void Level::Update(double gameTime)
{
    if( _redraw )
    {
        if( GameManager::GetDungeonFinished(0) )
        {
            std::list<Position>::iterator iterator;
            std::list<Position> toRemove;

            for( iterator = _locks.begin(); iterator != _locks.end(); iterator++ )
            {
                _level[(*iterator).Y][(*iterator).X] = ' ';

                toRemove.push_back((*iterator));
            }

            for( iterator = toRemove.begin(); iterator != toRemove.end(); iterator++ )
            {
                _locks.push_back((*iterator));
            }
        }
    }

	std::list<GameObject*>::iterator iterator;
	for( iterator = _toRemove.begin(); iterator != _toRemove.end(); iterator++ )
	{
		_objects.remove((*iterator));
	}

	for( iterator = _objects.begin(); iterator != _objects.end(); iterator++  )
	{
		(*iterator)->Update(gameTime);
	}
}

bool Level::CheckXY(int x, int y, bool isProjectile)
{
	return !HasObject(Position(x,y)) && (_level[y-2][x] == ' ' || ( isProjectile && _level[y-2][x] == '#' ));
}

void Level::HitObjects(int x, int y)
{
  	std::list<Enemy*> toRemove;
	bool finish = false;

	for( std::list<GameObject*>::iterator iterator = _objects.begin();  iterator !=  _objects.end();  iterator++  )
	{
		Enemy* obj = (Enemy*) (* iterator);

		if( obj != NULL )
		{
			if( obj->CollidesWith(x,y) )
			{
				toRemove.push_back(obj);
			}
		}
	}

    if( toRemove.size() != 0 && _isDungeon == -1 )
    {
        if( rand() % 3 == 1 )
        {
            _objects.push_front( new LifePickup( x, y ) );
        }
    }

	for( std::list<Enemy*>::iterator iterator = toRemove.begin(); iterator != toRemove.end(); iterator++ )
	{
		if( (*iterator)->GetType() == WIZARD ) finish = true;

		_objects.remove((*iterator));

		delete (Enemy*) (*iterator);
	}

    if( _isDungeon != -1 && _objects.size() == 0 )
    {
        GameManager::FinishDungeon(_isDungeon);
        GameManager::AddPlayerHealth();
        GameManager::HealPlayer();
        GameManager::ReturnToEntrance();
    }

	if( finish ) GameManager::EndGame(true);
}

int Level::GetNeighbour(Direction direction)
{
	return _neighbours[direction];
}

void Level::SetNeighbours(int north, int east, int south, int west)
{
	_neighbours[UP] = north;
	_neighbours[RIGHT] = east;
	_neighbours[DOWN] = south;
	_neighbours[LEFT] = west;
}

void Level::ResetDraw()
{
	_redraw = true;
}

WORD Level::GetBackground()
{
	return _background;
}

void Level::AddObject(GameObject* object)
{
	_objects.push_front(object);
}

void Level::RemoveObject(GameObject* object)
{
	_toRemove.push_front(object);
	//delete object;
}

void Level::CleanObjects()
{
	for( std::list<GameObject*>::iterator iterator = _objects.begin();  iterator !=  _objects.end();  iterator++  )
	{
		(*iterator)->Clean();
	}
}

char Level::GetChar(Position position)
{
	return _level[position.Y - 2][position.X];
}

bool Level::HasObject(Position position)
{
	std::list<Enemy*> toRemove;
	bool finish = false;

	for( std::list<GameObject*>::iterator iterator = _objects.begin();  iterator !=  _objects.end();  iterator++  )
	{
		GameObject* obj = (*iterator);

		if( obj != NULL && ((Player*) obj == NULL) )
		{
			if( obj->CollidesWith(position.X, position.Y) )
			{
				return true;
			}
		}
	}

	return false;
}