#include<stdio.h>
#include<time.h>
#include<pthread.h>
void *thread_fun(void* arg){
	time_t now;
	struct tm *local;
	time(&now);
	local = localtime(&now);
	printf("Current Time and Date : %s", asctime(local));
	return NULL;
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
