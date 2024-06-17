#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/time.h>

extern float etime(); //externally linking the etime() function

int main(int argc, char *argv[]){
if (argc != 3)
{
printf("/ep -a size\n");// prints usage information if incorrect number of arguments provided
exit (1);// exit the program 
}

float time_taken;
etime();
int unitK=1024;
int number = atoi (argv [2]);
char* buffer = (char*) calloc (number, unitK);// allocate memory for the buffer array
pid_t cpid;// variable to hold child process ID
if (strcmp(argv[1], "-b") == 0){
for (int i = 0; i < number*unitK; i= i+4096) {
buffer [i] = 20;
   }
}
if ((cpid==fork()) == 0){
//this is child

if (strcmp(argv[1], "-a") == 0) {
for (int i = 0; i < number*unitK; i= i+4096) {
buffer [i] = 20;
}
}
exit(0);// exit the child process
}else{
//this is parent
// wait for the child process to finish execution
waitpid (cpid, NULL, 0);
time_taken = etime();
printf("Total time taken is: %f\n", time_taken); // print the total time taken
}
return 0;
}

