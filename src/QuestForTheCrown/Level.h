#pragma once
#include "Enum.h"
#include "Console.h"
#include "Enemy.h"
#include <list>

#define LEVEL_WIDTH 81 //80 Characters + '\0';
#define LEVEL_HEIGHT 23

class Level
{
private:
	std::list<GameObject*> _objects;
	WORD _background;
	char _level[LEVEL_HEIGHT][LEVEL_WIDTH];
	int _neighbours[4];
	bool _redraw;

public:
	Level(char map[LEVEL_HEIGHT][LEVEL_WIDTH], WORD background);
	~Level();

public:
	void Draw();
	void Update(double gameTime);

	bool CheckXY(int x, int y);
	void HitObjects(int x, int y);
	int GetNeighbour(Direction direction);
};

