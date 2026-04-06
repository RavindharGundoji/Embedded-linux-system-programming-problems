#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *thread_fun(void *arg){
	pthread_mutex_lock(&lock);
	printf("Hello world\n");
	pthread_mutex_unlock(&lock);
}int main(){
	pthread_t ti_1, ti_2;
	pthread_create(&ti_1, NULL, thread_fun, NULL);
	pthread_create(&ti_2, NULL, thread_fun, NULL);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	return 0;
}
