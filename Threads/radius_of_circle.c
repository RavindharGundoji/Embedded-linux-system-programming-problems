#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *thread_fun(void *arg){
	int di = *(int*)arg;
	int *radius = malloc(sizeof(int));
	*radius = di/2;
	pthread_exit((void*)radius);
}int main(){
	int di, *radius;
	printf("Enter diameter : ");
	scanf("%d", &di);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &di);
	pthread_join(ti, (void**)&radius);
	printf("Radius of circle : %d\n", *radius);
	return 0;
}
