#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
int main(){
	char file_name[20];
	int status;
	mode_t pre;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	printf("Enter permissions : ");
	scanf("%o", &pre);
	status = chmod(file_name, pre);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Permissions changed successfully\n");
	return 0;
}
