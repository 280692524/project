#ifndef _LOG_
#define _LOG_

#ifdef __cplusplus
extern "C"{
#endif


#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

#define ERROR_LEVER                        (0)
#define WARNING_LEVER                      (1)
#define NORMAL_LEVER                       (2)
#define INFO_LEVER                         (3)
#define DEBUG_LEVER                        (4)

#define LOG_ERROR                        0, __FILE__, __LINE__
#define LOG_WARNING                      1, __FILE__, __LINE__
#define LOG_NORMAL                       2, __FILE__, __LINE__
#define LOG_INFO                         3, __FILE__, __LINE__
#define LOG_DEBUG                        4, __FILE__, __LINE__

#define MAX_BUFF_SIZE                  (2048)
#define OUT_PUT_BUFF_SIZE              (1024)
#define TIME_STRING_SIZE               (100)



int log_init(const char *log_name, int log_level, int use_log);
void log_close();
void log_print(int eventdump_Level, char* file, int line, char * format, ...);







#ifdef __cplusplus
}
#endif

#endif

