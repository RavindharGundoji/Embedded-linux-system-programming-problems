#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i, j;
	for(i = 1; i < 11; i++){
		for(j = i; j >= 1; j--){
			printf("%d ", j);
		}printf("\n");
	}pthread_exit(NULL);
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
