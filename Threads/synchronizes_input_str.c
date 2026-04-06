#include<stdio.h>
#include<pthread.h>
#include<string.h>
#define SIZE 100
char buffer[SIZE];
pthread_mutex_t lock;
void *thread_fun(void *arg){
	printf("Enter a string : ");
	pthread_mutex_lock(&lock);
	fgets(buffer, SIZE, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	pthread_mutex_unlock(&lock);
	return NULL;
}int main(){
	pthread_t ti;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	pthread_mutex_lock(&lock);
	printf("Buffer shared memorey string : %s\n", buffer);
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
	return 0;
}
