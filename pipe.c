#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/time.h>
int main()
{
	pid_t pid;
	int r, pfd[2], f, f2;
	char name[15], st[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
	char st2[27];
	r = pipe(pfd);
	if (r < 0)
		printf("\nError in creation of pipe");
	pid = fork();
	if (pid == 0)
	{
		printf("\nI am the child process");
		close(pfd[1]);
		f2 = read(pfd[0], st2, sizeof(st2));
		printf("\nRead the content:%s\n", st2);
	}
	else if (pid > 0)
	{
		setpriority(PRIO_PROCESS, 0, 19);
		printf("\nI am the parent process");
		close(pfd[0]);
		f = write(pfd[1], st, sizeof(st));
	}
	else
		printf("\nError in process creation");
	return 0;
}
