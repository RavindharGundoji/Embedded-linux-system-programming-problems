#include<stdio.h>
#include<pthread.h>
int MAX = 100000;
int num_g = 0;
pthread_mutex_t lock;
void *increment(void *arg){
	int i;
	for(i = 0; i < MAX; i++){
		pthread_mutex_lock(&lock);
		num_g++;
		pthread_mutex_unlock(&lock);
	}pthread_exit(NULL);
}int main(){
	pthread_t ti_1, ti_2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti_1, NULL, increment, NULL);
	pthread_create(&ti_2, NULL, increment, NULL);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	pthread_mutex_destroy(&lock);
	printf("After increment by 2 threads : %d\n", num_g);
	return 0;
}
