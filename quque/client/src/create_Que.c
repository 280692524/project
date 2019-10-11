#include<sys/msg.h>
#include<sys/ipc.h>
#include "create_Que.h"
#include "log.h"
//#define PATH "/tmp"
//#define PROJ_ID 32


int create_Que(char *path,int proj_id)
{
	int id = -1;
	key_t key = -1;

	if(proj_id == 0)
	{
		
		/*ftok函数生成键值*/
		if(-1 == (key = ftok(path,proj_id)))
		{
			log_print(LOG_ERROR,"create key fail error = %d %s\n",errno,strerror(errno));
			return -1;
		}
		/*msgget函数创建消息队列*/
		if(-1 == (id = msgget(key,IPC_CREAT | 0666)))
		{
			log_print(LOG_ERROR,"open msg error =%d %s\n",errno,strerror(errno));
			return -1;
		}
		else
		{
			log_print(LOG_ERROR,"create quque succeed id = %d\n",id);
			return id;	/*返回id*/
		}
	}
	if(proj_id == 1)
	{
		/*ftok函数生成键值*/
		if(-1 == (key = ftok(path,proj_id)))
		{
			log_print(LOG_ERROR,"create key fail error = %d %s\n",errno,strerror(errno));
			return -1;
		}
		/*msgget函数创建消息队列*/
		if(-1 == (id = msgget(key,IPC_CREAT | 0666)))
		{
			log_print(LOG_ERROR,"open msg error =%d %s\n",errno,strerror(errno));
			return -1;
		}
		else
		{
			log_print(LOG_ERROR,"create quque succeed id = %d\n",id);
			return id;	/*返回id*/
		}
	}

}