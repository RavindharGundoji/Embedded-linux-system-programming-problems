#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *num){
	int *inc = num, sum = 1;
	while(*inc != 0){
		sum *= *inc;
		(*inc)--;
	}printf("factorial : %d\n", sum);
	return NULL;
}int main(){
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, NULL);
	return 0;
}
