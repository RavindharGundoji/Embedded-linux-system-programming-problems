#include<stdio.h>
#include<pthread.h>
void *thread_fun(void *arg){
	int i = 0, prev = 0, curr = 1, next = 0;
	while(next < *(int*)arg){
		printf("%d ", next);
		prev = curr;
		curr = next;
		next = curr + prev;
	}printf("\n");
	return NULL;
}int main(){
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &num);
	pthread_join(ti, NULL);
	return 0;
}
