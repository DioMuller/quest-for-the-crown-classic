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

public:
	LevelManager(Level** levels, int levelCount, LevelManager** dungeons, int dungeonCount);
	~LevelManager();

public:
	void ChangeLevel(Player* player, Direction direction);

	void Update(double gameTime);
	void Draw();
	
	bool CheckXY(int x, int y);
	void TryHit(int x, int y);


	WORD GetLevelBackground();

	void SetParent(LevelManager* parent);
	void InitializeChild();

private:
	Level* GetCurrentLevel();
};

