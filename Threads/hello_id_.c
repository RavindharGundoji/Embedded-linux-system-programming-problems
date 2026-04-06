#include<stdio.h>
#include<pthread.h>
void *thread_fun1(void *arg){
	int ti_1 = (unsigned int)pthread_self();
	printf("Thread id : %d and string : %s\n", ti_1, (char*)arg);
	pthread_exit(NULL);
}void *thread_fun2(void *arg){
	int ti_2 = (unsigned int)pthread_self();
	printf("Thread id : %d and string : %s\n", ti_2, (char*)arg);
	pthread_exit(NULL);
}int main(){
	pthread_t ti_1, ti_2;
	pthread_create(&ti_1, NULL, thread_fun1, "Hello ");
	pthread_create(&ti_2, NULL, thread_fun2, "World!");
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	return 0;
}
