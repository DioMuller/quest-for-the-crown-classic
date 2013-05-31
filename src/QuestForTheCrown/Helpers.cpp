#ifndef __HELPERS_H_
#define __HELPERS_H_

#include <time.h>

/*
	Returns current time in ms.
*/
double current_time()
{
	clock_t cl = clock();

	return (double) (cl / CLOCKS_PER_SEC) * 1000.0;
}

#endif