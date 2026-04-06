#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int num1, num2;
void *thread_fun(void* arg){
	int *div = malloc(sizeof(int));
	*div = num1 % num2;
	pthread_exit((void*)div);
}int main(){
	int *num;
	printf("Enter a two numbers : ");
	scanf("%d%d", &num1, &num2);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, (void**)&num);
	if(!(*num)){
		printf("Given numbers is divisible\n");
	}else{
		printf("Given numbers is not divisible\n");
	}free(num);
	return 0;
}
