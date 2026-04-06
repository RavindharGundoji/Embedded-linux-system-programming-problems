#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
int main(){
	char path[300];
	printf("Enter a path : ");
	scanf("%s", path);
	struct stat file_stat;
	if(lstat(path, &file_stat) == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}if(S_ISREG(file_stat.st_mode)){
		printf("Given path is regural file\n");
	}else if(S_ISDIR(file_stat.st_mode)){
		printf("Given path is directory\n");
	}else if(S_ISLNK(file_stat.st_mode)){
		printf("Given path is symboil link\n");
	}else if(S_ISCHR(file_stat.st_mode)){
		printf("Given path is characte device\n");
	}else if(S_ISBLK(file_stat.st_mode)){
		printf("Given path is blocking device\n");
	}else if(S_ISFIFO(file_stat.st_mode)){
		printf("Given path is FIFO(name file)\n");
	}else if(S_ISSOCK(file_stat.st_mode)){
		printf("Given path is socket\n");
	}else{
		printf("Given path is wornge\n");
	}return 0;
}
