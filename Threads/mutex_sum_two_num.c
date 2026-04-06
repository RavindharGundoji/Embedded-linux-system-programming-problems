#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
int num_g = 10;
void *thread_fun(void *num){
	pthread_mutex_lock(&lock);
	num_g = num_g + *(int*)num;
	printf("Number : %d\n", num_g);
	pthread_mutex_unlock(&lock);
}int main(){
	int num;
	pthread_t ti_1, ti_2;
	printf("Enter to add : ");
	scanf("%d", &num);
	pthread_create(&ti_1, NULL, thread_fun, &num);
	pthread_create(&ti_2, NULL, thread_fun, &num);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	return 0;
}
