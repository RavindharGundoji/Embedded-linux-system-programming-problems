#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *num){
	int *ret_val = (int*)num;
	*ret_val = (*ret_val) * (*ret_val);
	return (void*)ret_val;
}int main(){
	int num_l;
	void *ret_val;
	printf("Enter a number : ");
	scanf("%d", &num_l);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &num_l);
	pthread_join(ti, &ret_val);
	printf("Squre of : %d\n", *(int*)ret_val);
	return 0;
}
