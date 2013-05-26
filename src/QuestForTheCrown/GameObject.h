#pragma once

class GameObject
{
	//Attributes
	protected:
		int _x;
		int _y;

	public:
		GameObject(int x, int y);
		~GameObject();

	public:
		virtual void Update(double gameTime);
		virtual void Draw();

		bool CollidesWith(int x, int y);
};