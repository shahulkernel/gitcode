


#include<sys/types.h>
int globalvar=6;
main()
{
	int localvar;
	pid_t pid;
	localvar=88;
	printf("BEFORE VFORK\n");
	if((pid=vfork())<0)
	{
		printf("ERROR IN VFORK\n");
		exit(0);
	}
	else if (pid==0)
	{
		globalvar++;
		localvar++;
		_exit(0);
	}
	printf("Parent process id = %d, global variable=%d, local variable=%d\n", getpid(), globalvar, localvar);
}
