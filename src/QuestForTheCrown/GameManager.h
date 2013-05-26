#pragma once
#include "Console.h"
#include "Enemy.h"
#include "Player.h"
#include <list>

class GameManager
{
	protected:
		//Game initialized
		bool _initialized;
		bool _isRunning;

		//Color variables
		WORD _background;

		//Time variables
		double _currentTime;

		//Game objects
		std::list<Enemy> _enemies;
		std::list<Enemy>::iterator _iterator;

		Player _player;

		//Debug attributes
		#ifdef _DEBUG 
		double _fpsLast;
		int _currentFPS;
		int _frameCount;
		#endif

	public:
		GameManager();
		~GameManager();

	public:
		void UpdateGame();
		void DrawGame();

		bool IsRunning();

	public:
		static WORD GetBackground();
		static GameManager GetInstance();
};

