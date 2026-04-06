#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
int main(){
	char file_name[256];
	struct stat file_stat;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	if(stat(file_name, &file_stat) == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("The number of hard links of %s is : %lu\n", file_name, file_stat.st_nlink);
	return 0;
}
