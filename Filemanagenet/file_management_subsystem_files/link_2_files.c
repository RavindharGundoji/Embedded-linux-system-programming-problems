#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
int main(){
	int status;
	char source[30], hardlink[30];
	printf("Enter a source file : ");
	scanf("%s", source);
	printf("Enter a hardlink file : ");
	scanf("%s", hardlink);
	status = link(source, hardlink);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Now inode of both files are same\n");
	return 0;
}
