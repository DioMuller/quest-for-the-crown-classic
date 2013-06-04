#pragma once
#include "Level.h"
#include "Player.h"

class LevelManager
{
private:
	Level** _levels;
	LevelManager** _dungeons;
	LevelManager* _parent;

	int _currentLevel;
	int _currentDungeon;

	int _levelCount;
	int _dungeonCount;

	Position _startPoint;

	Position _oldPoint;

public:
	LevelManager(Level** levels, int levelCount, LevelManager** dungeons, int dungeonCount, Position startPoint);
	~LevelManager();

public:
	void ChangeLevel(Player* player, Direction direction);

	void Update(double gameTime);
	void Draw();
	void Clean();
	
	bool CheckXY(int x, int y, bool isProjectile);
	char GetChar(Position position);
	bool HasObject(Position position);
	void TryHit(int x, int y);


	WORD GetLevelBackground();
	Position GetStart();

	void SetParent(LevelManager* parent);
	void InitializeChildren();

	void GoToDungeon(int id);
	void BackToMap();

	void AddObject(GameObject* object);
	void RemoveObject(GameObject* object);
private:
	Level* GetCurrentLevel();
	void SetCurrentLevel(int level);
};

