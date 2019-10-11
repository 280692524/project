#include<sys/msg.h>
#include<sys/ipc.h>
#include "log.h"

int kill_Que(int id)
{
	if(-1 == (msgctl(id,IPC_RMID,NULL)))  /*删除id号的消息队列*/
	{
		log_print(LOG_ERROR,"del msg error %d %s\n",errno,strerror(errno));
		return -1;
	}
	return 0;
}