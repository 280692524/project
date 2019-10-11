#ifndef _CREATE_QUE_H_
#define _CREATE_QUE_H_

typedef enum {
    SET_TIME = 0X01,
    SET_VOLUME = 0X02,
    PLAY_VOICE = 0X03,
    SET_DISPLAY_LIGHT = 0X04,
    SET_AD_DISPLAY = 0X05,
    SET_TMP_DISPLAY = 0X06
}CONTROL_TYPE;


extern int create_Que(char *path,int proj_id);

#endif