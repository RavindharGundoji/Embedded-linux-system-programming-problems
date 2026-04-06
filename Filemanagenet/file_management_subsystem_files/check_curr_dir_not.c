#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int *status;
	char path[1024];
	getcwd(path, sizeof(path));
	if(status == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Current working directory : %s\n", path);
	return 0;
}
