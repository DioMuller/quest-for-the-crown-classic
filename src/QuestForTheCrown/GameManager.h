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
		std::list<GameObject*> _objects;
		std::list<GameObject*>::iterator _iterator;
		
		Player* _player;

	public:
		GameManager();
		~GameManager();

	public:
		static void UpdateGame();
		static void DrawGame();

		static bool IsRunning();
		static WORD GetBackground();
		static void TryHit(int x, int y);
		static void HitPlayer(int x, int y);

		static void EndGame();
};

