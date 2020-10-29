
/* multi_proc.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
//https://blog.csdn.net/cuit2016123070/article/details/83280125
int main(void)
{
	pid_t child1, child2, child;
	
	
	child1 = fork();
		
	
	if (child1 == -1)
	{
		printf("进程一创建失败\n");
		exit(1);
	}
	else if (child1 == 0) 
	{
		printf("In child1: execute 'ls -l'\n");
		
		if (execlp("ls", "ls", "-l", NULL) < 0)
		{
			printf("Child1 execlp error\n");
		}
  	}
  	else 
  	{
  		child2 = fork();
  		if (child2 == -1) 
  		{
  			printf("子进程2创建失败\n");
  			exit(1);
  		}
  		else if( child2 == 0 ) 
  		{
  			printf("在子进程2之中: 睡眠5秒钟 然后退出\n");
  			sleep(5);
  			exit(1);
  		}
  		
  		printf("在父进程中:\n");
  		
  		child = waitpid(child1, NULL, 0);
  		if (child == child1)
  		{
  			printf("得到子进程1的退出代码\n");
  		}
  		else
  		{
  			printf("错误发生了!\n");
  		}
  		
  		do
  		{
  			child = waitpid(child2, NULL, WNOHANG );
  			
  			if (child == 0)
  			{
  				printf("子进程2还没有退出!\n");
  				sleep(1);
  			}
  		} while (child == 0);
  		
  		if (child == child2)
  		{
  			printf("Get child2 exit code\n");
  		}
  		else
  		{
  			printf("Error occured!\n");
  		}
  	}
  	
  	exit(0);
}
