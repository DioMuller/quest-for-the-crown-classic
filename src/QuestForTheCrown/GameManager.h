#pragma once
#include "Console.h"
#include "Enemy.h"
#include "Player.h"
#include <list>
#include "LevelManager.h"
#include "Definitions.h"

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

        bool _dungeonsDone[DUNGEONS];

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
        static void AddPlayerWeapon();
        static void HealPlayer();
        static void AddPlayerHealth();
        static int GetAmmo(WeaponType weapon);
        static void AddAmmo(WeaponType weapon, int toAdd);
        static bool HasWeapon(WeaponType weapon);

        static void ReturnToEntrance();

		static void ResetGame();

		static void GoToDungeon(int dungeon);

		static void AddObject(GameObject* object);
		static void RemoveObject(GameObject* object);

        static void FinishDungeon(int x);
        static bool GetDungeonFinished(int x);

	private:
		void InitializeMaps();
};

