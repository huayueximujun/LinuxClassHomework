/* msgrcv.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define  BUFFER_SIZE		512

struct message
{
	long msg_type;
	char msg_text[BUFFER_SIZE];
};

int main()
{
	int qid;
	key_t key;
	struct message msg;
	
	if ((key = ftok(".", 'a')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	
	if ((qid = msgget(key, IPC_CREAT|0666)) == -1)
	{
		perror("msgget");
		exit(1);
	}
	printf("Open queue %d\n", qid);
	
	do
	{
		memset(msg.msg_text, 0, BUFFER_SIZE);
		if (msgrcv(qid, (void*)&msg, BUFFER_SIZE, 0, 0) < 0)
		{
			perror("msgrcv");
			exit(1);
		}
		printf("The message from process %ld : %s", msg.msg_type, msg.msg_text);		
		
	} while(strncmp(msg.msg_text, "quit", 4));
	
	
	if ((msgctl(qid, IPC_RMID, NULL)) < 0)
	{
		perror("msgctl");
		exit(1);
	}
	
	exit(0);
}
