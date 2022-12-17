#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<semaphore.h>
#include<pthread.h>


sem_t chops[6];

void* philosopher(void* ind)
{
    int i = *((int *)ind);
    while(1)
    {    
        printf("\nPhilosopher %d is Hungry",i);
        sem_wait(&chops[i]);
        sem_wait(&chops[(i+1)%5]);
        printf("\nPhilosopher %d is eating",i);
        sleep(2+rand()%3);
        sem_post(&chops[(i+1)%5]);
        sem_post(&chops[i]);
        printf("\nPhilosopher %d is thinking",i);
        sleep(rand()%4);
    }
}


int main()
{
    srand(0);
    for(int i =0;i<5;i++)
        sem_init(&chops[i],0,1);
    int philno[] = {0,1,2,3,4};
    pthread_t phils[5];
    for(int i=0;i<5;i++)
    {
        pthread_create(&phils[i],NULL,philosopher,&philno[i]);
    }
    for(int i=0;i<5;i++)
    {
        pthread_join(phils[i],NULL);
    }
    return 0;

}