#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *num){
	int count = 0, i = 1;
	int *ret_val = (int*)num;
	int num_f = *ret_val;
	*ret_val = 0;
	while(i < num_f){
		if(num_f % i == 0){
			(*ret_val)++;
		}i++;
	}return (void*)ret_val;
}int main(){
	int num;
	void* ret_val;
	pthread_t ti;
	printf("Enter a number  : ");
	scanf("%d", &num);
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, &ret_val);
	num = *(int*)ret_val;
	if(num == 1){
		printf("It is prime number\n");
	}else{
		printf("It is not prime number\n");
	}return 0;
}
