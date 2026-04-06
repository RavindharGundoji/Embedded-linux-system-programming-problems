#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *thread_fun(void *arg){
	char *str = (char*)arg;
	int *len = malloc(sizeof(int));
	*len = strlen(str)-1;
	pthread_exit((void*)len);
}int main(){
	char str[30];
	int *ret_val;
	printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, str);
	pthread_join(ti, (void**)&ret_val);
	printf("Length of string : %d\n", *ret_val);
	free(ret_val);
	return 0;
}
