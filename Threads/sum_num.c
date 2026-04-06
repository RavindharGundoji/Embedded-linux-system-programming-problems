#include<stdio.h>
#include<pthread.h>
int num_g = 10;
void *thread_fun(void *num){
	//int *num_f = (int*)num;
	int sum = *((int*)num) + num_g;
	printf("Sum : %d\n", sum);
	return NULL;
}
int main(){
	int num = 10;
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, NULL);
	return 0;
}
