#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	char file_name[20], str[1024];
	int fd, status;
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	fd = open(file_name, O_WRONLY | O_APPEND);
	if(fd == -1){
		printf("%s", strerror(errno));
		exit(1);
	}printf("Enter a text : ");
	fgets(str, sizeof(str), stdin);
	status = write(fd, str, strlen(str));
	str[strcspn(str, "\n")] = '\0';
	if(status == -1){
		printf("%s", strerror(errno));
		exit(1);
	}printf("Append %s to file %s is successfully\n", str, file_name);
	close(fd);
	return 0;
}
