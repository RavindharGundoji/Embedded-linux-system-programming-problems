#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_fun(void *num){
	int i, *sum;
	sum = malloc(sizeof(int));
	*sum = 1;
	for(i = 1; i <= 5; i++){
		*sum = *sum * i;
	}
	pthread_exit((void*)sum);
}int main(){
	int num_l;
	int *ret_val;
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &num_l);
	pthread_join(ti, (void**)&ret_val);
	printf("Squre of : %d\n", *ret_val);
	return 0;
}
