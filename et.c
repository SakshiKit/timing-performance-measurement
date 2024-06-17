#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

extern float etime(); // linking of etime
int number;
char* buffer; 
char* argument;
// Thread function to perform memory access based on command line argument.
void*function (void *arg) {
     if(strcmp(argument,"-a") ==0) {
       for (int i = 0; i<number*1024; i= i+4096) {
          buffer[i] = 20;
       }
    }
}

int main(int argc, char *argv[]){
   // check if the command line arguments is not equal to 3
if (argc != 3) {
printf("/et -a size\n") ; // print usage information
exit (1);
}

float time_taken;
int number=atoi (argv[2]); //convert the second command line argument to an integer
int unitK=1024;                                 
argument=argv [1];
char* buffer = (char*) calloc(number, unitK);// allocate memory for the buffer array
pthread_t task; // declared a pthread variable for the task

etime();

if (strcmp(argument,"-b") ==0) {
   for (int i = 0; i < number*unitK; i=i+4096) {
     buffer[i] = 20;
   }
}

pthread_create(&task, NULL,function, NULL); // create a new thread to execute the function
pthread_join (task, NULL); // wait for the thread to finish execution
time_taken = etime();
printf("Total time taken:%f seconds\n", time_taken);// print the total time taken

}