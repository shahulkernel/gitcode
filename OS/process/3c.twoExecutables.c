

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <string.h>

int main()
{

	int pid = 0;

	pid = fork();

//	if (pid == 0 )
	{
		execvp("./one",NULL);
		printf("\nmy pid %d",getpid());
		printf("\nmy parent pid %d",getppid());
	}
//	else
	{
		printf("\nmy pid %d",getpid());
		printf("\nmy child pid %d",pid);
	}
	return 0;
}
