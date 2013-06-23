#include "Input.h"
#include <stdlib.h>
#include <conio.h>

Input instance;

Input::Input()
{
    _vibrationTime = 0;
    _controller = new XboxController(1);
}

Input::~Input()
{
    if( _controller ) delete _controller;
}

char Input::GetControllerInput()
{
    if( _controller->IsConnected() )
    {
        XINPUT_STATE state = _controller->GetState();

        //Remove Dead Zone
       // Controller is connected
      // Check to make sure we are not moving during the dead zone
        if( (state.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
            state.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
            (state.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
            state.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) )
        {    
                state.Gamepad.sThumbLX = 0;
                state.Gamepad.sThumbLY = 0;
        }
 
        if( (state.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
            state.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
            (state.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
            state.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) )
        {
                state.Gamepad.sThumbRX = 0;
                state.Gamepad.sThumbRY = 0;
        }

        
        //Movement
        if( state.Gamepad.sThumbLX != 0 || state.Gamepad.sThumbLY != 0 )
        {
            if( abs( state.Gamepad.sThumbLX ) > abs(state.Gamepad.sThumbLY) )
            {
                return state.Gamepad.sThumbLX < 0 ? KEY_LEFT : KEY_RIGHT;
            }
            else
            {
                return state.Gamepad.sThumbLY < 0 ? KEY_DOWN : KEY_UP;
            }
        }
        //ATTACK
        if( state.Gamepad.sThumbRX != 0 || state.Gamepad.sThumbRY != 0 )
        {
            if( abs( state.Gamepad.sThumbRX ) > abs(state.Gamepad.sThumbRY) )
            {
                Rumble(15);
                return state.Gamepad.sThumbRX < 0 ? KEY_LEFT_ACTION : KEY_RIGHT_ACTION;
            }
            else
            {
                Rumble(15);
                return state.Gamepad.sThumbRY > 0 ? KEY_DOWN_ACTION : KEY_UP_ACTION;
            }
        }
        //SWITCH WEAPONS
        if( state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER )
        {
            return KEY_PREV_WEAPON;
        }
        if( state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER )
        {
            return KEY_NEXT_WEAPON;
        }
        //PAUSE
        if( state.Gamepad.wButtons & (XINPUT_GAMEPAD_START | XINPUT_GAMEPAD_A) )
        {
            Rumble(50);
            return KEY_PAUSE;
        }
    }

    return KEY_NONE;
}


char Input::GetInput()
{
    char input = instance.GetControllerInput();

    if( instance._timeSinceLastInput <= 0 || input != instance._lastKey )
    {
        if( input != KEY_NONE )
        {
            instance._lastKey = input;
            instance._timeSinceLastInput = INPUT_DELAY;
            return input;
        }
    }
    else if( instance._timeSinceLastInput > 0 )
    {
        instance._timeSinceLastInput--;
    }

	if (_kbhit())
	{
		char c = _getch();

		while(_kbhit()) c = _getch();
				
		return c;
	}

    if( instance._vibrationTime == 1 )
    {
        instance._vibrationTime = 0;
        instance._controller->Vibrate();
    }
    else if ( instance._vibrationTime > 1 )
    {
        instance._vibrationTime--;
    }

	return KEY_NONE;
}

void Input::Rumble(int intensity)
{
    if( instance._controller->IsConnected() )
    {
        instance._controller->Vibrate(intensity * 655, intensity * 655);
        instance._vibrationTime = 17;
    }
}