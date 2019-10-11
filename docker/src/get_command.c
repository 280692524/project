#include<string.h>
#include<stdio.h>
#include<stdlib.h>


int get_command(char *p,char *q)  //该函数为获取命令所得的信息，并保存起来.同时检测版本号去下载软件
{
		/*yum list docker-ce --showduplicates | sort -r  参数1  */
		/*19.03.2   参数2  */

	char *str1 = p;
	char *str2 = q;
	
	FILE *read_fp;								/*popen的读文件句柄*/
	FILE *write_fp;								/*fopen的打开文件句柄*/
	FILE *fp;									/*fopen的检测文件是否可读句柄*/
	
	char buffer[ BUFSIZ + 1];
	char filename[] = "docker.txt";				/*文件名*/
	char StrLine[1024];             			/*每行最大读取的字符数*/
	char LineBuffer[1024];						/*暂存的行数内容*/
	
	int chars_read;
	int chars_write;
	
	memset(buffer,'\0',sizeof(buffer));			/*将buffer清空*/

	/*********************************
	获取该命令下的版本号
	并打开文件写入获取的版本号信息
	*********************************/
	if(!strcmp(str1,"yum list docker-ce --showduplicates | sort -r"))
	{
		read_fp = popen(str1,"r");				/*将str读入管道*/
		write_fp = fopen("docker.txt","w+");	/*创建文件对str1进行信息写入*/
		if(read_fp != NULL)
		{
			chars_read = fread(buffer,sizeof(char),BUFSIZ,read_fp);
			while(chars_read>0)
			{
				buffer[chars_read -1]='\0';
				printf("%s \n",buffer);
				chars_read = fread(buffer,sizeof(char),BUFSIZ,read_fp);
				chars_write = fwrite(buffer,1,sizeof(buffer),write_fp);
			}
			pclose(read_fp);
			fclose(write_fp);
		}
	}
    if((fp = fopen(filename,"r")) == NULL) 		/*判断文件是否存在及可读*/
    { 
         printf("error!"); 
         return -1; 
    }
		
    while (!feof(fp)) 							/*读到文件尾返回真值“1”   否则返回“0”*/
    {
		 int line = 0;
		 int N = 1;
		 while(1)
		 {
			 fgets(LineBuffer,1024,fp);
			 N++;
			 if(N == 13)
				 break;
		 }//暂存不需要的内容
		 fgets(StrLine,38,fp);						/*读取一行（只读38）*/
		 printf("你输入的版本号：%s\n",str2);		 
		 char str[15]={0};							/*防止越界，数组可设置大*/
		 line++;  									/*获取第一行版本号，line加一*/
		 char *Mystr;
	 	 Mystr = strstr(StrLine,str2);				/*获取冒号以后的字符串*/
		 snprintf(str,15,Mystr);					/*将冒号之后的内容获取到str里*/
		 if(!strcmp(str2,str))
		 {
			char *a = (char*)malloc(sizeof(char*)*50);/*为获取的命令申请内存空间*/
			char *ystr = "yum install docker-ce-";
			sprintf(a,"%s%s",ystr,str);				/*将获得的版本号进行拼接*/
			printf("即将为你安装的是：%s\n",a);
			system(a); 								/*将获取的版本号进行yum安装*/
			free(a);								/*释放内存空间*/
			
			if(line == 1)							/*执行完第一个版本号后退出*/
				break;								
		 }
		 else
		 {
			 printf("%s版本过低或不存在，请查看后再输入\n",str2);
			 return -1;
		 }
 	
    }
    fclose(fp);                     /*关闭文件*/
	return 0;
}
	/*yum list docker-ce --showduplicates | sort -r  参数1*/
	/*19.03.2   参数2*/
