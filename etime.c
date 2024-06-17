#include <stdlib.h>
#include <sys/time.h> 
#include <stdio.h>

struct timeval start;

float etime (){
struct timeval stop;
float time_taken;
gettimeofday (&stop, NULL);
time_taken=(stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
start = stop;
return time_taken;
}


