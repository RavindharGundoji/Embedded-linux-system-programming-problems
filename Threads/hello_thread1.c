#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *thread_fun(void *arg){
	char *sptr;
	sptr = (char*)arg;
	printf("Thread : %s\n", sptr);
	return (void*)(long)strlen(sptr);
}int main(){
	int len;
	void *ret_val;
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, "hello_world");
	pthread_join(ti, &ret_val);
	len = (int)(long)ret_val;
	printf("length of string : %d\n", len);
	return 0;
}
