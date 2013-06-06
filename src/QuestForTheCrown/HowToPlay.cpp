#include "HowToPlay.h"
#include "Console.h"

void HowToPlay::Draw()
{
    clrscr(FOREGROUND_WHITE);
	mostrar(0, 0,FOREGROUND_WHITE, "################################################################################");
	mostrar(0, 1,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 2,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 3,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 4,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 5,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 6,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 7,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 8,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0, 9,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,10,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,11,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,12,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,13,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,14,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,15,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,16,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,17,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,18,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,19,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,20,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,21,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,22,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,23,FOREGROUND_WHITE, "#                                                                              #");
	mostrar(0,24,FOREGROUND_WHITE, "################################################################################");

	mostrar(5, 5, FOREGROUND_WHITE, "   [W]   ");
	mostrar(5, 6, FOREGROUND_WHITE, "[A][S][D]");

   	mostrar(15, 5, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Use the WASD keys");
	mostrar(15, 6, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "to      your character.");
    mostrar(18, 6, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "MOVE");

    mostrar(5, 10, FOREGROUND_WHITE, "   [^]   ");
	mostrar(5, 11, FOREGROUND_WHITE, "[<][v][>]");

   	mostrar(15, 10, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Use the Arrow keys");
	mostrar(15, 11, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "to        on a specific direction.");
    mostrar(18, 11, FOREGROUND_RED | FOREGROUND_INTENSITY, "ATTACK");

	mostrar(5, 15, FOREGROUND_WHITE, "[Q]   [E]");

   	mostrar(15, 15, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Use the 'q' and 'e' keys");
	mostrar(15, 16, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "to        your weapon.");
    mostrar(18, 16, FOREGROUND_YELLOW | FOREGROUND_INTENSITY, "CHANGE");

    mostrar(29, 20, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Press SPACE to return.");

    gotoxy(0,0);
}