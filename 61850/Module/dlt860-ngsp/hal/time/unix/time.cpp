/*
 *  time.c
 */

#include "gsp_hal_time.h"

#include <time.h>

#ifdef CONFIG_SYSTEM_HAS_CLOCK_GETTIME
uint64_t Hal_getTimeInMs()
{
	struct timespec tp;
	clock_gettime(CLOCK_REALTIME, &tp);
	return ((uint64_t) tp.tv_sec) * 1000LL + (tp.tv_nsec / 1000000);
}
#else

#include <sys/time.h>

uint64_t GSP_Hal_getTimeInMs()
{
    struct timeval now;
    gettimeofday(&now, nullptr);
    return ((uint64_t) now.tv_sec * 1000LL) + (now.tv_usec / 1000);
}

#endif

