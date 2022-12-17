#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int BUFFER[5];
int END = 0;
int START = 0;
sem_t mutex;
sem_t empty;
sem_t full;


void* producer()
{
    int i=0;
    while(i<10)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        BUFFER[(START++)%5] = i;
        printf("Producer produces %d\n",i);
        i++;
        sem_post(&mutex);
        sleep(rand()%2);
        sem_post(&full);
    }

}

void* consumer()
{

    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        int i = BUFFER[(END)%5];
        printf("Consumer consumes %d\n",i);
        END++;
        sem_post(&mutex);
        sem_post(&empty);
    }



}


int main()
{
    srand(time(NULL));
    sem_init(&mutex,0,1);
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_t cons,prod;

    
    pthread_create(&cons,NULL,consumer,NULL);
    pthread_create(&prod,NULL,producer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);


    return 0;
}