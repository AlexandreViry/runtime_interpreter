#include <time.h>
#include <stdio.h>

time_t my_mktime(struct tm *date);

int main(void)
{
    struct tm date;
    time_t timestamp;

    date.tm_mday = 6;
    date.tm_mon = 3;
    date.tm_year = 114;
    date.tm_hour = 12;
    date.tm_min = 30;
    date.tm_sec = 15;

    timestamp = my_mktime(&date);
    //@ assert timestamp == 2000;
    timestamp = my_mktime(NULL);
    //@ assert timestamp == -1;
    timestamp = my_mktime(&date);
    //@assert timestamp == 3000;
    timestamp = my_mktime(&date);
    //assert timestamp == 4000;
    timestamp = my_mktime(NULL);
    //@ assert timestamp == -1;
    return 0;
}
