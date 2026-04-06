#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
int main(){
	int status;
	char path[50];
	struct stat st;
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	status = stat(path, &st);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}if(S_ISREG(st.st_mode)){
		printf("Given path is file\n");
	}else if(S_ISDIR(st.st_mode)){
		printf("Given path is directory\n");
	}else{
		printf("Given path is not file or sirectory\n");
	}return 0;
}
