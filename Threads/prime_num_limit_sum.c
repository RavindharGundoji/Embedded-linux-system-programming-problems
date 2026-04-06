#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_fun(void *num){
	int is_pri, i, j = 1;
	int *sum = malloc(sizeof(int));
	*sum = 0;
	for(i = 2; i < *(int*)num; i++){
		is_pri = 1;
		for(j = 2; j*j <= i; j++){
			if(i % j == 0){
				is_pri = 0;
				break;
			}
		}if(is_pri){
			*sum += i;
		}
	}pthread_exit((void*)sum);
}int main(){
	pthread_t ti;
	int num, *sum;
	printf("Enter a upto range : ");
	scanf("%d", &num);
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, (void**)&sum);
	printf("Sum of all prime number from 0 to %d : %d\n", num, *sum);
	return 0;
}
