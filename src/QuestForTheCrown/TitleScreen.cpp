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

	mostrar(1, 2, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "      e88 88e                             d8      dP,e,                  ");
	mostrar(1, 3, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "     d888 888b  8888 8888  ,e e,   dP\"Y  d88      8b \"   e88 88e  888,8, ");
	mostrar(1, 4, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "    C8888 8888D 8888 8888 d88 88b C88b  d88888   888888 d888 888b 888 \"  ");
	mostrar(1, 5, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "     Y888 888P  Y888 888P 888   ,  Y88D  888      888   Y888 888P 888    ");
	mostrar(1, 6, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "      \"88 88\"    \"88 88\"   \"YeeP\" d,dP   888      888    \"88 88\"  888    ");
	mostrar(1, 7, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "          b                                                              ");
	mostrar(1, 8, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "          8b,                                                            ");
	mostrar(1, 9, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "    d8   888                 e88'Y88                                        ");
	mostrar(1, 10, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "   d88   888 ee   ,e e,     d888  'Y 888,8,  e88 88e  Y8b Y8b Y888P 888 8e  ");
	mostrar(1, 11, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "  d88888 888 88b d88 88b   C8888     888 \"  d888 888b  Y8b Y8b Y8P  888 88b ");
	mostrar(1, 12, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "   888   888 888 888   ,    Y888  ,d 888    Y888 888P   Y8b Y8b \"   888 888 ");
	mostrar(1, 13, FOREGROUND_YELLOW | FOREGROUND_INTENSITY,  "   888   888 888  \"YeeP\"     \"88,d88 888     \"88 88\"     YP  Y8P    888 888 ");

	mostrar(25, 15, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Author: Diogo Muller de Miranda");

	mostrar(29, 22, FOREGROUND_WHITE | FOREGROUND_INTENSITY, "Press SPACE to select.");

	gotoxy(0,0);
}

Option TitleScreen::UpdateDraw()
{
    WORD active = FOREGROUND_BLUE | BACKGROUND_WHITE;
    WORD inactive = FOREGROUND_WHITE;
    int option = (int) selectedOption;

    mostrar(34, 17, selectedOption == OPTION_NEWGAME ? active : inactive , "Start Game");
    mostrar(34, 18, selectedOption == OPTION_HOWTOPLAY ? active : inactive , "How to Play");
    mostrar(34, 19, selectedOption == OPTION_QUIT ? active : inactive , "Quit Game");

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