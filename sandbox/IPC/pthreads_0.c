#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutext = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;

int number_evens_finished = 0;

int counter = 0; // Global variable to be manipulated by our threads

void *function_1(void *data);

int main(void)
{
  pthread_t thread_id[NTHREADS]; // Create array of 10 threads
  int values[NTHREADS];
  
  for (int k = 0; k < 150; k++)
  {
    for (int i = 0; i < NTHREADS; i++) // For-Loop to create the 10 threads
    {
      values[i] = i;
      pthread_create(&thread_id[i], NULL, function_1, &values[i]);
    }
    // Need to wait until all Threads have been created and running
    // Even try to signal (or there will be a race condition)
    sleep(1);
    
    while(1)
    {
      if (number_evens_finished == NTHREADS / 2)
      {    
        pthread_cond_broadcast(&evens_done);
        break;
      }
    }
    
    for (int j = 0; j < NTHREADS; j++)
    {
      pthread_join(thread_id[j], NULL); // Join the 10 threads to Main
      //pthread_exit(&thread_id[j]); // Kill Threads before exiting the program
    }
    counter = 0;
    number_evens_finished = 0;
  }
  return(0);
}

void *function_1(void *data) // Function to pass to pthread_create
{
  int *x = (int *)data; // Type-cast to *int, as the prototype
                        // only allows for a void *
  pthread_mutex_lock(&condition_mutext);
  //pthread_mutex_lock(&lock);
  
  if (*x % 2 == 0)
  {
    number_evens_finished++;
  }
  else
  {
    pthread_cond_wait(&evens_done, &condition_mutext); 
  }
  
  pthread_mutex_unlock(&condition_mutext);
  
  pthread_mutex_lock(&lock);
  
  counter++;
  
  printf("Message is %d, thread_id -> %lud modified the counter to = %d\n", *x, pthread_self(), counter);
  printf("Message is %d, thread_id -> %lud read the counter = %d\n", *x, pthread_self(), counter);

  pthread_mutex_unlock(&lock);
}