#include "TitleScreen.h"
#include "GameManager.h"
#include "GameOver.h"
#include "VictoryScreen.h"

#include "Input.h"

int main(int argc, char **argv)
{
	bool running = true;

	while(running)
	{
		TitleScreen::Draw();
		while( Input::GetInput() != KEY_PAUSE ) Sleep(17);

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

	//End of the Game
	return 0;
}