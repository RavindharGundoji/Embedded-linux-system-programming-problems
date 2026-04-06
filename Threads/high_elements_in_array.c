#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int size;
void *thread_fun(void *arg){
	int *arr = (int*)arg;
	int i;
	int *max = malloc(sizeof(int));
	*max = 0;
	for(i = 0; i < size; i++){
		if(*max < arr[i]){
			*max = arr[i];
		}
	}pthread_exit((void*)max);
}int main(){
	int *max;
	printf("Enter a size : ");
	scanf("%d", &size);
	getchar();
	int arr[size], i;
	printf("Enter a elemnts : ");
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, arr);
	pthread_join(ti, (void**)&max);
	printf("Max ememnts in array : %d\n", *max);
	return 0;
}
