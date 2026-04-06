#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX_BUFFER 5
int buffer[MAX_BUFFER];
int count = 0;
pthread_mutex_t lock;
pthread_cond_t cond_full;
pthread_cond_t cond_empty;
void *producer(void *arg){
	int item = 0;
	while(item <= 10){
		pthread_mutex_lock(&lock);
		while(count == MAX_BUFFER){
			pthread_cond_wait(&cond_empty, &lock);
		}buffer[count] = item;
		count++;
		printf("producer : %d Buffer count : %d\n", item, count);
		item++;
		pthread_cond_signal(&cond_full);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}pthread_exit(NULL);
}void *consumer(void *arg){
	int item;
	while(1){
		pthread_mutex_lock(&lock);
		while(count == 0){
			pthread_cond_wait(&cond_full, &lock);
		}item = buffer[count-1];
		count--;
		printf("consumer : %d Buffer count : %d\n", item, count);
		pthread_cond_signal(&cond_empty);
		pthread_mutex_unlock(&lock);
		if(item == 10){
			break;
		}sleep(2);
	}pthread_exit(NULL);
}int main(){
	pthread_t ti_1, ti_2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti_1, NULL, producer, NULL);
	pthread_create(&ti_2, NULL, consumer, NULL);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
