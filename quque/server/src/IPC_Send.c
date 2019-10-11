#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include "kill_Que.h"

#define BUF_SIZE 512    
#define SERVER_MSG 1
#define TRUE 1
/***********************************************************************
**函数：IPC_Send
**功能：服务端发送数据
**参数：无

**返回值：
        错误返回 -1
************************************************************************/
typedef struct __MSG_BUF_INFO__{
    long int mtype;
    char msg[BUF_SIZE];
}MSG_BUF_INFO,*LPMSG_BUF_INFO;

int IPC_Send(int id)
{
    int msglen;
    MSG_BUF_INFO msg_buf_info;
	
	msglen = sizeof(MSG_BUF_INFO) - sizeof(msg_buf_info.mtype);

	while(TRUE)
	{
		memset(msg_buf_info.msg,0,msglen);

		fgets(msg_buf_info.msg,sizeof(msg_buf_info.msg),stdin);
        //msgbuf.msg[strlen(msgbuf.msg)] = '\0';
        msg_buf_info.mtype = SERVER_MSG;
		
		int ret = msgsnd(id, (void *)&msg_buf_info, msglen, IPC_NOWAIT);
        if(ret < 0)
		{
			printf("Server msgsnd error!   ret: %d\n",ret);
            return 0;
        }

        if(0 == strncmp(msg_buf_info.msg, "QUIT", 4))
		{
			printf("消息队列已退出\n");
			exit(0);
        }
		
	}
}