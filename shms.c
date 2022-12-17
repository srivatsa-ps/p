#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char *shared_mem;
    key_t key=1234;
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    shared_mem = shmat(shmid, NULL, 0);
    char buff[100];
    printf("enter data to write into shared memory ");
    gets(buff);
    strcpy(shared_mem, buff);
    printf("the data you wrote is %s \n", (char *)shared_mem);
}
