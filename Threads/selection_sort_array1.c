#include<stdio.h>
#include<pthread.h>
int size;
void *thread_fun(void *arg){
	int temp, i, j, min_inx, *arr = (int*)arg;
	for(i = 0; i < size-1; i++){
		min_inx = i;
		for(j = i+1; j < size; j++){
			if(arr[j] < arr[min_inx]){
				min_inx = j;
			}
		}temp = arr[min_inx];
		arr[min_inx] = arr[i];
		arr[i] = temp;
	}
}int main(){
	printf("Enter a size of array : ");
	scanf("%d", &size);
	int arr[size], i;
	printf("Enter a elements : ");
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, arr);
	pthread_join(ti, NULL);
	printf("selection sorting\n");
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}printf("\n");
	return 0;
}
