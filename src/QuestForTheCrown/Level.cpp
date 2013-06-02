#include "Level.h"
#include "GameManager.h"


Level::Level(char map[LEVEL_HEIGHT][LEVEL_WIDTH], int neighbours[4], WORD background)
{
	_background = background;

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
				case (char) SLIME:
				case (char) GOON:
				case (char) BAT:
				case (char) WORM:
				case (char) WIZARD:
					_objects.push_back(new Enemy( j, i + 2, (EnemyType) map[i][j]));
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
	for( std::list<GameObject*>::iterator iterator = _objects.begin(); iterator != _objects.end(); iterator++  )
	{
		(*iterator)->Update(gameTime);
	}
}

bool Level::CheckXY(int x, int y)
{
	return _level[y-2][x] == ' ';
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

	for( std::list<Enemy*>::iterator iterator = toRemove.begin(); iterator != toRemove.end(); iterator++ )
	{
		if( (*iterator)->GetType() == WIZARD ) finish = true;

		_objects.remove((*iterator));

		delete (Enemy*) (*iterator);
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