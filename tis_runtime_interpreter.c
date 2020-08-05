#include <stdio.h>
#include <sys/time.h>
#include <time.h>

// Gettimeofday and settimeofday Macros :

#ifndef TIS_INIT_TIME
// Number of elapsed seconds on August 3, 2020.
#define TIS_INIT_TIME 1596453215L
#endif
#ifndef TIS_INCR_TIME
// Number of seconds incremented by default.
#define TIS_INCR_TIME 60L
#endif

// My_mktime Macros :

#ifndef INIT_VALUE
#define INIT_VALUE 1000L
#endif
#ifndef INCR_VALUE
#define INCR_VALUE 1000L
#endif

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    static int count = 0;
    if (tv == NULL && tz == NULL)
	return -1;

    if (count * TIS_INCR_TIME > sizeof(long) - TIS_INIT_TIME)
	count = 0;

    if (tv != NULL) {
	tv->tv_sec = TIS_INIT_TIME + TIS_INCR_TIME * count;
	tv->tv_usec = TIS_INIT_TIME * 1000l + TIS_INCR_TIME * 1000l * count;
    }
    if (tz != NULL) {
	tz->tz_minuteswest =  (TIS_INIT_TIME + TIS_INCR_TIME * count) / 60;
	tz->tz_dsttime = 0;
    }
    count++;

    return 0;
}

int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    if (tv == NULL && tz == NULL)
	return -1;

    return 0;
}

time_t my_mktime(struct tm *time)
{
    static long res = INIT_VALUE;

    if (time == NULL)
        return -1;
    res += INCR_VALUE;
    return res;
}

time_t time_structure_modifier(struct tm *time)
{
    long res = 0;

    if (time == NULL)
        return -1;
    res = time->tm_sec;
    res += time->tm_min * 100;
    res += time->tm_hour * 10000;
    res += time->tm_year * 1000000;
    res += time->tm_mon * 10000000000;
    res += time->tm_mday * 1000000000000;
    res += time->tm_wday * 100000000000000;
    res += time->tm_yday * 1000000000000000;
    return res;
}
