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
    //@ assert tz.tz_minuteswest == 26607553 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, NULL);
    //@ assert res == 0;
    //@ assert tz.tz_minuteswest == 26607553 && tz.tz_dsttime == 0;
    //@ assert tv.tv_sec == 1596453275 && tv.tv_usec == 1596453275000;
    res = gettimeofday(&tv, &tz);
    //@ assert res == 0;
    //@ assert tv.tv_sec == 1596453335 && tv.tv_usec == 1596453335000;
    //@ assert tz.tz_minuteswest == 26607555 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 1596453395 && tv.tv_usec == 1596453395000;
    //@ assert tz.tz_minuteswest == 26607556 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 1596453455 && tv.tv_usec == 1596453455000;
    //@ assert tz.tz_minuteswest == 26607557 && tz.tz_dsttime == 0;


    res = settimeofday(NULL, NULL);
    //@ assert res == -1;
    res = settimeofday(NULL, &tz);
    //@ assert res == 0;
    res = settimeofday(&tv, NULL);
    //@ assert res == 0;


    tv.tv_sec = 1326953455;
    tv.tv_usec = 1326953455000;
    tz.tz_minuteswest = 22115890;
    tz.tz_dsttime = 0;
    res = settimeofday(&tv, &tz);
    //@ assert res == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 1326953755 && tv.tv_usec == 1326953755000;
    //@ assert tz.tz_minuteswest == 22115895 && tz.tz_dsttime == 0;
    res = gettimeofday(&tv, &tz);
    //@ assert tv.tv_sec == 1326953815 && tv.tv_usec == 1326953815000;
    //@ assert tz.tz_minuteswest == 22115896 && tz.tz_dsttime == 0;

    return 0;
}
