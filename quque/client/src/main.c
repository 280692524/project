#include<sys/msg.h>
#include<sys/ipc.h>

#include "IPC_Recv.h"
#include "create_Que.h"
#include "kill_Que.h"
#include "log.h"
/*执行接收主函数*/
int main(int argc,char *argv[])
{

	/*初始化日志*/
	//log_init("./client.log",NORMAL_LEVER, 1);
	//log_print(LOG_ERROR,"Hello world");
	/*日志关闭*/
	//log_close();
	
	char path[512] = {0};
	int proj_id = 0;
	int id = 0;
	id = create_Que(path,proj_id);
	IPC_Recv(id);
	kill_Que(id);
	
	return 0;
}