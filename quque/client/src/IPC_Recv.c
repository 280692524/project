#include<sys/msg.h>
#include<sys/ipc.h>
#include "log.h"

#define BUF_SIZE 512
#define SERVER_MSG 1
#define TRUE 1
/***********************************************************************
**函数：IPC_Recv
**功能：客户端接收数据
**参数：无

**返回值：
        错误返回 -1
************************************************************************/

/*typedef struct __MSG_CONTROL_INFO__
{
	unsigned char	operator_type; 
	int				content_length;        //内容长度 
    char			*content;             //内容
}MSG_CONTROL_INFO,*LPMSG_CONTROL_INFO;*/



typedef struct __MSG_BUF_INFO__
{
    long int mtype;
    char msg[BUF_SIZE];
}MSG_BUF_INFO,*LPMSG_BUF_INFO;


int IPC_Recv(int id)
{
    int msglen;
	MSG_BUF_INFO msg_buf_info;
	msglen = sizeof(MSG_BUF_INFO) - sizeof(msg_buf_info.mtype);
	
	
	//msg_buf_info = (LPMSG_BUF_INFO)malloc(sizeof(MSG_BUF_INFO));
	//msg_buf_info->lpmsg_control_info->content = malloc(msg_buf_info->lpmsg_control_info->content_length);
	
	while(TRUE)
	{
		/*接收server消息*/
		int ret = msgrcv(id, (void *)&msg_buf_info, msglen, SERVER_MSG, 0);
        if(ret < 0)
		{
			printf(LOG_ERROR,"Recv from server error!   ret= : %d %d %s\n",ret,errno,strerror(errno));
            return -1;
        }
        printf(LOG_ERROR,"Recv from server : %s %d %s\n", msg_buf_info.msg,errno,strerror(errno));
		//free(msg_buf_info->lpmsg_control_info->content);
		//free(msg_buf_info);
        /*if(0 == strncmp(lpmsg_control_info.content, "QUIT", 4))
		{
			printf("消息队列已退出\n");
            break;
        }*/
	}
}