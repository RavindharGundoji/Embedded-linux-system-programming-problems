#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
int main(){
	int fd, bytes;
	char buffer[1024];
	const char *file_name = "./input_files/myfifo";
	fd = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}while((bytes = read(fd, buffer, sizeof(buffer)-1)) > 0){
		buffer[bytes] = '\0';
		printf("%s\n", buffer);
	}if(bytes == -1){
		printf("%s\n", strerror(errno));
		close(fd);
		exit(1);
	}close(fd);
	printf("Read of myfifo file is successfully\n");
	return 0;
}
