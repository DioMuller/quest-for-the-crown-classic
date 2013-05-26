#include "GameManager.h"



int main(int argc, char **argv)
{
	while( GameManager::IsRunning() )
	{	
		GameManager::UpdateGame();
		GameManager::DrawGame();

		Sleep(17);
	}

	return 0;
}