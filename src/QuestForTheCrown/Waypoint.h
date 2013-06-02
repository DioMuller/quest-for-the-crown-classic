#pragma once
#include "gameobject.h"

class Waypoint : public GameObject
{
	private:
		int _id;
	public:
		Waypoint(int x, int y, int id);
		~Waypoint();
	public:
		void Update(double gameTime);
};

