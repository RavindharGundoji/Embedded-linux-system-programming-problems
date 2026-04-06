#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
int fd_s, fd_d;;
void *thread_fun(void *arg){
	char ch;
	int len = *(int*)arg;
	while((read(fd_s, &ch, sizeof(char))) > 0){
		write(fd_d, &ch, sizeof(char));
	}printf("coped succefully\n");
	pthread_exit(NULL);
}int main(int argc, char* argv[]){
	int file_size;
	if(argc != 3){
		printf("user: cp <sourec_file> <destination_file>\n");
		exit(1);
	}fd_s = open(argv[1], O_RDONLY);
	if(fd_s < 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}fd_d = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0640);
	if(fd_d < 0){
		close(fd_s);
		printf("%s\n", strerror(errno));
		exit(1);
	}pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, NULL);
	pthread_join(ti, NULL);
	}return 0;
}
