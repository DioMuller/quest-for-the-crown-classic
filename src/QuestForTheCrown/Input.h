#pragma once

#include <conio.h>

#define KEY_NONE '\0'
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ACTION ' '

class Input
{
	public:
		static char GetInput()
		{
			if (_kbhit())
			{
				char c = _getch();
				
				return c;
			}

			return KEY_NONE;
		}
};

