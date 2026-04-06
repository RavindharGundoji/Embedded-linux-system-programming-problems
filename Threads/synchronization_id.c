#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *thread_fun(void *arg){
	pthread_mutex_lock(&lock);
	printf("Id of %d : %lu\n", *(int*)arg, (unsigned long)pthread_self);
	pthread_mutex_unlock(&lock);
}int main(){
	int id_1 = 1, id_2 = 2;
	pthread_t ti_1, ti_2;
	//pthread_mutex_init(&lock, NULL);
	pthread_create(&ti_1, NULL, thread_fun, &id_1);
	pthread_create(&ti_2, NULL, thread_fun, &id_2);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	//pthread_mutex_destroy(&lock);
	return 0;
}
