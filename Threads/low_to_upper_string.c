#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun(void *arg){
	char *str = (char*)arg;
	int i;
	for(i = 0; str[i]; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] = str[i] - 32;
		}
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
	printf("%s\n", str);
	return 0;
}
