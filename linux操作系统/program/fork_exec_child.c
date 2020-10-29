#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char *argv[ ] )
{
    int i;
    char **pStr;
    extern char **environ;
   
    printf ("child starting\n");
    for ( i = 0; i < argc; i++)
       printf (" argv[%d] : %s\n", i, argv[i]);
    for ( pStr = environ; *pStr != 0 ; pStr++)
       printf ("%s\n", *pStr);
    printf ("child exiting\n");
    exit(0);
}
