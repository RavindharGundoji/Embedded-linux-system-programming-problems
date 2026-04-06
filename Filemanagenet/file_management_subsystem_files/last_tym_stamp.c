#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
int main(){
	char file_name[20];
	int status;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	struct stat st;
	status = stat(file_name, &st);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Size of file %s : %s", file_name, ctime(&st.st_mtime));
	return 0;
}
