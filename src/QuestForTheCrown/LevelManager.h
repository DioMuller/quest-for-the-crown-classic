#pragma once
#include "Level.h"
#include "Player.h"

class LevelManager
{
private:
	Level** _levels;
	int _currentLevel;

public:
	LevelManager();
	~LevelManager();

public:
	void ChangeLevel(Player* player, Direction direction);

	void Update(double gameTime);
	void Draw();
	bool CheckXY(int x, int y);
	WORD GetLevelBackground();

private:
	Level* GetCurrentLevel();
};

