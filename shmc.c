#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/ipc.h>
#include<stdlib.h>

int main()
{
void *shared_mem;
key_t key=1234;
int shmid=shmget(key,1024,0666|IPC_CREAT);
shared_mem=shmat(shmid,NULL,0);
printf("data written is\n");
printf("%s",(char*)shared_mem);
shmdt(shared_mem);
shmctl(shmid,IPC_RMID,NULL);
}

