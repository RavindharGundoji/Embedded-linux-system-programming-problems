#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char old[20], new[20];
	int status;
	printf("Enter old directory : ");
	scanf("%s", old);
	printf("Enter new directory : ");
	scanf("%s", new);
	status = rename(old, new);
	if(status != 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Successfully coped\n");
	return 0;
}
