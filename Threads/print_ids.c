#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *st){
	char *str = (char*)st;
	printf("%s", str);
	printf("%lu\n", (unsigned long)pthread_self());
	return NULL;
}int main(){
	pthread_t ti_1, ti_2;
	pthread_create(&ti_1, NULL, thread_fun, "Thread 1 ID : ");
	pthread_create(&ti_2, NULL, thread_fun, "Thread 2 ID : ");
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	printf("Main thread id : %lu\n", (unsigned long)pthread_self());
	return 0;
}
