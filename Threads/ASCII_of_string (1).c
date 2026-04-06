#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun(void *arg){
	char *str = (char*)arg;
	int i;
	for(i = 0; str[i]; i++){
		printf("ASCII value of %c is %d\n", str[i], str[i]);
	}pthread_exit(NULL);
}int main(){
	int i;
	char str[30];
	printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, str);
	pthread_join(ti, NULL);
	return 0;
}
