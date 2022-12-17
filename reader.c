#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include<string.h>
#include <unistd.h>

int readerCount=0;
sem_t mutex, wrt;
int common_data=0;

void* writer(void* arg)
{
    sem_wait(&wrt);
    printf("Enter Data to be written: ");
    scanf("%d", &common_data);
    printf("%d written.\n",common_data);
    sleep(3);
    sem_post(&wrt);
    pthread_exit(0);
}

void* reader(void* arg)
{
    sleep(2);
    sem_wait(&mutex);
    readerCount++;
    if(readerCount==1)
        sem_wait(&wrt);
    sem_post(&mutex);
    
    printf("\n Data read by the Reader Thread %d is %d\n", readerCount,common_data);
    sleep(1);
    
    sem_wait(&mutex);
    readerCount--;
    if(readerCount==0)
        sem_post(&wrt);
    sem_post(&mutex);
    sleep(2);
    pthread_exit(0);
}

int main(void)
{
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_t rdid[5],wrid[5];
    // int i = 0;
    // int error;
    for(int i=0; i<3; ++i){
        pthread_create(&wrid[i], NULL, writer, NULL);
        pthread_create(&rdid[i], NULL, reader, NULL);
    }

    
    for(int i=0; i<3; i++){
      pthread_join(rdid[i],NULL);  
      pthread_join(wrid[i],NULL);
    }
    return 0;
}