#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <pthread.h>
#include<semaphore.h>

#define MS 400 // the size of the square matrices
int n;  // number of threads


extern float etime();//externally linking the etime() function


int MA[MS][MS];// declare the first matrix
int MB[MS][MS];// declare the second matrix
int MC[MS][MS];// declare the result matrix

sem_t sem;//semaphore for synchronization

void *worker(void *arg) {
    long tid = (long)arg; //thread id
    int start_row =(MS / n)*tid;// calculate starting row for this thread
    int end_row =(MS / n)* (tid +1) -1;// calculate ending row for this thread

    for (int i = start_row; i < end_row; i++) {

        for (int j = 0; j < MS; j++) {

            MC[i][j] = 0;

            for (int k = 0; k < MS; k++) {

                MC[i][j] += MA[i][k] * MB[k][j];
            }
        }
    }

    sem_post(&sem);//signal completion of work by this thread
}

int main(int argc, char *argv[]) {
int start_row;// start row for matrix initialization
int end_row;// end row for matrix initialization
    sem_init(&sem,0,0);
    if (argc != 2) {
        printf(" not arguments:\n");
        return 1;
    }
 n = atoi(argv[1]);
   
           
    pthread_t threads[n];// declare array to hold thread id
   
   
    for (int i = start_row; i < end_row; i++) {

        for (int j = 0; j < MS; j++) {

            MA[i][j] = 0;
            }
         }
           
           
            for (int i = start_row; i < end_row; i++) {

        for (int j = 0; j < MS; j++) {

            MB[i][j] = 0;
            }
          }  
   
   
   
etime();
    // create specified number of worker threads
    for (long i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, worker, (void *)i);
       
    }
    // wait for all threads to finish execution
    for (long i = 0; i< n; i++){
        sem_wait(&sem);
    }

   // measure total time taken for matrix multiplication
    float time_taken = etime();
    printf("Total time taken: %.6f seconds\n", time_taken);

    return 0;
}