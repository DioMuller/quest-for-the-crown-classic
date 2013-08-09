#include "GameOver.hpp"
#include "Console.h"

void GameOver::Draw()
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

	mostrar(34, 11, FOREGROUND_RED | FOREGROUND_INTENSITY, "Game Over");
	mostrar(24, 12, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Press SPACE to return to title.");

	gotoxy(0,0);
}
