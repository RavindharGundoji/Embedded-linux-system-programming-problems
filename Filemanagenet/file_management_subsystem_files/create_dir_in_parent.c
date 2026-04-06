#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
int main(){
	char dir[10], str[50] = "../";
	int status;
	printf("Enter a directory : ");
	scanf("%s", dir);
	strcat(str, dir);
	status = mkdir(str, 0755);
	if(status != 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Directory created successfully\n");
	return 0;
}
