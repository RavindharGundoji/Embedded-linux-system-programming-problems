#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
int main(){
	char str[30];
	DIR *status;
	printf("Enter a directory : ");
	scanf("%s", str);
	status = opendir(str);
	if(status == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}else{
		printf("Directory exist\n");
	}closedir(status);
	return 0;
}
