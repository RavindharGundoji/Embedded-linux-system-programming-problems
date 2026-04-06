#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i, sum = 0; 
	for(i = 1; i < 101; i++){
		if(i % 2 == 0){
			sum += i;
		}
	}printf("Sum of even : %d\n", sum);
	return NULL;
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
