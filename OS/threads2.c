



#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *messageprintf( void * msg);



int main()
{
	pthread_t thread1;
	pthread_t thread2;
	char* m1 = "Thread1";
	char* m2 = "Thread2";


	pthread_create( &thread1,NULL, messageprintf,(void *) m1);
	pthread_create( &thread2,NULL, messageprintf, (void *)m2);
//	pthread_create( &thread1,NULL, print_message_function, (void*) message1);


	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);


	printf("all done");


	getchar();
	return 0 ;
}



void * messageprintf( void * msg)
{

	char *m = (char*)msg;

	printf("\n msg rcvd %s",m);

	return NULL;
}
