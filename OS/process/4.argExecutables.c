

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h> 
#include <string.h>

int main( int argc, char * argv[] )
{

	int pid = 0;
	int a= 0, b= 0;
	const char *name;
	va_list  list;


//	va_start(list,argv);

//	name = argv[0]; //va_arg(list,const char*);
//	a = argv[1];
//	b = argv[2]; //va_arg(list,int);

//	va_end(list);
	
	pid = fork();

//	printf("\ncmd %s",argv[1]);
	
	execvp(argv[1],argv);
/*
	if (pid == 0 )
	{
		execvp("./one",NULL);
		printf("\nmy pid %d",getpid());
		printf("\nmy parent pid %d",getppid());
	}
	else
	{
		printf("\nmy pid %d",getpid());
		printf("\nmy child pid %d",pid);
	}
*/
	return 0;
}
