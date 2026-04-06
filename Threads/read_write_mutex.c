#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int fd_s, fd_d;
char ch;
int has_data = 0;
pthread_mutex_t lock;
pthread_cond_t cond_full, cond_empty;
void *thread_read(void* arg){
	int ret;
	while(1){
		pthread_mutex_lock(&lock);
		while(has_data == 1){
			pthread_cond_wait(&cond_empty, &lock);
		}ret = read(fd_s, &ch, 1);
		if(ret <= 0){
			has_data = -1;
			pthread_cond_signal(&cond_full);
			pthread_mutex_unlock(&lock);
			break;
		}has_data = 1;
		pthread_cond_signal(&cond_full);
		pthread_mutex_unlock(&lock);
	}pthread_exit(NULL);
}void *thread_write(void* arg){
	int ret;
	while(1){
		pthread_mutex_lock(&lock);
		while(has_data == 0){
			pthread_cond_wait(&cond_full, &lock);
		}if(has_data == -1){
			pthread_mutex_unlock(&lock);
			break;
		}write(fd_d, &ch, 1);
		has_data = 0;
		pthread_cond_signal(&cond_empty);
		pthread_mutex_unlock(&lock);
	}pthread_exit(NULL);
}int main(){
	fd_s = open("./input_file/ladakh_input.txt", O_RDONLY);
	if(fd_s < 0){
		close(fd_s);
		printf("%s\n", strerror(errno));
	}fd_d = open("./input_file/output_file.txt", O_WRONLY|O_CREAT|O_TRUNC, 0640);
	if(fd_d < 0){
		close(fd_s);
		printf("%s\n", strerror(errno));
	}pthread_t ti_r, ti_w;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&ti_r, NULL, thread_read, NULL);
	pthread_create(&ti_w, NULL, thread_write, NULL);
	pthread_join(ti_w, NULL);
	pthread_join(ti_r, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
