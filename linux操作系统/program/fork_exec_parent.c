#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    const char *usr_envp[ ] = { "MYDEFINE=unknown" , "PATH=/tmp" , (char *)0 };

    printf ("Begin fork()\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        perror("fork failed");
        exit(1);
    case 0:
        if (execle( "/tmp/child1" , "child1" , "myarg1" , "my arg2" , (char *)0 , usr_envp )<0)
              perror("execle failed");
        break;
    default:
        break;
    }
    if (waitpid (pid, NULL, 0) < 0)
        perror("waitpid failed");
    printf ("parent exiting\n");
    exit(0);
}
