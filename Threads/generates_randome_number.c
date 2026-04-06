#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
void *thread_fun(void *arg){
	unsigned int seed = (unsigned int)time(NULL);
	int rand_num = rand_r(&seed);
	printf("Randome number : %d\n", rand_num);
	pthread_exit(NULL);
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
