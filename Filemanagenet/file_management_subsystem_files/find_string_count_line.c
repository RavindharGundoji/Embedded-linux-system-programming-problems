#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int fd, ret, found = 0, i , j, new_line = 0, line[30];
	char str[1024], given_str[1024], file_name[30];
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	printf("Enter the string to search : ");
	scanf("%s", given_str);
	fd = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}while((ret = read(fd, str, sizeof(str))) > 0){
		str[ret] = '\0';
		new_line++;
		if((strstr(str, given_str)) != NULL){
			found = 1;
			line[j] = new_line;
			j++;
		}
	}if(!found){
		printf("Given string is not pressent in string\n");
	}else{
		printf("Given string is present in string in line : ");
			for(i = 0; i < j; i++){
			printf("%d ", line[i]);
		}printf("\n");
	}close(fd);
	return 0;
}
