

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{

	int pid = 0;

	pid = fork();

	if (pid == 0 )
	{
		printf("\nmy pid %d",getpid());
		printf("\nmy parent pid %d",getppid());
		exit(10);
	}
	else
	{
		int status = 0,stat = 0;
		wait(&status);
		stat = WEXITSTATUS(status);
		printf("child exit with status %d",stat);
		printf("\nmy pid %d",getpid());
		printf("\nmy parent pid %d",getppid());
	}
	return 0;
}
