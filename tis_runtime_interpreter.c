#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#ifndef TIS_INIT_TIME
// Number of elapsed seconds on August 3, 2020.
#define TIS_INIT_TIME 1596453215L
#endif
#ifndef TIS_INCR_TIME
// Number of seconds incremented by default.
#define TIS_INCR_TIME 60L
#endif

struct timeval tis_internal_timeval = {
    .tv_sec = TIS_INIT_TIME,
    .tv_usec = TIS_INIT_TIME * 1000L
};

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    static int count = 0;
    if (tv == NULL && tz == NULL)
        return -1;

    if (count * TIS_INCR_TIME > sizeof(long) - tis_internal_timeval.tv_sec)
        count = 0;

    if (tv != NULL) {
        tv->tv_sec = tis_internal_timeval.tv_sec + TIS_INCR_TIME * count;
        tv->tv_usec = tis_internal_timeval.tv_usec + TIS_INCR_TIME * 1000l * count;
    }
    if (tz != NULL) {
        tz->tz_minuteswest =  (tis_internal_timeval.tv_sec + TIS_INCR_TIME * count) / 60;
        tz->tz_dsttime = 0;
    }
    count++;

    return 0;
}

int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    if (tv == NULL && tz == NULL)
        return -1;
    if (tv != NULL) {
        tis_internal_timeval.tv_sec = tv->tv_sec;
        tis_internal_timeval.tv_usec = tv->tv_usec;
    }
    return 0;
}

int mktime_error(struct tm *time)
{
    if (time->tm_sec < 0 || time->tm_min < 0 || time->tm_hour < 0)
        return -1;
    if (time->tm_year < 1900 || time->tm_mon < 0 || time->tm_wday < 0)
        return -1;
    return 0;
}

int error_handling(struct tm *time)
{
    if (time->tm_sec < 0 || time->tm_min < 0 || time->tm_hour < 0)
        return -1;
    if (time->tm_sec > 60 || time->tm_min > 59 || time->tm_hour > 59)
        return -1;
    if (time->tm_mday < 1 || time->tm_mon < 1|| time->tm_year < 1900)
        return -1;
    if (time->tm_mday > 31 || time->tm_mon > 12)
        return -1;
    return 0;
}

time_t mktime(struct tm *time)
{
    long res = 0;
    int count = 0;

    if (time == NULL || error_handling(time) == -1)
        return -1;
    res += time->tm_sec;
    res += time->tm_min * 100;
    res += time->tm_hour * 10000;
    res += time->tm_mday *1000000;
    res += time->tm_mon * 100000000;
    res += time->tm_year * 10000000000;
    printf("%ld\n", res);
    return res;
}
