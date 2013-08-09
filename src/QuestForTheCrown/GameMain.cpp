#include "TitleScreen.h"
#include "GameManager.h"
#include "GameOver.hpp"
#include "VictoryScreen.hpp"
#include "HowToPlay.hpp"

#include "Input.h"

#include <time.h>

int main(int argc, char **argv)
{
	bool running = true;

	while(running)
	{
		TitleScreen::Draw();
        clock_t t1, t2;
        int time_ms;

        Option opt = OPTION_NONE;
		while( opt == OPTION_NONE )
        {
            t1 = clock();
            opt = TitleScreen::UpdateDraw();
            t2 = clock();
            time_ms = (t2-t1);

            Sleep(17 - time_ms);
        }

        if( opt == OPTION_NEWGAME )
        {
		    //Main Game Loop
		    GameManager::ResetGame();

		    while( GameManager::IsRunning() )
		    {	
                t1 = clock();
			    GameManager::UpdateGame();
			    GameManager::DrawGame();
                t2 = clock();
                time_ms = (t2-t1);

			    Sleep(max(17 - time_ms,0)); //Poor mans substitute for gameTime. At least it doesn't make the Draw() function more complicated.
		    }

		    //Game Over Loop
		    if( GameManager::WasSuccessful() )
		    {
			    VictoryScreen::Draw();
		    }
		    else
		    {
			    GameOver::Draw();
		    }
		    while( Input::GetInput() != KEY_PAUSE ) Sleep(17);
        }
        else if( opt == OPTION_HOWTOPLAY )
        {
            HowToPlay::Draw();
            Sleep(500);
            while( Input::GetInput() != KEY_PAUSE ) Sleep(17);
        }
        else if( opt == OPTION_QUIT )
        {
            running = false;
        }
	}

	//End of the Game
	return 0;
}