#include<stdio.h>
#include<string.h>
#include<stdlib.h>//exit();
#include<unistd.h>//creat();
#include<fcntl.h>//flags in creat
#include<errno.h>//errno
int main(){
	int fd, w;
	char str[20];
	fd = creat("./input_files/hello.txt", 0640);
	if(fd <= -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	w = write(fd, str, strlen(str));
	if(w <= 0){
		perror("Write opareted dosnt work\n");
	}close(fd);
	return 0;
}
