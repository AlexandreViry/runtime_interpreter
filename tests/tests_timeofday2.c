#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    int res;
    struct timeval tv;
    struct timeval tv2;
    struct timezone tz;

    res = gettimeofday(NULL, NULL);
    //@ assert res == -1;
    res = gettimeofday(NULL, &tz);
    //@ assert res == 0;
    //@ assert tz.tz_minuteswest == 78641953 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, NULL);
    //@ assert res == 0;
    //@ assert tv.tv_sec == 4718517215 && tv.tv_usec == 4718517215000;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4718603615 && tv.tv_usec == 4718603615000;
    //@ assert tz.tz_minuteswest == 78643393 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv2, &tz);
    //@ assert tv.tv_sec == 4718690015 && tv.tv_usec == 4718690015000;
    //@ assert tz.tz_minuteswest == 78644833 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv2, &tz);
    //@ assert tv.tv_sec == 4718776415 && tv.tv_usec == 4718776415000;
    //@ assert tz.tz_minuteswest == 78646273 && tz.tz_dsttime == 0;

    res = settimeofday(NULL, NULL);
    //@ assert res == -1;
    res = settimeofday(NULL, &tz);
    //@ assert res == 0;
    res = settimeofday(&tv, NULL);
    //@ assert res == 0;
    res = settimeofday(&tv, &tz);
    //@ assert res == 0;

    return 0;
}
