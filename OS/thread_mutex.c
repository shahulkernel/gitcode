



#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *messageprintf2( void * msg);
void *messageprintf1( void * msg);


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;


int main()
{
	pthread_t thread1;
	pthread_t thread2;
	char* m1 = "Thread1";
	char* m2 = "Thread2";

	printf("\n");
	pthread_create( &thread1,NULL, messageprintf1,(void *) m1);
	pthread_create( &thread2,NULL, messageprintf2, (void *)m2);
//	pthread_create( &thread1,NULL, print_message_function, (void*) message1);


	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);


	printf("all done");


	getchar();
	return 0 ;
}



void * messageprintf2( void * msg)
{

	char *m = (char*)msg;

	
	for (int i = 2; i <= 10; i=i+2)
	{
		pthread_mutex_lock(&mutex1);
		printf("\t t2: %d",i);
		fflush(stdout);
		pthread_cond_signal(&cond1);
		pthread_cond_wait(&cond1,&mutex1);
		pthread_mutex_unlock(&mutex1);
	}

	return NULL;
}
void * messageprintf1( void * msg)
{

	char *m = (char*)msg;
	
	for (int i = 1; i < 10; i=i+2)
	{
		pthread_mutex_lock(&mutex1);
		printf("\t t1: %d",i);
		fflush(stdout);
		pthread_cond_signal(&cond1);
		pthread_cond_wait(&cond1,&mutex1);
		pthread_mutex_unlock(&mutex1);
	}
	return NULL;
}
