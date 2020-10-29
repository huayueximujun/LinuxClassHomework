/* myfork.c */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t result;
	
	result = fork();
	
	if(result ==  -1)
	{
		printf("Fork error\n");
	}
	else if (result == 0)
	{
		printf("The return value is %d\nIn child process!!\nMy PID is %d\n",result,getpid());
		printf("The PPID of this process is %d\n",getppid());
		//while(1);
	}
	else 
	{
		printf("The return value is %d\nIn father process!!\nMy PID is %d\n",result,getpid());
		//wait();
		printf("The father process exit now.\n");
	}
	
	return result;
}
