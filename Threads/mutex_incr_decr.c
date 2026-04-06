#include<stdio.h>
#include<pthread.h>
int num_g = 500000;
pthread_mutex_t lock;
void *thread_fun1(void *inc){
	int size = *(int*)inc;
	int i;
	for(i = 0; i <= size; i++){
		pthread_mutex_lock(&lock);
		num_g++;
		pthread_mutex_unlock(&lock);
	}return NULL;
}void *thread_fun2(void *dec){
	int size = *(int*)dec;
	int i;
	for(i = 0; i <= size; i++){
		pthread_mutex_lock(&lock);
		num_g--;
		pthread_mutex_unlock(&lock);
	}return NULL;
}int main(){
	int inc, dec;
	printf("Enter a value to increment : ");
	scanf("%d", &inc);
	printf("Enter a value to decrement : ");
	scanf("%d", &dec);
	pthread_t ti_1, ti_2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti_1, NULL, thread_fun1, &inc);
	pthread_create(&ti_2, NULL, thread_fun2, &dec);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	pthread_mutex_destroy(&lock);
	printf("Number after  modificatoin : %d\n", num_g);
	return 0;
}
