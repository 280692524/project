#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#include "IPC_Send.h"
#include "create_Que.h"
#include "kill_Que.h"


/*执行发送主函数*/
int main()
{
	int id = 0;
	id = create_Que();
	IPC_Send(id);
	kill_Que(id);
	return 0;
}