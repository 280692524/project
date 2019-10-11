#include "onvif_test.h"






void soap_perror(struct soap *soap, const char *str)
{
    if (NULL == str) {
        SOAP_DBGERR("%s[%s\t%d] [soap] error: %d, %s, %s\n",__TIME__,__FILE__,__LINE__,soap->error, *soap_faultcode(soap), *soap_faultstring(soap));
    } else {
        SOAP_DBGERR("%s[%s\t%d] [soap] %s error: %d, %s, %s\n",__TIME__,__FILE__,__LINE__, str, soap->error, *soap_faultcode(soap), *soap_faultstring(soap));
    }
    return;
}

void* ONVIF_soap_malloc(struct soap *soap, unsigned int n)
{
    void *p = NULL;

    if (n > 0) 
    {
        p = soap_malloc(soap, n);
        if(p == NULL)
        {
            memset(p, 0 ,n);
        }
    }
    return p;
}

struct soap *ONVIF_soap_new(int timeout)
{
    struct soap *soap = NULL;                                                   // soap环境变量

    if(NULL == (soap = soap_new()))
    {
        printf("[%s/%d] soap is NULL",__FILE__,__LINE__);
    }
    soap_set_namespaces(soap, namespaces);                                      // 设置soap的namespaces
    soap->recv_timeout    = timeout;                                            // 设置超时（超过指定时间没有数据就退出）
    soap->send_timeout    = timeout;
    soap->connect_timeout = timeout;

#if defined(__linux__) || defined(__linux)                                      // 参考https://www.genivia.com/dev.html#client-c的修改：
    soap->socket_flags = MSG_NOSIGNAL;                                          // To prevent connection reset errors
#endif

    soap_set_mode(soap, SOAP_C_UTFSTRING);                                      // 设置为UTF-8编码，否则叠加中文OSD会乱码

    return soap;
}

void ONVIF_soap_delete(struct soap *soap)
{
    soap_destroy(soap);                                                         // remove deserialized class instances (C++ only)
    soap_end(soap);                                                             // Clean up deserialized data (except class instances) and temporary data
    soap_done(soap);                                                            // Reset, close communications, and remove callbacks
    soap_free(soap);                                                            // Reset and deallocate the context created with soap_new or soap_copy
}

/************************************************************************
**函数：ONVIF_init_header
**功能：初始化soap描述消息头
**参数：
        [in] soap - soap环境变量
**返回：无
**备注：
    1). 在本函数内部通过ONVIF_soap_malloc分配的内存，将在ONVIF_soap_delete中被释放
************************************************************************/
void ONVIF_init_header(struct soap *soap)
{
    struct SOAP_ENV__Header *header = NULL;
    if(NULL == soap)
    {
        return ;
    }
    header = (struct SOAP_ENV__Header *)ONVIF_soap_malloc(soap, sizeof(struct SOAP_ENV__Header));
    /* 消息头结构体初始化 */
    soap_default_SOAP_ENV__Header(soap, header);
    header->wsa__MessageID = (char*)soap_wsa_rand_uuid(soap);
    header->wsa__To = (char*)ONVIF_soap_malloc(soap, SOAP_TO_LENGTH);
    header->wsa__Action = (char*)ONVIF_soap_malloc(soap, SOAP_ACTION_LENGTH);
    memcpy(header->wsa__To,SOAP_TO,SOAP_TO_LENGTH);
    memcpy(header->wsa__Action,SOAP_ACTION,SOAP_ACTION_LENGTH);
    soap->header = header;
    return;
}

