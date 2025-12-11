#include<stdio.h>
#include<unistd.h>

int main() 
{
	pid_t pid = fork();

	if(pid == 0)
	{
		// child process
		printf("child executing new program using exec.\n");
		execl("/bin/ls","ls",NULL);
		printf("This will not print if exec() succeeds.\n");
	
	}

	else {
	    //parent process
	    
		printf("parent process continues here.\n");
	}

	return 0;
}
