/* forktest.c */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t result;
	int n = 6;
	
	result = fork();
	
	if(result ==  -1)
	{
		printf("Fork error\n");
	}
	else if (result == 0)
	{
		n++;
		printf( "In child process!! n = %d\n" , n );
	}
	else 
	{
		n--;
		printf("In father process!! n = %d\n" , n );
	}
	
	return result;
}
