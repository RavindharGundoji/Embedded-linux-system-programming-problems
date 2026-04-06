#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
int main(){
	int s, d, status;
	char source[20], distention[20], str[20];
	printf("Enter a source's file name : ");
	scanf("%s", source);
	printf("Enter a distention's file name : ");
	scanf("%s", distention);
	s = open(source, O_RDONLY);
	if(s == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}d = open(distention, O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if(d == -1){
		close(d);
		printf("%s\n", strerror(errno));
		exit(1);
	}while((status = read(s, str, sizeof(str))) >  0){
		write(d, str, status);
	}printf("File successfuly coped\n");
	close(s);
	close(d);
	return 0;
}
