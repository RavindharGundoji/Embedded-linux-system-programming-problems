#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	printf("Given number : %d\n", num);
	pthread_exit(NULL);
}
int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
