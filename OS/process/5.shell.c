

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
	char s[100];

	while (1)
	{	
		printf("\nenter the command to execute or q to exit#############");
		scanf(s);

		pid = fork();

		if (pid ==0)
		{	
			execvp(argv[1],argv);
		}
		else
		{
			wait(&status);
			continue;
		}	
	}
	return 0;
}
