#include "GameManager.h"



int main(int argc, char **argv)
{
	GameManager manager = GameManager::GetInstance();

	while( manager.IsRunning() )
	{	
		manager.UpdateGame();
		manager.DrawGame();

		Sleep(17);
	}

	return 0;
}