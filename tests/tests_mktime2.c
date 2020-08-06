#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm date;
    long res;

    date.tm_wday = 8;
    date.tm_yday = 980;
    date.tm_mday = 01;
    date.tm_mon = 21;
    date.tm_year = 1970;
    date.tm_hour = 25;
    date.tm_min = 68;
    date.tm_sec = 80;
    res = mktime(&date);
    //@ assert res == -1;
    res = mktime(NULL);
    //@ assert res == -1;
    return 0;
}
