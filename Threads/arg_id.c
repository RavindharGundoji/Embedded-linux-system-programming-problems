#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun1(void *arg){
	int ti_1 = (unsigned int)pthread_self();
	printf("Thread id : %d and string : %s\n", ti_1, (char*)arg);
	pthread_exit(NULL);
}void *thread_fun2(void *arg){
	int ti_2 = (unsigned int)pthread_self();
	printf("Thread id : %d and string : %s\n", ti_2, (char*)arg);
	pthread_exit(NULL);
}int main(){
	char str1[30], str2[30];
	printf("Enter a string for thread one : ");
	fgets(str1, sizeof(str2), stdin);
	str1[strcspn(str1, "\n")] = '\0';
	printf("Enter a string for thread two : ");
	fgets(str2, sizeof(str2), stdin);
	str2[strcspn(str2, "\n")] = '\0';
	pthread_t ti_1, ti_2;
	pthread_create(&ti_1, NULL, thread_fun1, str1);
	pthread_create(&ti_2, NULL, thread_fun2, str2);
	pthread_join(ti_1, NULL);
	pthread_join(ti_2, NULL);
	return 0;
}
