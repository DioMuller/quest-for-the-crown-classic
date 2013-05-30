#include "TitleScreen.h"
#include "GameManager.h"
#include "GameOver.h"

#include "Input.h"

int main(int argc, char **argv)
{
	TitleScreen::Draw();
	while( Input::GetInput() != KEY_ACTION ) Sleep(17);

	//Main Game Loop
	while( GameManager::IsRunning() )
	{	
		GameManager::UpdateGame();
		GameManager::DrawGame();

		Sleep(17);
	}

	//Game Over Loop
	GameOver::Draw();
	while( Input::GetInput() != KEY_ACTION ) Sleep(17);

	//End of the Game
	return 0;
}