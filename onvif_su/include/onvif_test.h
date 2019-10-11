#ifndef _ONVIF_TEST_H_#define _ONVIF_TEST_H_#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>#include <stdlib.h>#include <assert.h>#include "soapH.h"#include "wsaapi.h"#include "soapStub.h"#include "wsseapi.h"
#ifdef WIN32#include <windows.h>#endif#define ONVIF_ADDRESS_SIZE 100//#define SOAP_ASSERT                             assert#define SOAP_DBGLOG                             printf#define SOAP_DBGERR                             printf#define USERNAME	                            "admin"#define PASSWORD	                            "admin"	#define SOAP_TO                                 "urn:schemas-xmlsoap-org:ws:2005:04:discovery"#define SOAP_TO_LENGTH                          (sizeof(SOAP_TO)-1)#define SOAP_ACTION                             "http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe"#define SOAP_ACTION_LENGTH                      (sizeof(SOAP_ACTION)-1)#define SOAP_MCAST_ADDR                         "soap.udp://239.255.255.250:3702"                       // onvif规定的组播地址#define SOAP_ITEM                               ""                                                      // 寻找的设备范围#define SOAP_ITEM_LENGTH                        (sizeof(SOAP_ITEM)-1)#define SOAP_TYPES                              "dn:NetworkVideoTransmitter"                            // 寻找的设备类型#define SOAP_TYPES_LENGTH                       (sizeof(SOAP_TYPES)-1)#define GET_PHOTO_COUNT                        (20)#define SOAP_SOCK_TIMEOUT                      (10)                                                    // socket超时时间（单秒秒）#define GET_PHOTOS_CMD_PATTERN                 ("wget -q -O ./photo/%d.jpg '%s'")#define GET_PHOTOS_CMD_PATTERN_LENGTH          (sizeof(GET_PHOTOS_CMD_PATTERN)-1)#define PHOTO_URI_PATTERN                      ("http://192.168.14.147:80/web/auto.jpg?-usr=admin&-pwd=admin&")#define PHOTO_URI_PATTERN_LENGTH               (sizeof(PHOTO_URI_PATTERN)+10)


/* socket超时时间（单秒秒） */#define SOAP_SOCK_TIMEOUT    (10)
#define SOAP_CHECK_ERROR(result, soap, str) \    do { \        if (SOAP_OK != (result) || SOAP_OK != (soap)->error) { \            soap_perror((soap), (str)); \            if (SOAP_OK == (result)) { \                (result) = (soap)->error; \            } \            goto EXIT; \        } \} while (0)
	

void* ONVIF_soap_malloc(struct soap *soap, unsigned int n);struct soap *ONVIF_soap_new(int timeout);void ONVIF_soap_delete(struct soap *soap);void ONVIF_init_header(struct soap *soap);void ONVIF_init_ProbeType(struct soap *soap, struct wsdd__ProbeType *probe);int ONVIF_SetAuthInfo(struct soap *soap, const char *username, const char *password);void print_Msg( struct __wsdd__ProbeMatches resp);void print_baseMsg( struct _tds__GetDeviceInformationResponse resp );void ONVIF_DetectDevice(void (*cb)(char *DeviceXAddr));int ONVIF_GetDeviceInformation(const char *DeviceXAddr);int ONVIF_GetSnapshotUri(const char *MediaXAddr, char *ProfileToken,char *lpPhotoUri);int ONVIF_GetStreamUri(const char *MediaXAddr, char *ProfileToken);int UserGetProfiles(char *media,char *lpPhotoUri);int ONVIF_GetCapabilities(const char *DeviceXAddr,char *lpPhotoUri);void cb_discovery(char *DeviceXAddr);

#ifdef __cplusplus
}#endif

#endif
