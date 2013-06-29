#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

// No MFC
#define WIN32_LEAN_AND_MEAN
// We need the Windows Header and the XInput Header
#include <windows.h>
#include <XInput.h>
//Imports the XInput library acording to the version.
//Pre-VS2012
//#ifdef MSC_VER < 1700
#pragma comment(lib,"XINPUT.LIB")
//#else
//#pragma comment(lib,"XINPUT9_1_0.LIB")
//#endif

// XBOX Controller Class Definition
class XboxController
{
private:
    XINPUT_STATE _controllerState;
    int _controllerNum;
    bool _controllerActive;
public:
    XboxController(int playerNumber);

public:
    XINPUT_STATE GetState();
    bool IsConnected();
    void Vibrate(int leftVal = 0, int rightVal = 0);
};

#endif