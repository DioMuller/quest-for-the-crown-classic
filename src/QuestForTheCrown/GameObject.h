#pragma once
#include "Console.h"
#include "Position.h"

class GameObject
{
	//Attributes
	protected:
		Position _position;
		Position _oldPosition;

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

		Position GetPosition();

		bool CollidesWith(int x, int y);
};