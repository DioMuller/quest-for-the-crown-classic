#include "TitleScreen.h"
#include "Console.h"
#include "Input.h"

#define NUM_OPTIONS 3

Option selectedOption = OPTION_NEWGAME;

void TitleScreen::Draw()
{
    //Only on the first draw.
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

	mostrar(30, 5, FOREGROUND_YELLOW | FOREGROUND_INTENSITY, "QUEST FOR THE CROWN");
	mostrar(25, 6, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Author: Diogo Muller de Miranda");

	mostrar(29, 20, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Press SPACE to select.");

	gotoxy(0,0);
}

Option TitleScreen::UpdateDraw()
{
    WORD active = FOREGROUND_BLUE | BACKGROUND_WHITE;
    WORD inactive = FOREGROUND_WHITE;
    int option = (int) selectedOption;

    mostrar(34, 9, selectedOption == OPTION_NEWGAME ? active : inactive , "Start Game");
    mostrar(34, 10, selectedOption == OPTION_HOWTOPLAY ? active : inactive , "How to Play");
    mostrar(34, 11, selectedOption == OPTION_QUIT ? active : inactive , "Quit Game");

    switch(Input::GetInput())
    {
        case KEY_UP:
        case KEY_DOWN_ACTION:
            if( option > 0 )
            {
                selectedOption = (Option) (option - 1);
            }
            break;
        case KEY_DOWN:
        case KEY_UP_ACTION:
            if( option < (NUM_OPTIONS - 1) )
            {
                selectedOption = (Option) (option + 1);
            }
            break;
        case KEY_PAUSE:
            return selectedOption;
        default:
            break;
    }

    return OPTION_NONE;
}