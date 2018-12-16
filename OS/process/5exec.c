
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



int main(int cnt, char * arg[])
{
	int pid = 0;
	int t = 1;
	char buf[100];
	char buf1[100];
	char * str;
	int status = 0;
	int i = 0;
	char *argv[10];
	

	memset(buf,0,100);	
	while(1)
	{

		memset(buf,0,100);	
		memset(buf1,0,100);

		printf("\n Enter command#");
		fgets(buf,100,stdin);
	//	flush();
		i = 0;
		argv[i] = strtok(buf," ");

		str = argv[i];

		while (argv[i] != NULL)
		{
			printf("\n argv  %s ",argv[i] );
			//if (i != 0)
				i++;
			argv[i] = strtok(NULL," ");
		}	
	

//		printf("\n Entered command %s string %s ",str,buf );
		
		pid = fork();

		if (pid == 0)
		{
			execvp(str,argv);
			exit(10);
		}
		else
		{
			wait(&status);
			printf("\npress 1 to continue");
			scanf("%d\n",&t);

			if (t == 1)
				continue;
			else
				break;
		}
	}

	return 0;	
}
