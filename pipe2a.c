#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<stdlib.h>
int main()
{
	int r,fd[2];
	char str[30],str1[30];
	r=pipe(fd);
	if(r==0)
	{
		printf("\nPipe Creation is Successful");
		//close(fd[0]);
		printf("\nEnter a string: ");
		scanf("%s",str);
		printf("\nSize of str=%ld",sizeof(str));
		printf("\nstr=%s",str);
		write(fd[1],str,sizeof(str));
		close(fd[1]);
		read(fd[0],str1,sizeof(str1));
		printf("\nString from the pipe: %s",str1);
	}
	else
		printf("\nError");
	return 0;
}
