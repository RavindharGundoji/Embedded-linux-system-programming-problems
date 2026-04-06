#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *num){
	int is_pri, i, j = 1;
	for(i = 2; i < *(int*)num; i++){
		is_pri = 1;
		for(j = 2; j*j <= i; j++){
			if(i % j == 0){
				is_pri = 0;
				break;
			}
		}if(is_pri){
			printf("%d is prime number\n", i);
		}
	}
}int main(){
	pthread_t ti;
	int num;
	printf("Enter a upto range : ");
	scanf("%d", &num);
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, NULL);
	return 0;
}
