#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm date;
    long res;

    date.tm_wday = 1;
    date.tm_yday = 1;
    date.tm_mday = 01;
    date.tm_mon = 01;
    date.tm_year = 1970;
    date.tm_hour = 00;
    date.tm_min = 00;
    date.tm_sec = 00;
    res = time_structure_modifier(&date);
    //@ assert res == 1101011970000000;
    res = time_structure_modifier(NULL);
    //@ assert res == -1;
    return 0;
}
