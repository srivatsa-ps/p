#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    printf("\nthis is hi.c is \n ");
    printf("PID=  %d\n ", getpid());
    return 0;
}