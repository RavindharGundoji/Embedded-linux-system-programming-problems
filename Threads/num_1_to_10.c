#include<stdio.h>
#include<string.h>
#include<pthread.h>
int num = 1;
void *thread_fun1(void *arg){
	int *num1 = (int*)arg;
	while(1){
		if(*num1 > 10){
			break;
		}printf("Number : %d\n", (*num1)++);
	}return NULL;
}void *thread_fun2(void *arg){
	int *num2 = (int*)arg;
	while(1){
		if(*num2 > 10){
			break;
		}printf("Number : %d\n", (*num2)++);
	}return NULL;
}int main(){
	int i;
	void *ret_1, *ret_2;
	pthread_t ti_1, ti_2;
	pthread_create(&ti_1, NULL, thread_fun1, &num);
	pthread_create(&ti_2, NULL, thread_fun2, &num);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	printf("Program executed\n");
	return 0;
}
