#pragma once
#include "Console.h"

class GameObject
{
	//Attributes
	protected:
		int _x;
		int _y;

		int _old_x;
		int _old_y;

		bool _drawn;

		char* _sprite;
		WORD _color;

		bool _forcedraw;
	public:
		GameObject(int x, int y);
		~GameObject();

	public:
		virtual void Update(double gameTime);
		virtual void Draw();
		virtual void Clean();

		int GetX();
		int GetY();

		bool CollidesWith(int x, int y);
};