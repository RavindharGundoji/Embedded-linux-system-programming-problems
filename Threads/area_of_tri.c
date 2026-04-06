#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *thread_fun(void *arg){
	int base, highet;
	int *area = malloc(sizeof(int));
	printf("Enter a base and highet : ");
	scanf("%d%d", &base, &highet);
	*area = 0.5 * base * highet;
	return (void*)area;
}int main(){
	void *area;
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, &area);
	printf("Area of triangle : %d\n", *(int*)area);
	free(area);
	return 0;
}
