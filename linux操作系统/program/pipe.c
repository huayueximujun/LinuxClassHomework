
/*pipe.c*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	static const char mesg[] = "Hello world!";	
	int	pipefd[2];
	pid_t	pid;
	char    buf[BUFSIZ];
	size_t  l,n;

	if (pipe(pipefd) < 0)
		perror("pipe error");

	if ( (pid = fork()) < 0)
		perror("fork error");
	else if (pid > 0) {		/* parent */
	    	printf("PIPE(parent): Read end = fd %d, write end = fd %d\n",pipefd[0], pipefd[1]);
		close(pipefd[0]);
		l = strlen(mesg);
		if (write(pipefd[1], mesg, l) != l) {
			fprintf(stderr, "%s: write failed: %s\n", argv[0],
			strerror(errno));
			exit(1);
	        }
        	printf("Write <%s> to pipe\n", mesg);
        	close(pipefd[1]);
	}else {				/* child */
	    	printf("PIPE(child): Read end = fd %d, write end = fd %d\n",pipefd[0], pipefd[1]);
		close(pipefd[1]);
 	    	n = read(pipefd[0], buf, BUFSIZ);
	    	buf[n] = '\0';
	    	printf("Read <%s> from pipe\n", buf);
        	close(pipefd[0]);
	}
	exit(0);
}
