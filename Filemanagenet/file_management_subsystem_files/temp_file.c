#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char file_name[50] = "/home/sai-naveen/Desktop/linux/files/tempXXXXXX", str[50], str1[50];
	int fd, status;
	/*printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();*/
	fd = mkstemp(file_name);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	write(fd, str, strlen(str));
	status = lseek(fd, 0, SEEK_SET);
	if(status == -1){
		printf("%s\n", strerror(errno));
		close(fd);
		exit(1);
	}status = read(fd, str1, sizeof(str));
	if(status == -1){
		printf("%s\n", strerror(errno));
		close(fd);
		exit(1);
	}else{
		str1[status] = '\0';
	}printf("string : %s", str1);
	close(fd);
	unlink(file_name);
	return 0;
}
