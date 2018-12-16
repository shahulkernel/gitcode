
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


//#include<sys/typesi.h>
//#include<sys/wait.h>
//#include<stdio.h>
main()
{
	pid_t pid,i;
	int status;
	if((pid=fork())==0)
	{
		if((pid=fork())>0)
			exit(10);
		sleep(2);
		printf("Second Child, parent Id =%d\n",getppid());
		exit(0);
	}
	i=wait(&status);
	printf("My Child with pid %d exited with status %d\n",i,WEXITSTATUS(status));
}

