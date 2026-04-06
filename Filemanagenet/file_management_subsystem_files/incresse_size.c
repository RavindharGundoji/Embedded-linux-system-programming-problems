#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int resize, status;
	char file_name[30];
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	printf("Enter a resize number : ");
	scanf("%d", &resize);
	getchar();
	status = truncate(file_name, resize);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("File size incresed successfully\n");
	return 0;
}
