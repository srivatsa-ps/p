#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    printf("\nthe pid of hello.c is %d\n ", getpid());
    int pid = fork();
    if (pid == 0)
    {
        
        printf("\nchild's pid is %d \n", getpid());
        char *args[] = {"hi", NULL};
        execvp("./hi", args);
        printf("\nback to child");
    }
    else
    {
    printf("\nparent\n");
    
    }
    return 0;
}