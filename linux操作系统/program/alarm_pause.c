/* alarm_pause.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void myfunc( int sign_no )
{
	if( sign_no == SIGALRM )
		printf( "Time out!\n" );
}

int main()
{
	int ret;

	//signal( SIGALRM , myfunc );
	ret = alarm(5);
	pause();
	printf("I have been waken up. %d\n",ret);
}
