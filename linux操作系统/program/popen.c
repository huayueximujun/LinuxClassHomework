/* popen.c */
#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
//#include <fcntl.h>
#define BUFSIZE 1000

int main()
{
	FILE *fp;
	char *cmd = "ps -ef";
	char buf[BUFSIZE];

	if( ( fp = popen( cmd , "r" ) ) == NULL )
		perror( "fopen" );
	while( ( fgets( buf , BUFSIZE , fp ) ) != NULL )
		printf( "%s" , buf );
	pclose( fp );
	exit( 0 );
}