/************************************************************************
**函数：ONVIF_init_ProbeType
**功能：初始化探测设备的范围和类型
**参数：
        [in]  soap  - soap环境变量
        [out] probe - 填充要探测的设备范围和类型
**返回：
        0表明探测到，非0表明未探测到
**备注：
    1). 在本函数内部通过ONVIF_soap_malloc分配的内存，将在ONVIF_soap_delete中被释放
************************************************************************/
void ONVIF_init_ProbeType(struct soap *soap, struct wsdd__ProbeType *probe)
{
    /* 用于描述查找哪类的Web服务 */
    struct wsdd__ScopesType *scope = NULL;
    if( NULL == soap || NULL == probe)
    {
        soap_perror(soap,NULL);
        return ;
    }
    /* 申请内存 */
    scope = (struct wsdd__ScopesType *)ONVIF_soap_malloc(soap, sizeof(struct wsdd__ScopesType));
    if(NULL == scope)
    {
        soap_perror(soap,"scope malloc fail");
        return ;
    }
    /* 设置寻找设备的范围 */
    soap_default_wsdd__ScopesType(soap, scope);
    scope->__item = (char*)ONVIF_soap_malloc(soap, SOAP_ITEM_LENGTH);
    memcpy(scope->__item,SOAP_ITEM,SOAP_ITEM_LENGTH);
    memset(probe, 0x00, sizeof(struct wsdd__ProbeType));
    soap_default_wsdd__ProbeType(soap, probe);
    probe->Scopes = scope;
    /* 设置寻找设备的类型 */
    probe->Types  = (char*)ONVIF_soap_malloc(soap, SOAP_TYPES_LENGTH);
    memcpy(probe->Types,SOAP_TYPES,SOAP_TYPES_LENGTH);
    return;
}

/************************************************************************
**函数：ONVIF_SetAuthInfo
**功能：设置认证信息
**参数：
        [in] soap     - soap环境变量
        [in] username - 用户名
        [in] password - 密码
**返回：
        0表明成功，非0表明失败
**备注：
************************************************************************/
 int ONVIF_SetAuthInfo(struct soap *soap, const char *username, const char *password)
{
    int result = 0;
    if( NULL == username || NULL == password )
    {
        return -1;
    }
    result = soap_wsse_add_UsernameTokenDigest(soap, NULL, username, password);
    SOAP_CHECK_ERROR(result, soap, "add_UsernameTokenDigest");
EXIT:
    return result;
}

/*
* 打印搜索到的设备的信息
*
*
*/

