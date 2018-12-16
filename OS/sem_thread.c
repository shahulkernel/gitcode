



#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int arr[5] = {0,0,0,0,0};
int outa[5] = {10,23,34,45,56};
sem_t con;
int in = 0;
int out = 0;
int cnt = 0;
pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t con1 = PTHREAD_COND_INITIALIZER;

void consume1()
{

	while(1)
	{
		pthread_mutex_lock(&mut1);			
		pthread_cond_wait(&con1, &mut1);
		if ( in != out )
		{
		sleep (2);
		sem_wait(&con);			
		printf("\n consume1 %d",arr[out]);
		out++;
		if(out >= 5)
			out = 0;
		cnt--;			
		pthread_cond_signal(&con1);
		sem_post(&con);
		}
		pthread_mutex_unlock(&mut1);			
	}	
	return;
}


void consume2()
{

	while(1)
	{
		pthread_mutex_lock(&mut1);			
		fflush(stdout);
		pthread_cond_wait(&con1, &mut1);
		if ( in != out )
		{
		sleep (2);
		sem_wait(&con);
		printf("\n consume2 %d",arr[out]);
		out++;
		if(out >= 5)
			out = 0;
		cnt--;
		pthread_cond_signal(&con1);
		sem_post(&con);
		}
		pthread_mutex_unlock(&mut1);			
	}
	return;
}


void produce()
{

	
	while (1)
	{

		printf("\n produce %d",outa[in]);
		fflush(stdout);
		pthread_mutex_lock(&mut1);			


		if ( cnt == 5)
		{
			printf("waiting to produce cnt %d",cnt);
			pthread_cond_wait(&con1, &mut1);
		}

		sem_wait(&con);
		arr[in] = outa[in];
		in++;
		if (in >= 5)
			in = 0;
		cnt++;
		sem_post(&con);
		pthread_mutex_unlock(&mut1);
		pthread_cond_signal(&con1);
	}


	return;
}



int main()
{

	pthread_t t1;
	pthread_t t2;

	
	sem_init(&con,0,2);
	pthread_mutex_init(&mut1,NULL);
	pthread_cond_init(&con1,NULL);
	pthread_create(&t1,NULL,(void*) consume1,(void*)NULL);
	pthread_create(&t2,NULL,(void*)consume2,(void*)NULL);

	produce();


	return 0;
}
