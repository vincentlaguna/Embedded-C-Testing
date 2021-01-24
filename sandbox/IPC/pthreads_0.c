#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

int counter = 0;

int main(void)
{
  pthread_t thread_id[NTHREADS]; // Create array of 10 threads
  int values[NTHREADS];
  
  for (int i = 0; i < NTHREADS; i++)
  {
    values[i] = i;
    pthread__create(&thread[i], NULL, function_1, &values[i]);
  }
  
  return(0);
}
