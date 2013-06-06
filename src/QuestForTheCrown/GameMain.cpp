#include "TitleScreen.h"
#include "GameManager.h"
#include "GameOver.h"
#include "VictoryScreen.h"
#include "HowToPlay.h"

#include "Input.h"

int main(int argc, char **argv)
{
	bool running = true;

	while(running)
	{
		TitleScreen::Draw();
        Option opt = OPTION_NONE;
		while( opt == OPTION_NONE )
        {
            opt = TitleScreen::UpdateDraw();
            Sleep(17);
        }

        if( opt == OPTION_NEWGAME )
        {
		    //Main Game Loop
		    GameManager::ResetGame();

		    while( GameManager::IsRunning() )
		    {	
			    GameManager::UpdateGame();
			    GameManager::DrawGame();

			    Sleep(17);
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