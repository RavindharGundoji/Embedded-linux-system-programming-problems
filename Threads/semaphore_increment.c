#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int MAX = 100000;
int num_g = 0;
sem_t lock;
void *increment(void *arg){
	int i;
	for(i = 0; i < MAX; i++){
		sem_wait(&lock);
		num_g++;
		sem_post(&lock);
	}pthread_exit(NULL);
}int main(){
	pthread_t ti_1, ti_2;
	sem_init(&lock, 0, 1);
	pthread_create(&ti_1, NULL, increment, NULL);
	pthread_create(&ti_2, NULL, increment, NULL);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	sem_destroy(&lock);
	printf("After increment by 2 threads : %d\n", num_g);
	return 0;
}