void print_Msg( struct __wsdd__ProbeMatches resp)
{
    printf("===========================================\n");
    printf("sizeProbeMatch:%d\n",resp.wsdd__ProbeMatches->__sizeProbeMatch);
    printf("MetadataVersion:%d\n",resp.wsdd__ProbeMatches->ProbeMatch->MetadataVersion);
    printf("item:%s\n",resp.wsdd__ProbeMatches->ProbeMatch->Scopes->__item);
    printf("QName:%s\n",resp.wsdd__ProbeMatches->ProbeMatch->Types);
    printf("xsd:string:%s\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.Address);
    printf("xsd:QName:%p\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.PortType);
    printf("wsa:ServiceNameType:%p\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.ServiceName);
    printf("sequence of elements:%d\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.__size);
    printf("xsd:anyType:%s\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.__anyAttribute);
    printf("endpoint any:%p\n",resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.__any);
    printf("wsdd:UriListType:%s\n",resp.wsdd__ProbeMatches->ProbeMatch->XAddrs);
    printf("===========================================\n");	

}
/************************************************************************
*打印出获取设备的基本信息
*
*   
************************************************************************/
void print_baseMsg( struct _tds__GetDeviceInformationResponse resp )
{                
    printf("================= + dump_tds__GetDeviceInformationResponse + >>>\n");
    printf("Manufacturer:%s\t\t\n",resp.Manufacturer);
    printf("Model:%s\t\t\n",resp.Model);
    printf("Serial Number:%s\t\t\n",resp.SerialNumber);
    printf("Hardware Id:%s\t\t\n",resp.HardwareId);
    printf("Firmware Version%s\t\t\n",resp.FirmwareVersion);
    printf("================= - dump_tds__GetDeviceInformationResponse - <<<\n");
}
/*************************************************************************
**函数：ONVIF_DetectDevice
**功能：搜索设备,获得设备服务地址
**参数：[in] void (*cb)    -函数指针
**返回：无
*************************************************************************/
void ONVIF_DetectDevice(void (*cb)(char *DeviceXAddr))
{
    int i;
    int result = 0;
    /* 搜索到的设备个数 */
    unsigned int count = 0;
    /* soap环境变量 */
    struct soap *soap = NULL;
    /* 用于发送Probe消息 */
    struct wsdd__ProbeType      req;
    /* 用于接收Probe应答 */
    struct __wsdd__ProbeMatches rep;
    struct wsdd__ProbeMatchType *probeMatch;
    /*  */
    if( NULL== (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)) )
    {
        soap_perror(soap,"soap");
        return ;
    }
    /* 初始化消息头 */
    ONVIF_init_header(soap);
    /* 设置寻找的设备的范围和类型 */
    ONVIF_init_ProbeType(soap, &req);
    /* 向组播地址广播Probe消息 */
    result = soap_send___wsdd__Probe(soap, SOAP_MCAST_ADDR, NULL, &req);
    /* 开始接收设备发送过来的消息 */
    if (SOAP_OK == result)
    {
        memset(&rep, 0, sizeof(rep));
        /* 接收设备返回的消息 */
        result = soap_recv___wsdd__ProbeMatches(soap, &rep);
        if (SOAP_OK == result)
        {
            if (soap->error) 
            {
                soap_perror(soap, "ProbeMatches");
            }
            else
            {      
                /* 成功接收到设备的应答消息 */
                if (NULL != rep.wsdd__ProbeMatches) 
                {
                    count += rep.wsdd__ProbeMatches->__sizeProbeMatch;
                    for(i = 0; i < rep.wsdd__ProbeMatches->__sizeProbeMatch; i++) 
                    {
                        probeMatch = rep.wsdd__ProbeMatches->ProbeMatch + i;
                        if (NULL != cb) 
                        {
                            /* 使用设备服务地址执行函数回调 */
                            cb(probeMatch->XAddrs);                           
                        }
                    }
                }
            }
        }
        else if (soap->error) 
        {
        }
    }
    SOAP_DBGLOG("\ndetect end! It has detected %d devices!\n", count);
    if (NULL != soap) 
    {
        ONVIF_soap_delete(soap);
    }
    return ;
}


/************************************************************************
**函数：ONVIF_GetDeviceInformation
**功能：获取设备基本信息
**参数：
        [in] DeviceXAddr - 设备服务地址
**返回：
        0表明成功，非0表明失败
**备注：
************************************************************************/
int ONVIF_GetDeviceInformation(const char *DeviceXAddr)
{
    int result = 0;
    struct soap *soap = NULL;
    struct _tds__GetDeviceInformation           devinfo_req;
    struct _tds__GetDeviceInformationResponse   devinfo_resp;

    if(NULL == DeviceXAddr)
    {
        return -1;
    }
    /* 设置收发超时时间 */
    if(NULL == (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)))
    {
        soap_perror(soap,"soap malloc fail");
        return -1;
    }
    /* 设置认证信息 */
    ONVIF_SetAuthInfo(soap, USERNAME, PASSWORD);
    /* 清空收发消息结构体 */
    memset(&devinfo_req, 0x00, sizeof(devinfo_req));
    memset(&devinfo_resp, 0x00, sizeof(devinfo_resp));
    /* 获取设备信息 */
    result = soap_call___tds__GetDeviceInformation(soap, DeviceXAddr, NULL, &devinfo_req, &devinfo_resp);
    /* 检查是否有错误 */
    SOAP_CHECK_ERROR(result, soap, "GetDeviceInformation");
    /* 打印设备信息 */
    print_baseMsg(devinfo_resp);
    
EXIT:
    if (NULL != soap)
    {
        ONVIF_soap_delete(soap);
    }
    return result;
}

/************************************************************************
**函数：ONVIF_GetSnapshotUri
**功能：获取设备图像抓拍地址(HTTP)
**参数：
        [in]  MediaXAddr    - 媒体服务地址
        [in]  ProfileToken  - the media profile token
        [out] PhotoUri   - 获取图像的uri
**返回：
        0表明成功，非0表明失败
**备注：
    1). 并非所有的ProfileToken都支持图像抓拍地址。举例：XXX品牌的IPC有如下三个配置profile0/profile1/TestMediaProfile，其中TestMediaProfile返回的图像抓拍地址就是空指针。
************************************************************************/
int ONVIF_GetSnapshotUri(const char *MediaXAddr, char *ProfileToken,char *lpPhotoUri)
{
    int result = 0;
    struct soap *soap = NULL;
    struct _trt__GetSnapshotUri         req;
    struct _trt__GetSnapshotUriResponse rep;

    if(NULL == MediaXAddr)
    {
        return -1;
    }
    if(NULL == (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)))
    {
        return -1;
    }

    ONVIF_SetAuthInfo(soap, USERNAME, PASSWORD);

    memset(&req, 0x00, sizeof(req));
    memset(&rep, 0x00, sizeof(rep));
    req.ProfileToken = ProfileToken;
    result = soap_call___trt__GetSnapshotUri(soap, MediaXAddr, NULL, &req, &rep);
    SOAP_CHECK_ERROR(result, soap, "GetSnapshotUri");


    result = -1;
    if (NULL != rep.MediaUri) {
        if (NULL != rep.MediaUri->Uri) {
            printf("shotUri is : %s\n",rep.MediaUri->Uri);
            memcpy(lpPhotoUri, rep.MediaUri->Uri, PHOTO_URI_PATTERN_LENGTH);
            result = 0;
            
        }
    }
EXIT:
    if (NULL != soap) {
        ONVIF_soap_delete(soap);
    }
    return result;
}

/****************************************************************
**函数：ONVIF_GetStreamUri

**功能：获取设备码流地址(RTSP)
**参数：
        [in]  MediaXAddr    - 媒体服务地址
        [in]  ProfileToken  - the media profile token
**返回：
        0表明成功，非0表明失败
**备注：
************************************************************************/
int ONVIF_GetStreamUri(const char *MediaXAddr, char *ProfileToken)
{

    int result = 0;
    struct soap *soap = NULL;
    struct tt__StreamSetup              ttStreamSetup;
    struct tt__Transport                ttTransport;
    struct _trt__GetStreamUri           req;
    struct _trt__GetStreamUriResponse   rep;
    if(NULL == MediaXAddr)
    {
        return -1;
    }
    if(NULL == (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)))
    {
        return -1;
    }
    /* 清零 */
    memset(&req, 0x00, sizeof(req));
    memset(&rep, 0x00, sizeof(rep));
    memset(&ttStreamSetup, 0x00, sizeof(ttStreamSetup));
    memset(&ttTransport, 0x00, sizeof(ttTransport));
    ttStreamSetup.Stream                = tt__StreamType__RTP_Unicast;
    ttStreamSetup.Transport             = &ttTransport;
    ttStreamSetup.Transport->Protocol   = tt__TransportProtocol__RTSP;
    ttStreamSetup.Transport->Tunnel     = NULL;
    req.StreamSetup                     = &ttStreamSetup;
    req.ProfileToken                    = ProfileToken;
    ONVIF_SetAuthInfo(soap, USERNAME, PASSWORD);
    /* 获取uri */
    result = soap_call___trt__GetStreamUri(soap, MediaXAddr, NULL, &req, &rep);
    SOAP_CHECK_ERROR(result, soap, "GetServices");
    result = -1;
    if (NULL != rep.MediaUri) {
        if (NULL != rep.MediaUri->Uri) {
        printf("URI RTSP is : %s\n",rep.MediaUri->Uri);
        result = 0;
        //open_rtsp(rep.MediaUri->Uri);
        }
    }
EXIT:
    if (NULL != soap) {
        ONVIF_soap_delete(soap);
    }
    return result;
}

/***************************************************************
**函数：UserGetProfiles
**功能：获取设备Profiles
**参数：[in] char *media：设备媒体地址
        [out] PhotoUri   - 获取图像的uri
**返回：成功返回0，不成功返回非0 
****************************************************************/
int UserGetProfiles(char *media,char *lpPhotoUri)
{
	int result=0 ;
	int i = 0;
	struct soap *soap = NULL;
	struct _trt__GetProfiles 		    req;
	struct _trt__GetProfilesResponse 	rep;
	if(NULL == (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)))
	{
	    return -1;
	}
	ONVIF_SetAuthInfo(soap, USERNAME, PASSWORD);

    memset(&rep, 0x00, sizeof(rep));
    memset(&req, 0x00, sizeof(req));
	/* 获取设备Profiles */
	result = soap_call___trt__GetProfiles(soap,media, NULL,&req,&rep);	
	SOAP_CHECK_ERROR(result, soap, "GetProfiles");
	if(result != -1)
	{
	    /* 循环获取Profiles */
		while(rep.Profiles!=NULL && i < rep.__sizeProfiles)
		{
			if(rep.Profiles[i].Name != NULL){
				printf("Profiles Name:%s  \n",rep.Profiles[i].Name);
			}
			
			    if(rep.Profiles[i].token!=NULL){
			  	printf("Profiles Token:%s\n",rep.Profiles[i].token);
			
			}
			ONVIF_GetStreamUri(media,rep.Profiles[i].token);
			ONVIF_GetSnapshotUri(media,rep.Profiles[i].token,lpPhotoUri);
			i++;
		}
	}

EXIT:
    if (NULL != soap) {
        ONVIF_soap_delete(soap);
    }
    return result;		
}




