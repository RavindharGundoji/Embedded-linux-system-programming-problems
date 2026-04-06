#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread_fun(void *arg){
	while(1){
		printf("infinite loop running\n");
		sleep(1);
		pthread_testcancel();
	}pthread_exit(NULL);
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	sleep(5);
	pthread_cancel(ti);
	pthread_join(ti, NULL);
	return 0;
}
