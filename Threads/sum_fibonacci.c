#include<stdio.h>
#include<pthread.h>
int sum = 0;
void *thread_fun(void *arg){
	int limit = *(int*)arg;
	int prev = 0, curr = 1, next = 0;
	while(curr < limit){
		sum += curr;
		next = prev + curr;
		prev = curr;
		curr = next;
	}return NULL;
}int main(){
	int limit;
	void *ret_val;
	printf("Enter a limit : ");
	scanf("%d", &limit);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, &limit);
	pthread_join(ti, NULL);
	printf("Sum of fibonacci 0 to %d : %d\n", limit, sum);
	return 0;
}