/************************************************************************
**函数：ONVIF_GetCapabilities
**功能：获取设备能力信息
**参数：
        [in] DeviceXAddr - 设备服务地址
        [out] PhotoUri   - 获取图像的uri
**返回：
        0表明成功，非0表明失败
**备注：
    1). 其中最主要的参数之一是媒体服务地址
************************************************************************/
int ONVIF_GetCapabilities(const char *DeviceXAddr,char *lpPhotoUri)
{
    int result = 0;
    struct soap *soap = NULL;
    struct _tds__GetCapabilities            req;
    struct _tds__GetCapabilitiesResponse    rep;

    if(NULL == DeviceXAddr)
    {
        return -1;
    }
    if(NULL == (soap = ONVIF_soap_new(SOAP_SOCK_TIMEOUT)))
    {
        return -1;
    }

    ONVIF_SetAuthInfo(soap, USERNAME, PASSWORD);

    memset(&req, 0x00, sizeof(req));
    memset(&rep, 0x00, sizeof(rep));
    result = soap_call___tds__GetCapabilities(soap, DeviceXAddr, NULL, &req, &rep);
    SOAP_CHECK_ERROR(result, soap, "GetCapabilities");    
    printf("Media -> XAddr = %s\n",rep.Capabilities->Media->XAddr);
    UserGetProfiles(rep.Capabilities->Media->XAddr,lpPhotoUri);
EXIT:

    if (NULL != soap) {
        ONVIF_soap_delete(soap);
    }
    return result;
}


void cb_discovery(char *DeviceXAddr)
{
    //int i = 0;
	//char cmd[GET_PHOTOS_CMD_PATTERN_LENGTH+PHOTO_URI_PATTERN_LENGTH];
	char PhotosRri[PHOTO_URI_PATTERN_LENGTH];
	ONVIF_GetDeviceInformation(DeviceXAddr);
	ONVIF_GetCapabilities(DeviceXAddr,PhotosRri);
	#if 0
	for(i = 0; i < GET_PHOTO_COUNT;i++)
	{
	    snprintf(cmd, GET_PHOTOS_CMD_PATTERN_LENGTH+PHOTO_URI_PATTERN_LENGTH,GET_PHOTOS_CMD_PATTERN,i,PhotosRri);
	    system(cmd);
	}
	#endif
}




int main()
{
    ONVIF_DetectDevice(cb_discovery);
    return 0;
}




