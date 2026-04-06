#include<stdio.h>
#include<pthread.h>
int is_leap;
pthread_mutex_t lock;
void *thread_fun(void *arg){
	int year = *(int*)arg;
	pthread_mutex_lock(&lock);
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		is_leap = 1;
	}else{
		is_leap = 0;
	}pthread_mutex_unlock(&lock);
	return NULL;
}int main(){
	int year;
	printf("Enter a year : ");
	scanf("%d", &year);
	pthread_t ti;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti, NULL, thread_fun, &year);
	pthread_join(ti, NULL);
	if(is_leap){
		printf("Give %d is leap year\n", year);
	}else{
		printf("Given %d is not leap year\n", year);
	}pthread_mutex_destroy(&lock);
	return 0;
}
