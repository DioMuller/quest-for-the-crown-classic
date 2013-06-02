#include "Waypoint.h"
#include "GameManager.h"


Waypoint::Waypoint(int x, int y, int id) : GameObject(x,y)
{
	_id = id;

	_sprite = new char[2];
	_sprite[0] = (char) 219;
	_sprite[1] = '\0';

	_color = 0;
}


Waypoint::~Waypoint(void)
{
	//Nothing else to do.
}

void Waypoint::Update(double gameTime)
{
	Position player = GameManager::GetPlayerPosition();
	if( CollidesWith(player.X, player.Y) )
	{
		GameManager::GoToDungeon(_id);
	}
}