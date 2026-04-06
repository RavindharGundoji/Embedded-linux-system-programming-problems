#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(){
	char oldfile[20], newfile[20];
	int status;
	printf("Enter a old file name : ");
	scanf("%s", oldfile);
	printf("Enter a new file name : ");
	scanf("%s", newfile);
	status = rename(oldfile, newfile);
	if(status != 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("File is rename is successfuly\n");
	return 0;
}
