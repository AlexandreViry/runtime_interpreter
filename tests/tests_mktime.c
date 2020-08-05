#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm date;
    long res;

    date.tm_wday = 4;
    date.tm_yday = 183;
    date.tm_mday = 03;
    date.tm_mon = 04;
    date.tm_year = 2015;
    date.tm_hour = 13;
    date.tm_min = 15;
    date.tm_sec = 36;
    res = mktime(NULL);
    //@ assert res == -1;
    res = mktime(&date);
    //@assert res == 183403042015131536;
    return 0;
}
