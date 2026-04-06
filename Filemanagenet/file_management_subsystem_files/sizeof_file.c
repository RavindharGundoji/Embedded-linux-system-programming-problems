#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
	int status;
	char file_name[20];
	struct stat st;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	status = stat(file_name, &st);
	if(status != 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("size of file : %ld\n", st.st_size);
	return 0;
}
