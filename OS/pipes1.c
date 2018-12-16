



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>




int main()
{
	int pip[2];



	char buff[2][10] = {"shahul","shehzeen"};

	char recv[11];


	pipe(pip);


	write(pip[1],buff[1],sizeof(buff[1]));
	read(pip[0],recv,sizeof(recv));

	recv[11] = '\0';


	printf("recved %s", recv);



}
