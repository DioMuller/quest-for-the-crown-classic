#include <time.h>
#include "Console.h"

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

	double lastTime = current_time();
	double currentTime = current_time();

#ifdef _DEBUG 
	double fpsLast = current_time();
	int currentFPS = 0;
	int frameCount = 0;
#endif

	bool running = true;

	clrscr(BACKGROUND_CYAN);

	while( running )
	{
		currentTime = current_time();
		int loops = 0;

		while( lastTime + INTERVAL < currentTime && loops < IGNORED_FRAMES )
		{
			//For each Game Object -> Update
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

			mostrar ( 70, 0, FOREGROUND_WHITE, "DEBUG MODE" );
			mostrar ( 70, 1, FOREGROUND_WHITE, "FPS:   " );
			mostrar ( 77, 1, FOREGROUND_WHITE, (long) currentFPS );
#else
			mostrar ( 68, 0, FOREGROUND_WHITE, "RELEASE MODE" );
#endif
		}

		double interpolation = (lastTime + INTERVAL - currentTime) / 2;

		//For each Game Object -> Draw
	}

	return 0;
}