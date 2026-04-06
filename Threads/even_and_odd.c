#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i;
	for(i = 1; i <= 20; i++){
		if(i % 2 == 0){
			printf("even : %d\n", i);
		}else{
			printf("odd : %d\n", i);
		}
	}
	pthread_exit(NULL);
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
