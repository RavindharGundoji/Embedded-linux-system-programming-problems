#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int fd, bytes;
	char file_name[30], buffer[1024];
	printf("Enter a csv file name : ");
	scanf("%s", file_name);
	getchar();
	fd  = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
	}while((bytes = read(fd, buffer, sizeof(buffer)-1)) > 0){
		buffer[bytes] = '\0';
		printf("%s", buffer);
	}if(bytes == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("\n\n-------------FILE-END----------------\n");
	close(fd);
	return 0;
}
