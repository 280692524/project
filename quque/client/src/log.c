#include "log.h"

/* 全局变量 */
int         dumpLevel = 2;
int         uselog = 1;
int         log_fd = -1;

int log_init(const char *log_name, int log_level, int use_log)
{
    if(use_log == 1)
    {
        log_fd = open(log_name,O_CREAT | O_APPEND | O_RDWR,0777);
        if(-1 == log_fd)
        {
            fprintf(stderr,"open log file (%s) fail %s\n",log_name,strerror(errno) );
            return -1;
        }
    }
    dumpLevel = log_level;
    uselog = use_log;
    return log_fd;
}

void log_close()
{
    close(log_fd);
    log_fd = -1;
}

/***********************************************************************
**函数：log_print
**功能：打印消息
**参数：
        [in] eventdump_Level - log日志等级
        [in] file - 编译时的文件名
        [in] line - 编译时的行号
        [in] format - 要打印的各个信息
**返回值：
        无
************************************************************************/
 void log_print(int eventdump_Level, char* file, int line, char * format, ...)
{
    va_list va_ap;
    /* level小于等于2，即warning 和 error会打印出消息 */
    if(eventdump_Level <= dumpLevel)
    {
        char buf[MAX_BUFF_SIZE] = {0};
        char out_buf[OUT_PUT_BUFF_SIZE] = {0};
        char theDate[TIME_STRING_SIZE] = {0};
        int  out_buff_len = 0;
        int  write_offset = 0;
        int  write_len = 0;
        char *extra_msg = "";
        time_t theTime = time(NULL);
        /* 清空缓冲区 */
        memset(buf, 0, sizeof(buf));
        /* 获取当前时间 */
        strftime(theDate, TIME_STRING_SIZE, "%d/%b/%Y %H:%M:%S", localtime(&theTime));
        va_start (va_ap, format);
        vsnprintf(buf, sizeof(buf)-1, format, va_ap);
        va_end(va_ap);

        if(eventdump_Level == 0 /* TRACE_ERROR */)
        {
          extra_msg = "ERROR: ";
        }
        else if(eventdump_Level == 1 /* TRACE_WARNING */)
        {
          extra_msg = "WARNING: ";
        }
        else if(eventdump_Level == 4 /* TRACE_WARNING */)
        {
          extra_msg = "DEBUG: ";
        }
        /* 最后一个字符为换行符，替换成'\0' */
        while(buf[strlen(buf)-1] == '\n') buf[strlen(buf)-1] = '\0';
        out_buff_len = snprintf(out_buf, sizeof(out_buf), "%s [%11s:%4d] %s%s\n", theDate, file, line, extra_msg, buf);
        /* 是否写日志 */
        if(uselog)
        {
            do
            {
                /* 写到日志文件中 */
                write_len = write(log_fd,out_buf+write_offset,out_buff_len);
                write_offset += write_len;
                out_buff_len -= write_len;
            }while (out_buff_len);
        }
        else 
        {
            fprintf(stdout,"%s\n", out_buf);
            fflush(stdout);
        }
    }
}







