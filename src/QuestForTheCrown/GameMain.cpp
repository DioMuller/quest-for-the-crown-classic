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
	const int IGNORED_FRAMES = 2;

	//Screen size: 80 x 25
	const int WIDTH = 80;
	const int HEIGHT = 25;

	//Game objects
	std::list<Enemy> enemies;
	std::list<Enemy>::iterator iterator;

	Player player = Player(10,10);

	enemies.push_back(Enemy(15,15));
	enemies.push_back(Enemy(12,19));
	enemies.push_back(Enemy(70,5));
	enemies.push_back(Enemy(1,1));
	enemies.push_back(Enemy(49,21));
	enemies.push_back(Enemy(5,20));
	enemies.push_back(Enemy(15,23));

	//Game Time
	double lastTime = current_time();
	double currentTime = current_time();

#ifdef _DEBUG 
	double fpsLast = current_time();
	int currentFPS = 0;
	int frameCount = 0;
#endif

	bool running = true;

	//Clear Screen
	clrscr(BACKGROUND_CYAN);

	//Draw GUI Bar
	mostrar(0,0,FOREGROUND_WHITE, "                                                                                ");
	mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");

	while( running )
	{
		currentTime = current_time();
		int loops = 0;

		while( lastTime + INTERVAL < currentTime && loops < IGNORED_FRAMES )
		{
			//For each Game Object -> Update
			player.Update(currentTime);

			for( iterator = enemies.begin(); iterator != enemies.end(); iterator++  )
			{
				(*iterator).Update(currentTime);
			}

			lastTime += INTERVAL;
			loops++;

#ifdef _DEBUG  
			if( currentTime - fpsLast > 1000.0 )
			{
				fpsLast = currentTime;
				currentFPS = frameCount;
				frameCount = 0;
			}

			frameCount++;
#endif
		}

		double interpolation = (lastTime + INTERVAL - currentTime) / 2;

		//For each Game Object -> Draw
		player.Draw();

		for( iterator = enemies.begin(); iterator != enemies.end(); iterator++  )
		{
			(*iterator).Draw();
		}
		
		//Draw the GUI
#ifdef _DEBUG
		mostrar ( 70, 0, FOREGROUND_WHITE, "DEBUG MODE" );
		mostrar ( 70, 1, FOREGROUND_WHITE, "FPS:   " );
		mostrar ( 77, 1, FOREGROUND_WHITE, (long) currentFPS );
#endif
	}

	return 0;
}