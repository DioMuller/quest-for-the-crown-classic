#pragma once
#include "Console.h"
#include "Enemy.h"
#include "Player.h"
#include <list>
#include "LevelManager.h"

class GameManager
{
	protected:
		//Game initialized
		bool _initialized;
		bool _isRunning;

		bool _success;

		//Time variables
		double _currentTime;

		//Levels
		//TODO: Level Manager
		LevelManager *_manager;

		//Player Reference
		Player* _player;

	public:
		GameManager();
		~GameManager();

	public:
		static void UpdateGame();
		static void DrawGame();
		static void CleanGame();

		static bool IsRunning();
		static WORD GetBackground();
		static void TryHit(int x, int y);
		static void HitPlayer(int x, int y);
		static bool CanMoveTo(int x, int y, bool isProjectile);
		static void ChangeLevel(Direction direction);
		static void EndGame(bool success);
		static bool WasSuccessful();
		static char GetChar(Position position);

		static Position GetPlayerPosition();
		static void SetPlayerPosition(Position position);

		static void GoToDungeon(int dungeon);

		static void AddObject(GameObject* object);
		static void RemoveObject(GameObject* object);
};

