#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i, sum = 0;
	for(i = 1; i < 101; i++){
		sum += (i * i);
	}printf("Sum of all sqr 1 to 100 : %d\n", sum);
	return NULL;
}
int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
