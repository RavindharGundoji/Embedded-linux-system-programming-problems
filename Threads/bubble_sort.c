#include<stdio.h>
#include<pthread.h>
int size;
void *thread_fun(void * arg){
	int *arr = (int*)arg;
	int i, j, temp;
	for(i = 0; i < size-1; i++){
		for(j = 0; j < size-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}return NULL;
}int main(){
	printf("Enter a size : ");
	scanf("%d", &size);
	int arr[size], i;
	printf("Enter a number in array : ");
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, arr);
	pthread_join(ti, NULL);
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}printf("\n");
	return 0;
}
