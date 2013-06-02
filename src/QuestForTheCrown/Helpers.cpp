#include "Helpers.h"
#include <time.h>

/*
	Returns current time in ms.
*/
double current_time()
{
	clock_t cl = clock();

	return (double) (cl / CLOCKS_PER_SEC) * 1000.0;
}

Direction next_direction(Direction current)
{
	if( current = LEFT ) return UP;
	if( current = UP ) return RIGHT;
	if( current = RIGHT ) return DOWN;
	if( current = DOWN ) return LEFT;

}