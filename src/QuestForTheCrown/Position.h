#ifndef __POSITION_H_
#define __POSITION_H_

struct Position
{
	int X;
	int Y;

	Position()
	{
		X = 0;
		Y = 0;
	}

	Position(int x, int y)
	{
		this->X = x;
		this->Y = y;
	}
};

#endif