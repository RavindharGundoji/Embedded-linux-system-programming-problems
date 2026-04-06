#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
void *thread_fun(void *arg){
	int len = *(int*)arg;

	unsigned int seed = time(NULL) ^ (unsigned)(uintptr_t)pthread_self();
	char *str = malloc(sizeof(len+1));
	size_t charset_len = strlen(charset);

	for(int i = 0; i < len; i++){
		int index = rand_r(&seed) % charset_len;
		str[i] = charset[index];
	}str[len] = '\0';

	pthread_exit(str);
}int main(void){
	int length = 10;
	char *password;
	pthread_t ti;

	pthread_create(&ti, NULL, thread_fun, &length);
	pthread_join(ti, (void**)&password);

	printf("Password : %s\n", password);
	free(password);

	return 0;
}
