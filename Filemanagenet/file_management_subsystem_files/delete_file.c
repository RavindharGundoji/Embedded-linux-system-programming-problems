#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int main(){
	int status;
	char str[20];
	printf("Enter a file to delete : ");
	scanf("%s", str);
	status = unlink(str);
	if(status != 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("File is deleted successfuly\n");
	return 0;
}
