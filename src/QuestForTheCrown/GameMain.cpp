#include <time.h>
#include <list>
#include "Console.h"
#include "Player.h"
#include "Enemy.h"

/*
	Returns current time in ms.
*/
double current_time()
{
	clock_t cl = clock();

	return (double) (cl / CLOCKS_PER_SEC) * 1000.0;
}

int main(int argc, char **argv)
{
	//Game FPS
	const double FPS = 60.0;
	const double INTERVAL = 1000.0 / FPS;

	//Screen size: 80 x 25
	const int WIDTH = 80;
	const int HEIGHT = 25;

	//Time variables
	double currentTime;

	//Game objects
	std::list<Enemy> enemies;
	std::list<Enemy>::iterator iterator;

	Player player = Player(10,10);

	enemies.push_back(Enemy(15, 15, 15));
	enemies.push_back(Enemy(12, 19, 15));
	enemies.push_back(Enemy(70, 5, 15));
	enemies.push_back(Enemy(2, 2, 15));
	enemies.push_back(Enemy(49, 21, 15));
	enemies.push_back(Enemy(5, 20, 15));
	enemies.push_back(Enemy(15, 23, 15));

	//Debug Valiables
	#ifdef _DEBUG 
	double fpsLast = current_time();
	int currentFPS = 0;
	int frameCount = 0;
	#endif

	bool running = true;

	while( running )
	{	
		//Clear Screen
		clrscr(BACKGROUND_CYAN);

		//Draw GUI Bar
		mostrar(0,0,FOREGROUND_WHITE, "                                                                                ");
		mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");

		currentTime = current_time();

		//For each Game Object -> Update
		player.Update(currentTime);

		for( iterator = enemies.begin(); iterator != enemies.end(); iterator++  )
		{
			(*iterator).Update(currentTime);
		}

		//Show debug options
		#ifdef _DEBUG
		currentTime = current_time();

		if( currentTime - fpsLast > 1000.0 )
		{
			fpsLast = currentTime;
			currentFPS = frameCount;
			frameCount = 0;
		}

		frameCount++;
		#endif


		//For each Game Object -> Draw
		player.Draw();

		for( iterator = enemies.begin(); iterator != enemies.end(); iterator++  )
		{
			(*iterator).Draw();
		}
		
		//Draw debug data the GUI
		#ifdef _DEBUG
		mostrar ( 70, 0, FOREGROUND_WHITE, "DEBUG MODE" );
		mostrar ( 70, 1, FOREGROUND_WHITE, "FPS: " );
		mostrar ( 75, 1, FOREGROUND_WHITE, (long) currentFPS );
		#endif

		Sleep((DWORD) INTERVAL + 1);
	}

	return 0;
}