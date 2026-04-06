#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
int main(){
	int status;
	const char *file_name = "./input_files/myfifo";
	status = mkfifo(file_name, 0666);
	if(status == -1 || status == EEXIST){
		printf("%s\n", strerror(errno));
	}printf("Created successfully\n");
	return 0;
}
