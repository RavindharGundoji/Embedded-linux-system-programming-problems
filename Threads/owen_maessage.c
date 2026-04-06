#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun1(void *arg){
	char *sptr;
	sptr = (char*)arg;
	printf("%s\n",sptr);
	return (void*)(long)strlen(sptr);
}void *thread_fun2(void *arg){
	printf("%s\n", (char*)arg);
	return(void*)(long)strlen((char*)arg);
}int main(){
	void *ret_val1, *ret_val2;
	pthread_t ti_1, ti_2, ti_3;
	pthread_create(&ti_1, NULL, thread_fun1, "Thread number 1");
	pthread_create(&ti_2, NULL, thread_fun1, "Thread number 2");
	pthread_join(ti_1, &ret_val1);
	pthread_join(ti_2, &ret_val2);
	printf("Program is executed\n");
	return 0;
}
