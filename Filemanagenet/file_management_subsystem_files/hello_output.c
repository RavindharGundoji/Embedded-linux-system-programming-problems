#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(){
	int fd, ret;
	char str[20];
	fd = open("./input_files/hello.txt", O_RDONLY);
	if(fd <= -1){
		perror("error");
		exit(1);
	}ret = read(fd, str, sizeof(str));
	if(ret == 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}str[ret] = '\0';
	printf("String present in file : ");
	printf("%s", str);
	close(fd);
	return 0;
}
