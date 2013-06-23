#pragma once
#include "XboxController.h"

#define KEY_NONE '\0'

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

#define KEY_UP_ACTION 0x50
#define KEY_DOWN_ACTION 0x48
#define KEY_LEFT_ACTION 0x4b
#define KEY_RIGHT_ACTION 0x4d

#define KEY_NEXT_WEAPON 'e'
#define KEY_PREV_WEAPON 'q'

#define KEY_PAUSE ' '

#define INPUT_DELAY 3

class Input
{
    private:
        XboxController* _controller;
        int _timeSinceLastInput;
        char _lastKey;
        int _vibrationTime;
    public:
        Input();
        ~Input();
	private:
        void NormalizeSticks(float* LX, float* LY, float* RX, float* RY );
        char GetControllerInput();
    public:
        static void Rumble(int intensity);
		static char GetInput();
};

