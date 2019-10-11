#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>

/***********************************************************
IPC_RMID:删除消息队列
IPC_STAT:取此队列的msqid_ds结构，并将它存放在buf指向的结构中
IPC_SET :改变消息队列的状态，把buf所指的msqid_ds结构中的
		 uid、gid、mode复制到消息队列的msqid_ds结构内
************************************************************/
int kill_Que(int id)
{
	if(-1 == (msgctl(id,IPC_RMID,NULL)))  /*删除id号的消息队列*/
	{
		printf("del msg error \n");
		return -1;
	}
	return 0;
}