#include <stdio.h>
#include <time.h>

#ifndef INIT_VALUE
#define INIT_VALUE 1000L
#endif
#ifndef INCR_VALUE
#define INCR_VALUE 1000L
#endif

time_t my_mktime(struct tm *time)
{
    static long res = INIT_VALUE;

    if (time == NULL)
        return -1;
    res += INCR_VALUE;
    return res;
}
