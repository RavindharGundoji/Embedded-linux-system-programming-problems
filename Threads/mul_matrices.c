#include<stdio.h>
#include<pthread.h>
int insert(int row, int col, int arr[row][col]){
	int i, j;
	for(i = 0; i < col; i++){
		for(j = 0; j < row; j++){
			scanf("%d", &arr[i][j]);
		}
	}return 0;
}void *thread_fun(void *arg){
	int row, col;
	printf("Enter a col and row : ");
	scanf("%d%d", &row, &col);
	int arr1[row][col];
	int arr2[row][col];
	int arr[row][col], i , j;
	printf("Enter a elements in 1st array : ");
	insert(row, col, arr1);
	printf("Enter a elements in 2st array : ");
	insert(row, col, arr2);
	for(i = 0; i < col; i++){
		for(j = 0; j < row; j++){
			arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}for(i = 0; i < col; i++){
		for(j = 0; j < row; j++){
			printf("%d ", arr[i][j]);
		}printf("\n");
	}return NULL;
}int main(){
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	return 0;
}
