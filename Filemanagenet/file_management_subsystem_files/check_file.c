#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	char str[20];
	printf("Enter a file name : ");
	scanf("%s", str);
	fd = open(str, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}else{
		printf("File presented in directory\n");
	}return 0;
}
