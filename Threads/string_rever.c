#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *thread_fun(void *arg){
	char *str = (char*)arg;
	int j = strlen(str)-1;
	int  i = 0;
	char temp;
	while(i < j){
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}pthread_exit(NULL);
}int main(){
	char str[20];
	printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	void *rev_str;
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, str);
	pthread_join(ti, NULL);
	printf("Revresed string : %s\n", str);
	return 0;
}
