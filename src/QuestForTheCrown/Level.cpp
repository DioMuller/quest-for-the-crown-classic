#include "Level.h"


Level::Level(char map[LEVEL_HEIGHT][LEVEL_WIDTH], WORD background)
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
				case 'o':
				case '8':
				case 'W':
					_objects.push_back(new Enemy(i, j, (EnemyType) map[i][j]));
					_level[i][j] = ' ';
					break;
				default:
					_level[i][j] = ' ';
					break;
			}
		}
	}

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
			mostrar(0, i + 2, _background | FOREGROUND_WHITE, _level[i]);
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
	return _level[x][y] == ' ';
}

void Level::HitObjects(int x, int y)
{
  	std::list<Enemy*> toRemove;

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
		 _objects.remove((*iterator));
	}
}

int Level::GetNeighbour(Direction direction)
{
	return _neighbours[direction];
}
