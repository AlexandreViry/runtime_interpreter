#include <stdio.h>
#include <sys/time.h>

#ifndef TIS_INIT_TIME
// Number of elapsed seconds on August 3, 2020.
#define TIS_INIT_TIME 1596453215L
#endif
#ifndef TIS_INCR_TIME
// Number of seconds incremented by default.
#define TIS_INCR_TIME 60L
#endif


int gettimeofday(struct timeval *tv, struct timezone *tz)
{
  static int count = 0;
  if (tv == NULL || tz == NULL)
    return -1;

  if (count * TIS_INCR_TIME > sizeof(long) - TIS_INIT_TIME)
    count = 0;

  tv->tv_sec = TIS_INIT_TIME + TIS_INCR_TIME * count;
  tv->tv_usec = TIS_INIT_TIME * 1000l + TIS_INCR_TIME * 1000l * count;
  tz->tz_minuteswest = tv->tv_sec / 60;
  tz->tz_dsttime = 0;
  count++;

  return 0;
}

int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
  if (tv == NULL || tz == NULL)
    return -1;

  return 0;
}
