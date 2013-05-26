#include "GameManager.h"
#include "Helpers.h"

GameManager instance;

GameManager::GameManager()
{
	_player = Player(10,10);

	_background = BACKGROUND_GREEN;

	_enemies.push_back(Enemy(15, 15, 15));
	_enemies.push_back(Enemy(12, 19, 15));
	_enemies.push_back(Enemy(70, 5, 15));
	_enemies.push_back(Enemy(2, 2, 15));
	_enemies.push_back(Enemy(49, 21, 15));
	_enemies.push_back(Enemy(5, 20, 15));
	_enemies.push_back(Enemy(15, 23, 15));

	//Debug Valiables
	#ifdef _DEBUG 
	_fpsLast = current_time();
	_currentFPS = 0;
	_frameCount = 0;
	#endif

	_isRunning = true;
	_initialized = true;
}

GameManager::~GameManager()
{
	//Nothing else to do.
}

void GameManager::UpdateGame()
{
		_currentTime = current_time();

		//For each Game Object -> Update
		_player.Update(_currentTime);

		for( _iterator = _enemies.begin(); _iterator != _enemies.end(); _iterator++  )
		{
			(*_iterator).Update(_currentTime);
		}

		//Show debug options
		#ifdef _DEBUG
		_currentTime = current_time();

		if( _currentTime - _fpsLast > 1000.0 )
		{
			_fpsLast = _currentTime;
			_currentFPS = _frameCount;
			_frameCount = 0;
		}

		_frameCount++;
		#endif
}

void GameManager::DrawGame()
{
		//Clear Screen
		clrscr(_background);

		//For each Game Object -> Draw
		_player.Draw();

		for( _iterator = _enemies.begin(); _iterator != _enemies.end(); _iterator++  )
		{
			(*_iterator).Draw();
		}
		
		//Draw debug data the GUI
		#ifdef _DEBUG
		mostrar ( 70, 0, FOREGROUND_WHITE, "DEBUG MODE" );
		mostrar ( 70, 1, FOREGROUND_WHITE, "FPS: " );
		mostrar ( 75, 1, FOREGROUND_WHITE, (long) _currentFPS );
		#endif

		//Draw GUI Bar
		mostrar(0,0,FOREGROUND_WHITE, "                                                                                ");
		mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");
}

bool GameManager::IsRunning()
{
	return _initialized && _isRunning;
}

WORD GameManager::GetBackground()
{
	return instance._background;
}

GameManager GameManager::GetInstance()
{
	return (instance);
}