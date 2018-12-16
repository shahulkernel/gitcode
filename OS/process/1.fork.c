

#include<stdio.h>
#include <unistd.h>


int main()
{

	int pid = 0;

	pid = fork();

	if (pid == 0 )
	{
		printf("\nmy pid %d",getpid());
		printf("\nmy parent pid %d",getppid());
	}
	else
	{
		printf("\nmy pid %d",getpid());
		printf("\nmy child pid %d",pid);
	}
	return 0;
}
