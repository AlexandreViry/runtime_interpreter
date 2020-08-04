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
  //@ assert res == -1;
  res = gettimeofday(&tv, NULL);
  //@ assert res == -1;
  res = gettimeofday(&tv, &tz);
  //@ assert res == 0;
  //@ assert tv.tv_sec == 1596453215 && tv.tv_usec == 1596453215000;
  //@ assert tz.tz_minuteswest == 26607553 && tz.tz_dsttime == 0;
  res = gettimeofday(&tv2, &tz);
  //@ assert tv.tv_sec == 1596453275 && tv.tv_usec == 1596453275000;
  //@ assert tz.tz_minuteswest == 26607554 && tz.tz_dsttime == 0;
  //@ assert (tv2.tv_sec - tv.tv_sec) == 60;
  res = gettimeofday(&tv2, &tz);
  //@ assert tv.tv_sec == 1596453335 && tv.tv_usec == 1596453335000;
  //@ assert tz.tz_minuteswest == 26607555 && tz.tz_dsttime == 0;
  //@ assert (tv2.tv_sec - tv.tv_sec) == 120;

  #define TIS_INIT_TIME 4718517215L
  #define TIS_INCR_TIME 86400L

  res = gettimeofday(&tv, &tz);
  printf("%ld\n", tv.tv_sec);
  //@ assert res == 0;
  //@ assert tv.tv_sec == 4718517215 && tv.tv_usec == 4718517215000;
  //@ assert tz.tz_minuteswest == 78641953 && tz.tz_dsttime == 0;
  res = gettimeofday(&tv2, &tz);
  printf("temps écoulé = %ld\n", tv2.tv_sec - tv.tv_sec);
  //@ assert tv.tv_sec == 4718603615 && tv.tv_usec == 4718603615000;
  //@ assert tz.tz_minuteswest == 78643393 && tz.tz_dsttime == 0;
  //@ assert (tv2.tv_sec - tv.tv_sec) == 86400;
  res = gettimeofday(&tv2, &tz);
  printf("temps écoulé = %ld\n", tv2.tv_sec - tv.tv_sec);
  //@ assert tv.tv_sec == 4718690015 && tv.tv_usec == 4718690015000;
  //@ assert tz.tz_minuteswest == 78644833 && tz.tz_dsttime == 0;
  //@ assert (tv2.tv_sec - tv.tv_sec) == 172800;

  res = settimeofday(NULL, NULL);
  //@ assert res = -1;
  res = settimeofday(NULL, &tz);
  //@ assert res = -1;
  res = settimeofday(&tv, NULL);
  //@ assert res = -1;
  res = settimeofday(&tv, &tz);
  //@ assert res = 0;

  return 0;
}
