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
	std::list<GameObject*> _toRemove;
	WORD _background;
	char _level[LEVEL_HEIGHT][LEVEL_WIDTH];
	int _neighbours[4];
	bool _redraw;
    std::list<Position> _locks;

    int _isDungeon;

public:
	Level(char map[LEVEL_HEIGHT][LEVEL_WIDTH], int neighbours[4], WORD background);
	~Level();

public:
	void Draw();
	void Update(double gameTime);
	void CleanObjects();

	bool CheckXY(int x, int y, bool isProjectile);
	void HitObjects(int x, int y);
	int GetNeighbour(Direction direction);
	void SetNeighbours(int north, int east, int south, int west);
	void ResetDraw();
	WORD GetBackground();
	char GetChar(Position position);
	bool HasObject(Position position);

	void AddObject(GameObject* object);
	void RemoveObject(GameObject* object);
};

