#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define PATH "/tmp"
#define PROJ_ID 32


int create_Que(char *ip_addr,int num)
{
	int id;
	key_t key;
	if(-1 == (key = ftok(PATH,PROJ_ID)))/*ftok函数生成键值*/
	{
		printf("create key fail\n");
		return -1;
	}
	if(-1 == (id = msgget(key,IPC_CREAT | 0666)))/*msgget函数创建消息队列*/
	{
		printf("create msg error \n");
		return -1;
	}
	
	else
	{
		printf("id %d\n",id);
		return id;
	}
}
