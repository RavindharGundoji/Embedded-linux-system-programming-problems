#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>//mkdir
#include<sys/types.h>//mode in mkdir()
int main(){
	int status;
	char str[20];
	printf("Enter a directory name : ");
	scanf("%s", str);
	status = mkdir(str, 0755);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("%s directory is successfuly crated\n", str);
	return 0;
}
