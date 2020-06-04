
#include <stdio.h> 
#include <stdlib.h> 
#include <semaphore.h> 
#include <unistd.h>  
#include <pthread.h> 

sem_t mutex;

void *func(void *input)
{
    sem_wait(&mutex);
    printf("%s\n", (char *)input);
    sleep(1);
    sem_post(&mutex);
}

int main()
{
    pthread_t A, B;
    sem_init(&mutex, 0, 1);
    pthread_create(&B,NULL,func,"Inside B");
    pthread_create(&A,NULL,func,"Inside A");
    pthread_join(A,NULL);
    pthread_join(B,NULL);

    printf("Inside main thread\n");

    sem_destroy(&mutex);
    return 0;
}