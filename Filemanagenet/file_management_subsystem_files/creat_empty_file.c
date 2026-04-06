#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(){
	char path[50];
	int fd;
	printf("Enter a path to create empty file : ");
	scanf("%s", path);
	fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0640);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}if(truncate(path, 1) == -1){
		printf("%s\n", strerror(errno));
		close(fd);
		exit(1);
	}printf("Created empty file\n");
	close(fd);
	return 0;
}
