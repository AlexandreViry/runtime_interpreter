#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    int res;
    struct timeval tv;
    struct timezone tz;

    res = gettimeofday(NULL, NULL);
    //@ assert res == -1;
    res = gettimeofday(NULL, &tz);
    //@ assert res == 0;
    //@ assert tz.tz_minuteswest == 78641953 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, NULL);
    //@ assert res == 0;
    //@ assert tz.tz_minuteswest == 78641953 && tz.tz_dsttime == 0;
    //@ assert tv.tv_sec == 4718603615 && tv.tv_usec == 4718603615000;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4718690015 && tv.tv_usec == 4718690015000;
    //@ assert tz.tz_minuteswest == 78644833 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4718776415 && tv.tv_usec == 4718776415000;
    //@ assert tz.tz_minuteswest == 78646273 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4718862815 && tv.tv_usec == 4718862815000;
    //@ assert tz.tz_minuteswest == 78647713 && tz.tz_dsttime == 0;

    res = settimeofday(NULL, NULL);
    //@ assert res == -1;
    res = settimeofday(NULL, &tz);
    //@ assert res == 0;
    res = settimeofday(&tv, NULL);

    tv.tv_sec = 4618603615;
    tv.tv_usec = 4618603615000;
    tz.tz_minuteswest = 76976726;
    tz.tz_dsttime = 0;
    //@ assert res == 0;
    res = settimeofday(&tv, &tz);
    //@ assert res == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4619035615 && tv.tv_usec == 4618603615000;
    //@ assert tz.tz_minuteswest == 76983926 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 4619122015 && tv.tv_usec == 4619122015000;
    //@ assert tz.tz_minuteswest == 76985366 && tz.tz_dsttime == 0;
    printf("sec = %ld, usec = %ld, min = %d\n",tv.tv_sec, tv.tv_usec, tz.tz_minuteswest);

    return 0;
}
