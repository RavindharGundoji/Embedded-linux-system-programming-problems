#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t lock;
void *print_descending(void *arg) {
	pthread_mutex_lock(&lock);
	printf("Numbers from 10 to 1:\n");
    	for (int i = 10; i >= 1; i--) {
        	printf("%d ", i);
    	}printf("\n");
    	pthread_mutex_unlock(&lock);
    	pthread_exit(NULL);
}int main(){
    	pthread_t tid;
    	pthread_mutex_init(&lock, NULL);
    	if (pthread_create(&tid, NULL, print_descending, NULL) != 0) {
        	perror("pthread_create failed");
        	exit(1);
    	}pthread_join(tid, NULL);
    	pthread_mutex_destroy(&lock);
	return 0;
}

