#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int size;
void *thread_fun(void *arg){
	int i;
	int *arr = (int*) arg;
	float sum = 0, *avg;
	avg = malloc(sizeof(float));
	for(i = 0; i < size; i++){
		sum += arr[i];
	}*avg = sum/size;
	pthread_exit((void*)avg);
}int main(){
	float *avg;
	int i;
	printf("Enter a size  : ");
	scanf("%d", &size);
	getchar();
	int arr[size];
	printf("Enter a elements : ");
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, arr);
	pthread_join(ti, (void**)&avg);
	printf("Avg of array : %.2f\n", *avg);
	free(avg);
	return 0;
}
