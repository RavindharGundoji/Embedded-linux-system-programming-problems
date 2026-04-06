#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	char file_name[20], ch;
	int count = 0, fd;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	fd = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}while(read(fd, &ch, 1) > 0){
		if(ch == '\n'){
			count++;
		}
	}printf("No of line in file : %d\n", count);
	close(fd);
	return 0;
}
