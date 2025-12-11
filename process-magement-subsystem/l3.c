#include<stdio.h>
#include<unistd.h>

int main() 
{
	int x=10;

	pid_t pid =fork();


	if(pid < 0)
	{
		// fork () failed 
	printf(" Fork failed ! \n");

	return 1;
	}

 
     else if(pid == 0)
	{
		printf("child process is running . \n");

		x = 20;

		printf("value of x is = %d\n",x);

		printf("  PID = %d\n", getpid());
		printf("  PPID = %d\n", getppid());
	}

	else
	{
		printf("parent process is running . \n");

		printf("%d \n",x);

		printf("   PID    = %d\n", getpid());
		printf("   child PID  = %d\n",pid);
	}

	printf("This line is executed by both parent and child . \n");

	return 0;
}
