#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i;
	float sum = 0, avg;
	for(i = 1; i < 101; i++){
		sum += i;
	}avg = sum/100;
	printf("avg : %.2f\n", avg);
	return NULL;
}
int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
