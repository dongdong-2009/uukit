/*
*******************************************************************************
**  Copyright (c) 2012, ���������޹�˾, All rights reserved.
**  ���ߣ����Ž�
**  ��ǰ�汾��v1.0
**  ��������: 2015.10.26
**  �ļ�˵��: nvr �ͻ���sdk ����
*******************************************************************************
*/

#ifndef __HWSDKTYPE_H__ 
#define __HWSDKTYPE_H__

#ifdef WIN32
// #include <windows.h>
#pragma pack(push)
#pragma pack(1)
#define PACK_ALIGN
#else
#define PACK_ALIGN	__attribute__((packed))
#endif

#define HWSDKC_VERSION    "v3.04"

#define NORMAL_FILENAME_LEN		80	// ��������·�����ļ�����, ���õĲ�����80 ���ֽ�
#define DATETIME_LEN			20		// "2012-11-18 10:20:28" �ĳ���

//
// �洢�ռ����
#define MAX_DISK_NUM 12
#define MAX_PART_NUM 4

#define HWSDK_RECORD_VERSION        0xAB01      // ¼������˰汾�������
#define HWSDK_RECORD_SEARCH_VERSION 0xAB01      // ¼�������汾��

// sdk ����ȫ�ִ�������;
typedef enum 
{
    CERROR_TYPE_GET_PARAM_FAILED        = 29,   // ��ȡ����ʧ�� 
    CERROR_TYPE_SET_PARAM_FAILED        = 30,   // ���ò���ʧ��

	CERROR_TYPE_CONNECT 		        = 511, 	// ����ʧ��(�������)
	CERROR_TYPE_SEND 			        = 512, 	// ����ʧ��(�������)	
	CERROR_TYPE_RECV 			        = 513, 	// ����ʧ��(�������)
	CERROR_TYPE_GET_MNG_HOST	        = 514,	// ��ȡ���������ʧ��(�������)	
	CERROR_TYPE_TIMEOUT 		        = 515, 	// ��ʱ(�ȴ����������س���)
	
	CERROR_TYPE_ISNOT_LOGIN 	        = 516, 	// �û�û��½(�������̳���)
	CERROR_TYPE_NOT_PERMISSION 	        = 517,	// Ȩ�޲���(�������̳���) 	
    CERROR_TYPE_STREAM_NOT_OPEN         = 518,  // ������Ƶʱ����Ƶ����û�д�(�������̳���)
    CERROR_TYPE_PARSE_XML_RES	        = 519,	// �������������صĽ������(���ݸ�ʽ����)
	CERROR_TYPE_BUFFER_SIZE		        = 520,	// ���岻��(�����������ռ���ͼƬ���ļ�)
	
	CERROR_TYPE_PARAM			        = 521,	// ��������
    CERROR_TYPE_REPLAY_TOO_MANY_USER    = 522,	// �ط�¼����û�̫����
	CERROR_TYPE_REPLAY_LAST_FILE        = 523,	// ���������һ��¼��

    CERROR_TYPE_CB_NO_THIS_DEV          = 601,  // �����߻ص�,�豸�б�û�����Ӧ�豸id��
    CERROR_TYPE_CB_NOT_OPEN_STREAM      = 602,  // ʵ�����ص�,û�д�ʵʱ��
    CERROR_TYPE_CB_NOT_IN_REPLAY        = 603,  // ¼��طŻص�,�ط�û�д�,������ֹͣ
    CERROR_TYPE_BUTT			        = 10000 // �Ƿ����������ȡֵ��Χ[511,10000) 
} HW_CERROR_TYPE_EN;

typedef enum 
{
	CE_CLIENT_INDEX 		= 1,	    // ���������ؿͻ��˵�index, APP ��Ҫ����;
	CE_WIFI_CONNECT_PROGESS = 2, 	    // ����wifi�Ľ���;
	CE_WIFI_IP				= 3, 	    // ĳ���豸������wifi ��IP ��ַ;
	CE_DEV_ONLINE			= 4,	    // �豸����;
	CE_DEV_OFFLINE			= 5,	    // �豸����;
	
	CE_DEV_SVR				= 6,	    // �豸��IP ��ַ������������P2P ��������IP ��ַ����ת����������ַ��ʽ����;
    CE_PLAYBACK_RES         = 7,        // �طſ��ƴ���ʱ���ش�����;
    CE_CHANNEL_STATE_LOW    = 8,        // NVR 0-31ͨ��״̬;
    CE_CHANNEL_STATE_HIGH   = 9,        // NVR 32-63ͨ��״̬;
	CE_MNG_IP				= 10,	    // �����������IP ��ַ�Ͷ˿�, APP ��Ҫ����;
    CE_CHANNEL_SWITCH       = 11,       // ʵʱ������ͨ��״̬,����P2P��ת��;
    CE_DEV_SLEEP            = 12,       // �豸����;
    CE_DEV_ELECTRICITY      = 13,       // �����豸����;
	CE__BUTT
} COM_EVENT_EN;

typedef enum 
{
	CD_UNVARNISHED_TRANSMISSION 		= 1,	    // ͸���豸�������������;
	CD_DEBUG_DATA,			// ��������, �ַ�������, ��APP ��Ļ��ӡ����(��Ƶ��P2P����ת��)��ʱ, �Ѹ�ָ��ص�����Ϣ��ӡ����Ļ��(��������Ƶ��P2P����ת��);
	CD__BUTT
} COM_DATA_EN;


typedef enum 
{
	PIC_TYPE_REALTIME 	= 1,	// ʵʱͼƬ, ���ڻ�ȡһ��ͼƬ;
	PIC_TYPE_ALARM 		= 2,	// ����ͼƬ;
	PIC_TYPE_PRESET		= 3,	// Ԥ��λ, ������ֻ���ڻص�ʱ���õ�;
} PIC_TYPE_EN;

typedef enum _PlaybackControlQt_
{
	RC_STOP 	    = 0,		// ֹͣ
	RC_PLAY		    = 1, 		// ����	
	RC_PAUSE	    = 2, 		// ��ͣ
	RC_FILE		    = 3,		// �϶�
	RC_SPEED	    = 4,		// ��ĳ���ٶȲ��� 
    RC_CONTINUNE    = 5,		// �������ţ���Ӧ RC_PAUSE 
    RC_SWITCH_CHN   = 6,        // �л�����
	RC_UNKNOW       = 100,	    // δ֪״̬,�����RC_STOP ���� RC_PLAY, �������б�Ϊ0, �����δ֪״̬
} REPLAY_CMD_EN;

typedef enum _PlaybackSpeedQt_
{
	PSQ_2   = 0,	    // ��� 2���ٶ�
	PSQ_4   = 1, 		// ��� 4���ٶ�
	PSQ_8   = 2, 		// ��� 8���ٶ�
	PSQ_16  = 3,		// ��� 16���ٶ�
	PSQ_1_2 = 4,	    // ��� 1/2 ���ٶ�
	
	PSQ_1_4 = 5,	// ��� 1/4 ���ٶ�
	PSQ_1_8 = 6,	// ��� 1/8 ���ٶ�
	PSQ_1_16 = 7,	// ��� 1/16 ���ٶ�
/* ��ʱ��֧�ֿ���
	PSQ_FB_2,	// ���� 2���ٶ�
	PSQ_FB_4, 	// ���� 4���ٶ�
	
	PSQ_FB_8, 	// ���� 8���ٶ�
	PSQ_FB_16,	// ���� 16���ٶ�
	PSQ_FB_1_2,	// ���� 1/2 ���ٶ�
	PSQ_FB_1_4,	// ���� 1/4 ���ٶ�
	PSQ_FB_1_8,	// ���� 1/8 ���ٶ�
	
	PSQ_FB_1_16,// ���� 1/16 ���ٶ�
*/
} PLAYBACK_SPEED_QT_EN;

//
// ��������
typedef enum 
{
	ET_H264 	= 0,
	ET_H265 	= 1,
	ET_MPEG4	= 2,
	ET_JPEG		= 3, 	// jpg ͼƬ
	ET_G711A	= 100,	// ��Ƶ����Ϊ >= 100; ��Ƶ���� <100
	ET_G711U	= 101,
	ET_AAC		= 102,
} HW_ENC_TYPE;

// 
// ��Ϣ����ʱ���(Push Notification time quantum)
typedef enum 
{
	PNTQ_ALL 	= 0,	// ȫ������
	PNTQ_DAY 	= 1,	// ��������
	PNTQ_NIGHT 	= 2,	// ��������
	PNTQ_OFF 	= 3,	// ������
} HW_PNTQ_EN;

// 
// �����û��Ĳ���;
typedef enum
{
	AA_ENTER 	= 1, // ����, ����ĳ������;
	AA_UP		= 2, // ������;
	AA_DOWN		= 3, // ������;		
	AA_TIME		= 4, // ��ʱ�������ѯ;	
} APP_ACTION_EN;

// 
// ����ͻ�������;
typedef enum
{
	CLI_ANDROID_PHONE	= 1, // android �ֻ�;
	CLI_ISO_PHONE		= 2, // ƻ���ֻ�;
	CLI_WIN_PC			= 3, // win����;	
} CLI_TYPE_EN;

// 
// ����ͻ�������;
// VRL_[1,4]  ��Ӧ15֡/s, ����: 2048kbps��1536kbps��1024kbps��768kbps;
// VRL_[5,7]  ��Ӧ12֡/s, ����: 512kbps��384kbps��256kbps;
// VRL_[8,10] ��Ӧ 8֡/s, ����: 200kbps, 168kbps��128kbps;
typedef enum
{
	VRL_UNKONW	= 0,	// δ֪
	VRL_1		= 1, 			
	VRL_2		= 2, 	
	VRL_3		= 3, 
	VRL_4		= 4, 	
	VRL_5		= 5, 	
	VRL_6		= 6, 
	VRL_7		= 7, 	
	VRL_8		= 8, 	
	VRL_9		= 9, 	
	VRL_10		= 10, 
} HW_VRL_EN; // video rate level

// ͨ������
typedef enum 
{
	CHN_TYPE_CAMERA  = 0, // ���������ͨ��, ��Ӧ�豸�б�WEBS_DEV_INFO_T ����� "CAMERA_ATTR_T *cameraAttr[64]" ���;
	CHN_TYPE_KSENSOR = 1, // ����������ͨ��, ���豸�б���δ����;
	CHN_TYPE_DSENSOR = 2, // ���ֿ���������ͨ��, ���豸�б���δ����;
	CHN_TYPE_SYSTEM  = 3, // ϵͳͨ��, ÿ���豸����һ��Ψһ���豸ͨ��, ������Զ����;

	CHN_TYPE_BUTT
} HW_CHN_TYPE_EN;

//
// ������������
typedef enum 
{
	HW_ALM_INPUT_VIDEO 		= 1, // ��Ƶ����(�ƶ���⡢��Ƶ��������Ƶ��ʧ����������Ƶͨ�������ı���);
	HW_ALM_INPUT_KSENSOR 	= 2, // ������̽ͷ����(����תΪ���գ����߳���תΪ����);
	HW_ALM_INPUT_DSENSOR	= 3, // ���ִ���������(����ͨ��RS433, wifi ���ӵ����豸);
	HW_ALM_INPUT_SYSTEM		= 4, // ϵͳ���ϱ���(����Ӳ�̵�)
} HW_ALM_INPUT_TYPE_EN;

//
// ��Ƶ����(HW_ALM_INPUT_VIDEO)������
typedef enum 
{
	HW_ALM_VIDEO_MOTION_DETECT 		= 101, // �ƶ����;
	HW_ALM_VIDEO_LOSS 				= 102, // ��Ƶ��ʧ, ���豸ʧ��;
	HW_ALM_VIDEO_COVER				= 103, // ��Ƶ�ڵ�;
	HW_ALM_INPUT_BEHAVIOR			= 104, // ��Ƶ��������, ����ʵ��������Ӿ������Ϊ����;	
	HW_ALM_SWIPING_CARD				= 105, // ˢ��������Ƶ����;
} HW_ALM_VIDEO_TYPE_EN;

//
// ������̽ͷ����(HW_ALM_INPUT_KSENSOR)������
typedef enum 
{
	HW_ALM_KSENSOR_KSWITCH_ON 		= 201, // ���ش�;
	HW_ALM_KSENSOR_KSWITCH_OFF		= 202, // ���عر�;
	HW_ALM_KSENSOR_KSWITCH_DOORBELLBTN	= 203, // ���尴Ť����;

} HW_ALM_KSENSOR_TYPE_EN;

//
// ���ִ���������(HW_ALM_INPUT_DSENSOR)������
typedef enum 
{
	HW_ALM_DSENSOR_DSWITCH_UP 		= 301, // ���ִ�������������(��);
	HW_ALM_DSENSOR_DSWITCH_DOWN		= 302, // ���ִ�������������(��);

} HW_ALM_DSENSOR_TYPE_EN;

//
// ϵͳ���ϱ���(HW_ALM_INPUT_SYSTEM)������
typedef enum 
{
	HW_ALM_SYSTEM_EXTDEV_DISCONNECT	= 401, // �ⲿ�豸ʧ��(����video��ksensor��dsensor������ⲿ�豸��Ԥ��);
	HW_ALM_SYSTEM_DISK_FULL			= 402, // �����������ܼ���¼��(system);
	HW_ALM_SYSTEM_DISK_ERROR		= 403, // ���̴��󣬲��ܼ���д��(system);	
	HW_ALM_SYSTEM_DISK_NOSDCARD		= 404, // ����ʱδ��⵽SD��(system);
	HW_ALM_SYSTEM_DISK_MOUNTFAIL	= 405, // ��⵽SD��������ʧ��(system);
	
	HW_ALM_SYSTEM_DISK_ERRORFILE    = 406, // SD����̫��error�ļ��������ʽ��(system);
	HW_ALM_SYSTEM_DISK_REMOVE   	= 407, // SD�����ε�(system);	
	HW_ALM_SYSTEM_DISK_MULTIERROR	= 408, // �ļ���д����̫Ƶ��,����ϵ����SD��,Ȼ�������ϵ�,����������ɴ���,���ʽ��SD��(system);
	HW_ALM_SYSTEM_LOW_BATTERY	= 409, // ��������20%;

	HW_ALM_SYSTEM_BUTT

} HW_ALM_SYSTEM_TYPE_EN;

//
// �������������
typedef enum 
{
	HW_ALM_KOUT_ACT_SWITCH_ON 		= 501, // �����������;
	HW_ALM_KOUT_ACT_SWITCH_OFF 		= 502, // ����������ر�;
} HW_ALM_KOUT_ACT_EN;

//
// �����������������
typedef enum 
{
	HW_ALM_DOUT_ACT_CMD_1 		= 601, // ���������������������1;
	HW_ALM_DOUT_ACT_CMD_2 		= 602, // ���������������������2;	
	HW_ALM_DOUT_ACT_CMD_3 		= 603, // ���������������������3;
	HW_ALM_DOUT_ACT_CMD_4		= 604, // ���������������������4;
	HW_ALM_DOUT_ACT_CMD_5		= 605, // ���������������������5;
	HW_ALM_DOUT_ACT_CMD_6		= 606, // ���������������������6;
	HW_ALM_DOUT_ACT_CMD_7		= 607, // ���������������������7;
	HW_ALM_DOUT_ACT_CMD_8		= 608, // ���������������������8;
	HW_ALM_DOUT_ACT_CMD_9		= 609, // ���������������������9;
	HW_ALM_DOUT_ACT_CMD_10		= 610, // ���������������������10;

	HW_ALM_DOUT_ACT_CMD_BUTT
} HW_ALM_DOUT_ACT_EN;

//
// ���������
typedef enum 
{
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_1 		= 701, // �����ȵ�����1;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_2 		= 702, // �����ȵ�����2;	
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_3 		= 703, // �����ȵ�����3;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_4		= 704, // �����ȵ�����4;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_5		= 705, // �����ȵ�����5;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_6		= 706, // �����ȵ�����6;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_7		= 707, // �����ȵ�����7;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_8		= 708, // �����ȵ�����8;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_9		= 709, // �����ȵ�����9;
	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_10		= 710, // �����ȵ�����10;

	HW_ALM_CAMERA_ACT_CALL_HOTPOINT_BUTT
} HW_ALM_CAMERA_ACT_EN;

// 
// λ�÷���
typedef enum
{
	CD_NORTHERN_LATITUDE = 'N',	// ��γ
	CD_SOUTH_LATITUDE	 = 'S',	// ��γ
	CD_WEST_LONGITUDE	 = 'W', // ����
	CD_EAST_LONGITUDE	 = 'E',	// ����
} COORDINATE_DIRECTION_EN;

//
// �ط����󷵻صĻص�����,Ŀ���Ǹ�֪�ͻ��˻طſ���ʧ�ܵ�ԭ��;
typedef enum _ReplayResEn_
{
    REPLAY_RES_SUCCESS = 1,        // ����ɹ�;
    REPLAY_RES_TOO_MANY_CLIENTS,   // ̫���л�����;
    REPLAY_RES_NOMORE_FILE,        // ���ŵ������һ���ļ�,ipcֹͣ�˻ط�;
} HWSDK_REPLAY_RES_EN;

//  
//  ���淭ת
typedef enum 
{
    //  0-3 ��Ӧ��ת
    HW_ROTATE_NONE = 0,  //  ����ת
    HW_ROTATE_180 = 1,  //  180�ȷ���
    HW_ROTATE_90 =  2,   //  90��
    HW_ROTATE_270 = 3,  //  270��
    //  4-5 ��Ӧ����ת
    HW_ROTATE_FLIP_NONE = 4,  //  û�о���
    HW_ROTATE_FLIP_HORI = 5, //  ˮƽ����ת
    HW_ROTATE_FLIP_VERT = 6, //  ��ֱ����ת
    HW_ROTATE_FLIP_HOVE = 7, //  ˮƽ+��ֱ����ת
} HW_ROTATE_EN;

//  
// ��ȡ�豸�������
typedef enum
{
    HW_MULTI_CONF_ARM_FLAG_RESBIT   = (0x01),   // ��Ⲽ��
    HW_MULTI_CONF_SEN_LEVEL_RESBIT  = (0x02),   // ������
    HW_MULTI_CONF_ONL_ALARM_RESBIT  = (0x04),   // �Ƿ�ֻ¼�Ʊ���¼��
    HW_MULTI_CONF_AUD_RECORD_RESBIT = (0x08),   // ¼��ʱ�Ƿ�¼����Ƶ
    HW_MULTI_CONF_DIS_NUM_RESBIT    = (0x10),   // ��������
    HW_MULTI_CONF_DIS_ATTR_RESBIT   = (0x20),   // ÿ��Ӳ�̵���Ϣ����
    HW_MULTI_CONF_PWRFREQ_RESBIT    = (0x40),   // �豸��ԴƵ��
    HW_MULTI_CONF_ROTATE_RESBIT     = (0x80),   // ��ת����
    HW_MULTI_CONF_FLIP_RESBIT       = (0x0100), // ��ת���� 
    HW_MULTI_CONF_VOLUME_RESBIT     = (0X0200), // ��������,��ʾvolume,slaveVolume,micVol,slaveMicVol���ĸ���������
    HW_MULTI_CONF_PICSNAP_RESBIT    = (0X0400), // PIR����
}  HW_MULTI_CONF_RESBIT_EN;

// 
// ������¼����
typedef enum
{
	HW_REC_TYPE_NORMAL = 0,		// ͨ��, ԭ����ȡ������������ϸ������Ϣʹ���������;
	HW_REC_TYPE_VISITOR,		// ����ÿ�, ����ר��;
	HW_REC_TYPE_BUTT,
} HW_REC_TYPE_EN;

typedef struct _FrameHeadAttr_  // attribute
{
	unsigned char 	dataType:3;		// ��������, 0:��Ƶ; 1:��Ƶ; 2:��������(��osd������������)
	unsigned char	frameHeadLen:5;	// ֡ͷ����,�ó��ȸ���FRAME_HEAD_T �Ĵ�С�仯	
    unsigned char   sizeOfSps;
    unsigned char   sizeOfPps;
	char			reserved[1];
} PACK_ALIGN FRAME_HEAD_ATTR_T;

// ����Ƶ֡ͷ����
typedef struct _FrameHead_
{                                // <��Ƶ����>              |   <��Ƶ����>	   	
	unsigned int  	frameLen;   // ֡��������               |	֡��������
	unsigned int  	frameNo;    // ֡��,��������            |	֡��,��������
	unsigned int 	tsSec;      // ʱ���, ��λ:��          |	����	
	unsigned int 	tsUsec;     // ʱ���, ��λ:΢��        |	����
	unsigned short 	width;      // ��Ƶ���                 |	����
	unsigned short 	height;     // ��Ƶ�߶�                 |	������: 0, 8000; 1, 16000
	unsigned char 	frameRate;  // ��Ƶ:֡��                |	ͨ��ģʽ: 0, ��ͨ��(Mone); 1, ������
	unsigned char 	frameType;  // ��Ƶ:1,�ؼ�֡;0,�ǹؼ�֡ |	λ��: 0, 8bit; 1, 16bit
	unsigned char	encType;    // ��������,��HW_ENC_TYPE   |	��������,��HW_ENC_TYPE
	char			level;		// ���ʼ���,��HW_VRL_EN		|	���� 
} PACK_ALIGN FRAME_HEAD_T;

typedef struct _StreamHead_
{
	FRAME_HEAD_ATTR_T 	fha;			// frame head attribute
	FRAME_HEAD_T		frameHead;
} PACK_ALIGN STREAM_HEAD_T;

typedef struct _ProconHead_
{
	int type;	// ��������,DATA_TYPE_EN �е�����һ��
	int len;	// �ڵ����ݵĴ�С
} PACK_ALIGN PROCON_HEAD_T;

typedef struct _ProConNode_
{
	PROCON_HEAD_T 	proconHead;
	char 			data[1]; // ���һ֡����Ƶ����, ֡ͷ + ����, ֡ͷ�ο� STREAM_HEAD_T;
} PACK_ALIGN PROCON_NODE_T;

typedef struct
{
    unsigned int totalSize;	// ��Ӳ�̵�������, ��λ: ��
    unsigned int freeSize;	// ��Ӳ�̵�ʣ������, ��λ: ��
} PACK_ALIGN HWSDK_DISK_ATTR_T;
#if 0
typedef struct
{
    char model[16];		// �豸�ͺ�
    char devId[52];		// �֧��48 ���ֽڵĵ�ID
    char devType[16];	// �豸���� "nvr/ipc/dvr"
    char version[16];	// ��"v1.23"
    unsigned char vch;	// ��Ƶͨ����
    unsigned char ach;	// ��Ƶͨ����
    unsigned char kin;	// ���뿪��������
    unsigned char kout; // �������������
    char vencStandard[16]; 		// ��ǰ��Ƶ�����׼, ��"jpeg/fmpeg4/h.264/h.265" 
    char aencStardard[16]; 		// ��ǰ��Ƶ�����׼, ��"AAC/g711a/g711u/g726/mp3"
    char allResolution[84]; 	// �豸��֧�ֵ����зֱ���, �ð�Ƿֺ����ֿ���: "1920X1080;1080X720;640X360;704X576" 
    unsigned char diskNum;		// �ܹ��ж��ٸ�����, ���֧��8 ��
    char unsued[3];				// ����
    HWSDK_DISK_ATTR_T diskAttr[8]; 	// ÿ��Ӳ�̵���Ϣ
} PACK_ALIGN HWSDK_DEV_STATUS_T;
#endif

typedef struct
{	
    char	mac[24];			// ֻ��, �����ַ, ����"00:25:63:63:25:ba"
    char	ip[16];				// ip��ַ����:"192.168.111.254"	
    char	gateway[16];		// ����, ����:"192.168.111.1"
    char	netmask[16];		// ��������, ����:"255.255.255.0"
    unsigned char	dhcpEnable;	// 1: DHCP, 0: STATIC
    unsigned char 	enableFlag;			// 1: ����, 0: ͣ��,����������������
    unsigned char   inUse;      //  �Ƿ���ʹ��, 1 ʹ�� , 0 û��
    char	reserved[9];
} PACK_ALIGN HWSDK_NET_WIRED_INFO_T;

typedef struct
{	
    char	mac[24];			// ֻ��, �����ַ, ����"00:25:63:63:25:ba"
    char	ip[16];				// ip��ַ����:"192.168.111.254"	
    char	gateway[16];		// ����, ����:"192.168.111.1"
    char	netmask[16];		// ��������, ����:"255.255.255.0"

    char    appName[32];				// �Ѿ������ϵ�app ������, ��"free-wifi"
    char 	passwd[32];					// wifi ������
    unsigned char 	appStrength;		// ��ǰ����APP ���ź�ǿ�� [0,5]	
    unsigned char	dhcpEnable;			// 1: DHCP, 0: STATIC
    unsigned char 	enableFlag;			// 1: ����, 0: ͣ��	
    unsigned char	status;				// ֻ��, 0,����; 1, ����
    unsigned char   inUse;      //  �Ƿ���ʹ��, 1 ʹ�� , 0 û��
    char	reserved[8];
} PACK_ALIGN HWSDK_NET_WIFI_INFO_T;

typedef struct
{	
    char	dns1[16];	// dns 1����:"202.96.134.133"
    char	dns2[16];	// dns 2����:"202.96.128.86"
} PACK_ALIGN HWSDK_NET_COM_INFO_T;

typedef struct
{
    HWSDK_NET_WIRED_INFO_T 	    wiredInfo; 	// ��������Ϣ
    HWSDK_NET_WIFI_INFO_T		wifiInfo;	// wifi����Ϣ
    HWSDK_NET_COM_INFO_T		comInfo;	// ���繫����Ϣ
} PACK_ALIGN HWSDK_NET_INFO_T;

typedef struct
{
    unsigned char   isCanUse;			// 0, ����ʹ��; 1, ��ʹ��
    unsigned char 	partIndex;			// ��������, ��ʽ����ʱ����Ҫ�õ�
    char 			unused[2];
    unsigned int    totalSize;			// �ܴ�С,��λM
    unsigned int    freeSize;			// ʣ��ռ�
} PACK_ALIGN HWSDK_DISK_PART_INFO_T;

typedef struct
{
    unsigned int 	size;				// ��С,��λM
    unsigned char 	partNum;			// ���ٸ�����
    unsigned char	type;				// 0,SD ��/TF��; 1,Ӳ��; 2, USB �豸	
    unsigned char	diskIndex;			// Ӳ������, ��ʽ����ʱ����Ҫ�õ�
    char  	unused[1];			// 	
    HWSDK_DISK_PART_INFO_T partInfo[MAX_PART_NUM];
} PACK_ALIGN HWSDK_DISK_INFO_T;

typedef struct _SearchRecordRes_
{
	char yearMark[12];		/* 12 X 8 = 96 bits, ���Ա�ʾ��1970 �꿪ʼ�Ժ��96 ���¼�����, 
								���Ϊ1 ��ʾ������¼��, ���Ϊ0 ��ʾ����û¼��; */
	char dateMark[46];		/* 46 X 8 = 368 bits, 1bit ��ʾ1��, ����ʾ366 ��, ��ÿ���1��1�տ�ʼ��; 
								���Ϊ1 ��ʾ������¼��, ���Ϊ0 ��ʾ����û¼��; */
	char date[12];			// ��ʽ"2016-03-30", �����������������, ���ǵ�ʹ�ûص��ķ�ʽ֪ͨAPP;							
	char minuteMark[180]; 	/* ��ͨ¼��: һ�� 60 X 24=1440 ����, ÿbit ��ʾ1 ����; ���Ϊ1 
							   ��ʾ�÷�����¼��, ���Ϊ0 ��ʾ�÷���û¼��; ��Ҫ 1440 / 8 = 180 �ֽ� */
	char minuteMarkAlm[180]; /* ����¼��: һ�� 60 X 24 = 1440 bits, ÿbit ��ʾ1 ����; ���Ϊ1 ��ʾ�÷���
							   �б���¼��, ���Ϊ0 ��ʾ�÷���û����¼��; ��Ҫ 1440 / 8 = 180 �ֽ� */
    unsigned short recordVer; //  ¼��汾��, ��sdk���
	char reserved[62];
	struct _SearchRecordRes_ *next;	// Ԥ��, ��ʱΪNULL;
} PACK_ALIGN HWSDK_SEARCH_RECORD_RES_T;

typedef struct 
{
    char apAddr[20];  //  �����ַ
    int channel;      //  ͨ����
    char apEssid[33]; //  ap ����
    char encryptionkey;  //  ���ܷ�ʽ 0������ 1 wep���� 2 wpa2����
    char matchCnt;       //  
    char quality;        //  �ź�ǿ�� 0-100��
    unsigned char isUtf8;//  �����ʽ�Ƿ���utf8,1:�� 0:��;
    char reserve[3];
} PACK_ALIGN HWSDK_WIFI_INFO_T;

typedef struct
{	
	unsigned int 	groupIndex;		// ������������index, ͬһ���豸�ļ�������ͷ���Էֵ���ͬ����;
	unsigned int 	devIndex;		// ����������豸��index, ȫ��Ψһ������;
	unsigned char 	chNum;			// ͨ����, ��0 ��ʼ;	
	unsigned char  	addFrom;		// �����Դ, 0, �û��Լ����; 1, ����û�����;
	unsigned char	ptz;			// 1, ֧����̨; 0, ��֧����̨;
	unsigned char	isDisplay;		// 1, ��Ҫ��APP ����ʾ; 0, ����Ҫ��APP ����ʾ;
	char 	chName[128];			// ͨ������;
	char	sharedFrom[128];			// ��addFrom Ϊ1 ��ʱ��, �ñ�����ʾ�������˺�;
} PACK_ALIGN CAMERA_ATTR_T;

typedef struct
{	
	unsigned int 	groupIndex;		// ������������index, ͬһ���豸�ļ�������ͷ���Էֵ���ͬ����;
	unsigned int 	devIndex;		// ����������豸��index, ȫ��Ψһ������;
	unsigned char 	chNum;			// ͨ����, ��0 ��ʼ;	
	unsigned char  	addFrom;		// �����Դ, 0, �û��Լ����; 1, ����û�����;
	unsigned char	unused;			// ����;
	unsigned char	isDisplay;		// 1, ��Ҫ��APP ����ʾ; 0, ����Ҫ��APP ����ʾ;
	char 	chName[128];			// ͨ������;
	char	sharedFrom[128];		// ��addFrom Ϊ1 ��ʱ��, �ñ�����ʾ�������˺�;
} PACK_ALIGN KSENSOR_ATTR_T;

typedef struct
{	
	unsigned int 	groupIndex;		// ������������index, ͬһ���豸�ļ�������ͷ���Էֵ���ͬ����;
	unsigned int 	devIndex;		// ����������豸��index, ȫ��Ψһ������;
	unsigned char 	chNum;			// ͨ����, ��0 ��ʼ;	
	unsigned char  	addFrom;		// �����Դ, 0, �û��Լ����; 1, ����û�����;
	unsigned char	unused;			// ����;
	unsigned char	isDisplay;		// 1, ��Ҫ��APP ����ʾ; 0, ����Ҫ��APP ����ʾ;
	char 	chName[128];			// ͨ������;
	char	sharedFrom[128];		// ��addFrom Ϊ1 ��ʱ��, �ñ�����ʾ�������˺�;
} PACK_ALIGN KOUT_ATTR_T;



// �ͻ������������ѯ����ĳ���豸����Ϣ
typedef struct _WebsDevInfo_
{
	unsigned int nodeIndex;	// ���豸���ڽڵ��index, �����Ϊ0 ��ʾ�ڸ��ڵ�;ע��: ������������, ��APP �������ñ���;
	unsigned int index;		// �豸�Լ���index, ȫ��Ψһ������;
	char devId[128];		// �豸ID,����: AAAABBBB-ABCD-1234-ABCD-123456789001;
	char type[16];			// �豸����, ����: ipc,nvr,dvr;
	char name[128];			// �豸����, UTF-8;
	char authorizedFlag[32]; 	// ��֤��ʶ, ����"normal";
	unsigned char videoCh;		// ��Ƶͨ����;
	char ip[20];				// ������IP;
	unsigned short port; 		// ��������½�Ķ˿�;
	char wip[20];				// ������IP;
	unsigned short wport; 		// �����˿�;
	char user[32];				// ��½�豸���û���;
	char pwd[32];				// ��½�豸������;
	char natType[8];			// nat ����, 'A',��ȫԲ׶��; 'B',IP ������, 'C',�˿�������, 'D',Symmetric NAT �Գ���;
	char p2pIp[20];				// P2P ��������IP ��ַ1	;
	unsigned short p2pPort; 	// P2P ��������IP �˿�1;
	char tssIp[20];				// ת��������IP ��ַ;	
	unsigned short tssPort; 	// ת���������˿�;
	char almsIp[20];			// ����������IP ��ַ;
	unsigned short almsPort; 	// �����������˿�;
	char devCode[32];			// �豸����, ��Ϊ��ѯ�豸������Ϣ�ӿڵ����֮һ;
	char devSoftVersion[20];	// �豸����汾, �ʹ��豸��ȡ���İ汾�Ա�, �����Ƿ���豸����;
	char devHardware[32];		// �豸Ӳ����Ϣ, ��ʱû�õ�;
	unsigned char cameraNum;	// �ж��ٸ�����ͷ;
	CAMERA_ATTR_T *cameraAttr[64];	// ����ͷ����,���֧��64 ��ͨ��, ��Ч����Ϊ[0,cameraNum) ;
	unsigned char ksensorNum;		// �ж��ٸ�ģ�⿪��;
	KSENSOR_ATTR_T *ksensorAttr[64];// ģ�⿪������,���֧��64 ��ͨ��, ��Ч����Ϊ[0,cameraNum) ;
	unsigned char koutNum;			// �ж��ٸ�ģ���������(������);
	KOUT_ATTR_T *koutAttr[64];		// ģ�������������,���֧��64 ��ͨ��, ��Ч����Ϊ[0,cameraNum) ;
	struct _WebsDevInfo_ *next;	
} PACK_ALIGN WEBS_DEV_INFO_T;

// �ڵ���Ϣ 
typedef struct _WebsNodeInfo_
{
	unsigned int parentIndex;		// ���ڵ�����, ���Ϊ0, ��ʾ���ĸ��ڵ���Ǹ��ڵ�
	unsigned int nodeIndex;			// ���ڵ�����
	char parentNodeName[128];		// ���ڵ�����, UTF-8
	char nodeName[128];				// ���ڵ�����, UTF-8
	
	struct _WebsNodeInfo_ *next;
} PACK_ALIGN WEBS_NODE_INFO_T;

// ����Ϣ 
typedef struct _GroupInfo_
{
	unsigned int index;			// ���ڵ�����
	unsigned int number;		// �����, ������
	char groupName[128];		// ������
	
	struct _GroupInfo_ *next;
} PACK_ALIGN WEBS_GROUP_INFO_T;

// ��webs ��ȡ�����豸�б���Ϣ
typedef struct 
{
	WEBS_DEV_INFO_T 	*pDevInfo;		// �豸����;
	WEBS_DEV_INFO_T 	*pDevTail;		// APP �ڱ�����ʱ����Բ��ù�ע�������;
	WEBS_NODE_INFO_T 	*pNodeInfo; 	// �ڵ�����;
	WEBS_NODE_INFO_T 	*pNodeTail; 	// APP �ڱ�����ʱ����Բ��ù�ע�������;
	WEBS_GROUP_INFO_T	*pGroupInfo; 	// ������ 	
	WEBS_GROUP_INFO_T 	*pGroupTail; 	// APP �ڱ�����ʱ����Բ��ù�ע�������;
} PACK_ALIGN WEBS_DEV_LIST_T;

// �ͻ������������ѯ����ĳ��OEM���ҵ���Ϣ
typedef struct
{
	char brand[32]; 	// Ʒ��, ͬһ��OEM �¿����кܶ��brand;
	char oemInc[128]; 	// oem ���ҵ�����: �������ܼ���(����)���޹�˾;
	char oemLogo[128]; 	// logo �����ص�ַ: http://www.5-smart.com/logo.jpg;
	char address[512]; 	// ��˾��ַ;
	char url[128]; 		// ��˾��ҳ;
	char call[32];		// ��ϵ�绰;
	char fax[32];		// ����;
	char post[8];		// �ʱ�;
	char lang[16];		// ����, "zh-cn", "us_en";
	char oemEshopurl[128]; 		// �����url, ����: 5-smart.tmall.com;
	char email[128];			// �ʼ���ַ;
	char status[32];			// ״̬��Ϣ;
	char oemAppname[32];		// App����;
	char oemNewversion[16];		// App�汾;
	char oemdownloadurl[128];	// App���ص�ַ;
	char oemHelpUrl[128];		// ������Ϣ��ַ;	
	char oemAboutUrl[128];		// ������Ϣ��ַ;
	char updateInfo[128*1024];	// �°汾��Ϣ, ���֧��128KBytes ���ֽ�;
} PACK_ALIGN WEBS_CLIENT_INFO_T;

typedef struct _EventMsg_
{
	unsigned int 	msgIndex; 	// ��Ϣ����, ��ʾ��ǰ�ڼ�����Ϣ;
	unsigned int 	devIndex; 	// �豸��Ψһ����;	
	unsigned int	almInputType;	// ������������, ��HW_ALM_INPUT_TYPE_EN
	unsigned int	AlmType; 		// ����������:
								  	// 1) �� HW_ALM_INPUT_VIDEO == almInputType; ȡֵ��Χ��HW_ALM_VIDEO_TYPE_EN;	
								  	// 2) �� HW_ALM_INPUT_KSENSOR == almInputType; ȡֵ��Χ��HW_ALM_KSENSOR_TYPE_EN;
									// 3) �� HW_ALM_INPUT_DSENSOR == almInputType; ȡֵ��Χ��HW_ALM_DSENSOR_TYPE_EN;
									// 4) �� HW_ALM_INPUT_SYSTEM == almInputType; ȡֵ��Χ��HW_ALM_SYSTEM_TYPE_EN;
	unsigned char 	chn;		// ͨ����:
								// 1) �� HW_ALM_INPUT_VIDEO == almInputType; ȡֵ��Χ(0, �豸��֧�ֵ���Ƶͨ����];	
							  	// 2) �� HW_ALM_INPUT_KSENSOR == almInputType; ȡֵ��Χ(0, �豸��֧�ֵ���Ƶͨ����];
								// 3) �� HW_ALM_INPUT_DSENSOR == almInputType; ȡֵ��Χ(0, �豸��֧�ֵ���Ƶͨ����];
								// 4) �� HW_ALM_INPUT_SYSTEM == almInputType; ������;
	char	unused[3];
	char	*koutAct; 	// ����, �ɱ���linkage �滻;
						// ������������ģ�⿪��������, ���û��, ��NULL == koutAct; �������, ȡֵ��Χ��
						// HW_ALM_KOUT_ACT_EN, ���һ��ͨ���������, ʹ��'^'����, ��: 0:501^1:502 
						// ��ʾ�ñ��������˿������0 �Ĵ򿪶���(501), ͬʱ�����˿������1 �Ĺرն���(502);
						// ��ָ���ŵ�ȫ��ascii �ַ�, ������'\0' Ϊ��������;
	char	*doutAct; 	// ����, �ɱ���linkage �滻;
						// ���������������ֿ���������, ���û��, ��NULL == doutAct; �������, ȡֵ��Χ��
					 	// HW_ALM_DOUT_ACT_EN, ���һ��ͨ���������, ʹ��'^'����, ��: 0:601^1:602 
					 	// ��ʾ�ñ������������ֿ���ͨ��0 ִ�ж�������1(601), ͬʱ�������ֿ���ͨ��1 ִ�ж�������2(602);
					 	// ��ָ���ŵ�ȫ��ascii �ַ�, ������'\0' Ϊ��������;
	char	*cameraAct; // ����, �ɱ���linkage �滻;
						// ���������������������, ���û��, ��NULL == doutAct; �������, ȡֵ��Χ��
						// HW_ALM_CAMERA_ACT_EN, ���һ��ͨ���������, ʹ��'^'����, ��: 0:701^1:702 
						// ��ʾ�ñ������������0�����ȵ�����1(701), �����1�����ȵ�����2(702);
						// ��ָ���ŵ�ȫ��ascii �ַ�, ������'\0' Ϊ��������;
	char 	*linkage;	// �������������������, �ɷ������ṩ������Ե��ַ���, APP ֱ����ʾ;
						// +++ ���Ӹñ����Ƿ����滻koutAct, doutAct, cameraAct �⼸������;
	char 	*picture;	// ����������ץ�ĵ�ͼƬ, ���û��, ��NULL == picture; ��������˶����Ƶͨ��ץ��,ʹ��'^'����,
						// ��:"168_2_2016_03_28_11_25_23.jpg^168_1_2016_03_28_11_25_23.jpg", ÿ��ͼƬ�ĸ�ʽΪ
						// �豸index_��Ƶͨ����_��_��_��_ʱ_��_��.jpg.
						// ��ָ���ŵ�ȫ��ascii �ַ�, ������'\0' Ϊ��������;
	char 	tsUtc[20];	// APPչʾ���ͻ����ı���ʱ��, ��ʽ"2016-01-30 20:20:09", ע��, ��չʾ��ʱ�����UTC ʱ��;
	char	srvTime[20];// �����ϱ�ʱ, �������ĵ�ǰʱ��, ��APP ʹ�ñ�������ʱʹ��;
	char 	*detail;	// ��������ϸ��Ϣ, �ɷ������ṩ������Ե��ַ���, APP ֱ����ʾ;
	float	value;		// ֵ,��������ȡ���� almType �� almSubType ��ֵ�����:
						/*	almType 				|	almSubType					|	values
							HW_ALM_INPUT_SYSTEM		|	HW_ALM_SYSTEM_LOW_BATTERY	|	��ʾ�豸ʣ������İٷֱ�[0,100]	
						*/
	struct _EventMsg_ *next;
} PACK_ALIGN ALARM_MSG_T , DOOR_BELL_T;

//
// ĳ���豸ͨ��1��ı�������, ����������������Ҳ�����Ӧ���豸, ˵�����豸,
// �������������û�б�����Ϣ����;
typedef struct _OneDayNewMsgSize_
{
	unsigned int 	devIndex;	// ͨ�������豸������, �� CHN_TYPE_SYSTEM == chnType, �ñ���û����;
	unsigned char	chnType;	// ͨ������, ��HW_CHN_TYPE_EN;
	unsigned char	chn;		// ĳ���豸��ͨ��, �� CHN_TYPE_SYSTEM == chnType, �ñ���û����;
	unsigned int  	size;		// �ж�����������Ϣ, +++ ����100 ����ʱ��, APP ��ʾ"99+"����;
	ALARM_MSG_T		lastMsg;	// ���µı�����Ϣ, �� CHN_TYPE_SYSTEM == chnType, �ñ���û����;
								// +++ �ñ�����ʱֻʹ�õ����������������picture ����;
	struct _OneDayNewMsgSize_ *next;	
} ONE_DAY_NEW_MSG_SIZE_T;

//
//������ȡͼƬ����������ṹ
typedef struct _GetPicParam_
{
    unsigned int picType;       // Ҫ��ȡ��ͼƬ����, ȡֵ��Χ�μ�:PIC_TYPE_EN;
    unsigned int eventType;     // ��PIC_TYPE_REALTIME == picType, ��ʾ��ʾ��ȡ�豸��ǰ��ȡ��һ��ͼƬ, eventType ��Ч;
                                // ��PIC_TYPE_ALARM = picType, Ϊ��������, ��ӦALARM_MSG_T �����AlmType ����;
                                // ��PIC_TYPE_PRESET == picType, ��ʾ��ʾ��ȡ��ȡĳ��Ԥ��λ��ͼƬ, eventType ��Ч;
    int chn;                    // ��PIC_TYPE_REALTIME == picType, ��ʾ��Ƶ��ͨ����;
                                // ��PIC_TYPE_ALARM = picType, ��ӦALARM_MSG_T �����chn ����;
                                // ��PIC_TYPE_PRESET == picType, ��ʾԤ��λ���ڵ���Ƶͨ����;
    char context[64];           // ��PIC_TYPE_REALTIME == picType, �ò���û����;
                                // ��PIC_TYPE_ALARM = picType,��ӦALARM_MSG_T �����picture ����;
                                // ��PIC_TYPE_PRESET == picType, ��ʾԤ��λ��[1,8], ���ַ�����ʾ, ����:"1"��"2"��"3";
} HWSDK_GET_PIC_PARAM_T;

//
// �û���¼ʱ����һЩ�򵥵���Ϣ, ����û�����, �����ǳ�, ����ר����һ��ָ��ȥ��ȡ�ǳ�
typedef struct
{
	char nickname[128];		// �ǳ�;
	int userValue;			// �û�����ֵ;
	int userDiamons;		// �û�שʯ��;
	int userSuns;			// �û�̫����;
	int userMoons;			// �û�������;
	int userStars;			// �û�������;
	char reserved[1004];	// 
} LOGIN_RES_T;

//
// ���е�����Ϣ
typedef struct _AllNewMsgSize_
{
	ONE_DAY_NEW_MSG_SIZE_T *today;		// ����
	ONE_DAY_NEW_MSG_SIZE_T *yesterday;	// ����
	ONE_DAY_NEW_MSG_SIZE_T *beforeYesterday; // ǰ��
	ONE_DAY_NEW_MSG_SIZE_T *moreDay;	// ����ǰ
} ALL_NEW_MSG_SIZE_T;

//
// ���е�����Ϣ
typedef struct
{
	ONE_DAY_NEW_MSG_SIZE_T *anyDay;	// �������ڵ���Ϣ
} ANYDAY_NEW_MSG_SIZE_T;

//
// �豸�汾����
typedef struct _DevVersionParam_
{
	char version[16];		// ���µİ汾��, ��ʽ����:"1.0.0.11";
	char reserved[1024];	//
} HWSDK_DEV_VERSION_PARAM;

//
// �豸�������;
typedef struct
{
    unsigned char   	armFlag;			// 0: ����(�豸�������ƶ����); 1: ����(�豸�����ƶ����);
    unsigned char 		sensitiveLevel;		// ������, [1,5], ֵԽ��������Խ��;
    unsigned char       isOnlyAlarmRec;	    // 0, ȫ��¼��, ��������¼��; 1, ֻ�б���ʱ��¼��;
    unsigned char       isAudioRec;		    // 0, ¼��ʱֻ¼����Ƶ; 1, ¼��ʱͬʱ¼������Ƶ;
    
    unsigned char       rotate;	            // ��ת;
    unsigned char       flip;			    // ��ת;
    unsigned char       volume;		        // ����[0-100],ipc,nvr,������������������;
    unsigned char       diskNum;		    // �ܹ��ж��ٸ�����, ���֧��8 ��;
    
    HWSDK_DISK_ATTR_T   diskAttr[8]; 	    // ÿ��Ӳ�̵���Ϣ;
    
    unsigned short      pwrFreq;            // ��ԴƵ��;
    unsigned char       slaveVolume;        // [0-100],����ӻ�����������;
    unsigned char       micVol;             // [0-100],ipc,nvr,��������mic����;
    
    unsigned int        resBits;            // ÿλ��Ӧһ�������ķ��ؽ��, 0��ʾʧ�ܣ�1�ɹ�;
    unsigned char       slaveMicVol;        // [0-100],����ӻ�mic����;
    unsigned char       pirSnap;            // ��Ӧ���� 0,�ر� 1����;

    unsigned char       reserved[510];
} PACK_ALIGN HWSDK_GET_MULTI_CONF_T;

typedef enum _UpdateState_
{
    UPDATE_SEND_CMD = 0,             //  �ѷ�����������
    UPDATE_GET_CMD = 1,              //  �յ���������
    UPDATE_GET_FILEURL,              //  ��ȡ�����ļ�url
    UPDATE_DOWNLOAD_FILE,            //  �����ļ�
    UPDATE_DOWNLOAD_FILE_END,        //  �����ļ����
    UPDATE_WRITE_FLASH,              //  ��ʼ����
    UPDATE_WRITE_FLASH_END,          //  �������
    UPDATE_REBOOT,                   //  ׼������
    UPDATE_IS_NEWEST,                //  �Ѿ������²���Ҫ����
    UPDATE_OTHER_UPDATE,             //  �����ͻ�������
    UPDATE_FAIL,                     //  ����ʧ��
} UPDATE_STATE_EN;

//  ���̸�ʽ��
typedef enum 
{
    FORMAT_ING = 1,             //  ���ڸ�ʽ�� 1
    FORMAT_END,             //  ��ʽ����� 2
    FORMAT_FAIL,            //  ��ʽʧ�� 3 
} FORMAT_STATE_EN;

//
// Ѹ����װģʽ����;
typedef enum
{
    HWSDK_XM_INS_MODE_SUCTIONTOP    = 1,    // ����ģʽ;
    HWSDK_XM_INS_MODE_DESKTOP       = 2,    // ����ģʽ;
    HWSDK_XM_INS_MODE_WALLLOAD      = 3,    // ��װģʽ;
} HWSDK_XM_INS_MODE_E;

//
// Ѹ������ģʽ����;
typedef enum
{
    HWSDK_XM_FISHEYE_MODE_FISHEYE   = 1,    // ����ģ;
    HWSDK_XM_FISHEYE_MODE_PTZ       = 2,    // PTZ;
    HWSDK_XM_FISHEYE_MODE_DEG180    = 3,    // ˮƽ180;
    HWSDK_XM_FISHEYE_MODE_DEG360    = 4,    // 360;
    HWSDK_XM_FISHEYE_MODE_FOURSEG   = 5,    // �ķָ�;
} HWSDK_XM_FISHEYE_MODE_E;

typedef enum {
    PTZ_CTRL_STOP = 100, 
    PTZ_CTRL_MOVE_UP,           // �����ƶ�;
    PTZ_CTRL_MOVE_DOWN,         // �����ƶ�;
    PTZ_CTRL_MOVE_LEFT,         // �����ƶ�;
    PTZ_CTRL_MOVE_RIGHT,        // �����ƶ�;
    PTZ_CTRL_MOVE_UPLEFT,       // �������ƶ�;
    PTZ_CTRL_MOVE_DOWNLEFT,     // �������ƶ�;
    PTZ_CTRL_MOVE_UPRIGHT,      // �������ƶ�;
    PTZ_CTRL_MOVE_DOWNRIGHT,    // �������ƶ�;

    PTZ_CTRL_SET_PSP,           // ����Ԥ��λ;
    PTZ_CTRL_CALL_PSP,          // ��ȡԤ��λ;
    PTZ_CTRL_DELETE_PSP,        // ɾ��Ԥ��λ;

    PTZ_CTRL_BEGIN_CRUISE_SET,  // 
    PTZ_CTRL_SET_CRUISE,        // 
    PTZ_CTRL_END_CRUISE_SET,    // 
    PTZ_CTRL_CALL_CRUISE,       // 
    PTZ_CTRL_DELETE_CRUISE,     // 
    PTZ_CTRL_STOP_CRUISE,       // 

    PTZ_CTRL_AUTO_SCAN,         // 

    PTZ_CTRL_RAINBRUSH_START,   // 
    PTZ_CTRL_RAINBRUSH_STOP,    // 
    PTZ_CTRL_LIGHT_ON,          // 
    PTZ_CTRL_LIGHT_OFF,         // 

    PTZ_CTRL_MAX
} PTZ_CTRL_E;

//
// ��������Ƶ���ص�;
// context: ������, HwsdkRealTimeStreamStart() �����������ķ���ֵ;
// pnt: �����ݼ�������;
typedef int (*HW_STREAM_RECV_CB)( unsigned long context, PROCON_NODE_T *pnt );
// typedef HW_STREAM_RECV_CB HW_PLAYBACK_RECV_CB;

// ���ջط����ݰ��ص�;
// context: ������, HwsdkDevSearchRecord() ����������ķ���ֵ, �󶨻طŵ��豸�˺�ͨ����;
// pnt: �����ݼ�������;
// playbackSessID: �طŵ�sessionID,���ڷ�ֹ�л��ط��ļ�ʱ�յ��ϴλطŵ�����,��Χ[1,127];
typedef int (*HW_PLAYBACK_RECV_CB)( unsigned long context, PROCON_NODE_T *pnt, unsigned char playbackSessID );

//
// ����¼����������Ļص�;
// context: ������, HwsdkSearchRecord() ���һ�������ķ���ֵ;
// hsrr: out, ĳ���¼���������;
typedef int (*HW_SEARCH_RECORD_RES_CB)( unsigned long context, HWSDK_SEARCH_RECORD_RES_T *hsrr );

//
// ���ձ�����Ϣ;
// alarmMsg: ��Ϣ����;
typedef int (*HW_DEV_REPORT_MSG_CB)( ALARM_MSG_T alarmMsg );

//
// �豸������;
// devIndex: �豸��Ψһ����;
// onOFF: 0, ����; 1, ����;
// ע��:�豸����: APP��ȡ�豸�б�(����)->sdk �������������豸->ʹ�ñ��ص������������ϵ��豸֪ͨapp;
//      �豸����: sdk ά�������Ѿ����ߵ��豸->��⵽�豸����->ʹ�ñ��ص������������ϵ��豸֪ͨapp;
//		�豸��������: sdk ���豸��������->�豸��������->ʹ�ñ��ص������������ϵ��豸֪ͨapp;
typedef int (*HW_DEV_ONOFF_CB)( unsigned int devIndex, int onOFF );

//
// ���յ�ͼƬ�ص�, ��ӦHwsdkDevGetPic() ������;
// devIndex: �豸��Ψһ����, ��ӦHwsdkDevGetPic() �� devIndex����;
// picType: ͼƬ����, ��ӦHwsdkDevGetPic() �� picType����;
// eventType, �¼�����, ��ӦHwsdkDevGetPic() �� eventType����;
// chn: ͨ����, ��ӦHwsdkDevGetPic() �� chn����;
// context: ������, ��ӦHwsdkDevGetPic() �� context����;
// pic: ͼƬ����, ��ʱ֧��jpg ��ʽ;
// picSize: ͼƬ���ݵĳ���, Ϊ0 ��ʾͼƬ�ļ�������;
typedef int (*HW_DEV_RECV_PIC_CB)( unsigned int devIndex, unsigned int picType, 
									unsigned int eventType, int chn, char context[64], 
									char *pic, unsigned int picSize );

//
// �¼��ص�, ��Ҫ����һЩ�Ƚ�ͨ�õĻص�����;
// event: �μ� COM_EVENT_EN;
// param1: ����event �Ĳ�ͬ���в�ͬ������;
// param2: ����event �Ĳ�ͬ���в�ͬ������;
/* event��param1��param2 �������:
*   event  						| param1                            |  param2
    1(CE_CLIENT_INDEX)    		| ���������ظ��ͻ��˵�index          |  ������  
    2(CE_WIFI_CONNECT_PROGESS)	| ����wifi�Ľ���,�ٷֱ�[0,100]		|  ������
    3(CE_WIFI_IP)				| ĳ���豸������wifi ��IP ��ַ       |  ������
    4(CE_DEV_ONLINE)			| �豸index							|  ��½��
    5(CE_DEV_OFFLINE)			| �豸index							|  ������
    6(CE_DEV_SVR)				| �豸index							|  ������
    7(CE_PLAYBACK_RES)          | ����طŵ�channel                  |  �����룬��HW_CERROR_TYPE_EN
    8(CE_CHANNEL_STATE_LOW)     | �豸index                         |  NVR�豸��ͨ��״̬��Ϣ,ȡ��32λ��unsigned long������64λ��32λ��,1 bit��Ӧһ��ͨ��,��λ����;
                                                                        ��ʾͨ�� 0-31��ͨ��״̬,bit��1��ʾ����Ƶ,0û����Ƶ;
                                                                        ����: 0001 0000 0000 0000 0000 0000 0000 0000 ��ʾchannel=28 ͨ����Ƶ����;
    9(CE_CHANNEL_STATE_HIGH)    | �豸index                         | ��ʾ32-63��ͨ��״̬;
                                                                        ����: 0000 0000 0000 00000 0000 0000 00000 0001 ��ʾchannel=32 ͨ����Ƶ����;
	10(CE_MNG_IP)				| �����������IP ��ַ, APP ��Ҫ����   |  �˿�
    11(CE_CHANNEL_SWITCH)       | �豸index                         |  ʵʱ������ͨ��״̬,0:��ʾP2P,1:��ʾת��,2:��ʾ������;
    12(CE_DEV_SLEEP)			| �豸index							|  ������
    13(CE_DEV_ELECTRICITY)      | �豸index                          |  �����İٷֱ�[0,100]
*/
typedef int (*FN_COM_EVENT_CB)( unsigned long event, unsigned long param1, unsigned long param2 );

//
// ͨ�����ݻص�, ��Ҫ����һЩ�Ƚ�ͨ�õĻص�����;
// event: �μ� COM_DATA_EN;
// param1: ����event �Ĳ�ͬ���в�ͬ������;
// param2: ����event �Ĳ�ͬ���в�ͬ������;
/* event��param1��param2 �������:
*   event  								| param1                |  param2			|	pData
    1(CD_UNVARNISHED_TRANSMISSION)    	| �豸��index         	|  ͸�����ݵĳ���  	|	���������;
    2(CD_DEBUG_DATA)					| ����					|  ����				|	��������,��������'\0' Ϊ������;
*/
typedef int (*FN_COM_DATA_CB)( unsigned long event, unsigned long param1, unsigned long param2, char *pData );


/*
* fn:�������Ȼص�
* state: ����״̬, �� UPDATE_STATE_EN;
* percent:
*   ��state Ϊ UPDATE_DOWNLOAD_FILE ʱ��ʾ���ؽ���
*   ��state Ϊ UPDATE_WRITE_FLASH   ʱ��ʾ��������
*   ����״̬��percent û������
*/
typedef int (*FN_UPDATE_PERCENT_CB)( int state, int percent );

/*
* fn: ����Wifi ����ص�����;
* result: ��ʾ����wifi�Ľ��,-1����ʧ�ܣ�0��ʾ�ɹ�;
* ip: �ɹ����Ӻ�( result==0 )����ip���������ΪNULL;
*/
typedef int (*HWSDK_SEARCH_DEV_RESULT_CB)( char result, char *ip );

/*
* fn: ��ȡWifi�б� ����ص�����
* wifiList: wifi ��Ϣ����ָ��
* num: wifiList �����С, ��ʾ�ж��ٸ�wifi��
* totalnum: �ܹ��ж�����wifi, ��Ϊ�Ƿ��ض�λص�������ص�ȫ�����غ����Ϸ��أ� ���õȳ�ʱ
*/
typedef int (*HWSDK_GET_WIFILIST_CB)( unsigned int sessIndex, HWSDK_WIFI_INFO_T *wifiList, int num, unsigned short totalnum );

/*
* fn:��ʽ��sd�����Ȼص�
* state: ��ʽ��״̬, �� FORMAT_STATE_EN;
* percent:
*   ��state Ϊ FORMAT_ING ʱ��ʾ��ʽ������
*   ����״̬��percent û������
*/
typedef int (*HWSDK_FORMAT_PERCENT_CB)( int state, int percent );

//
// ��ʼ��sdk �ṹ��
typedef struct
{
	char ipAddr[20];									    // APP �����ֻ���IP ��ַ, ��ʽ"192.168.025.210" ��������л���, ����Ҫ�������ñ���;
    char hwpDns[128];                                       // ������������Ա/������Աʹ��,����ƽ̨��DNS��������ַ����ʽ"###actapi.iotor.net###"�����û��, ��ʹhwpDns[0] = '\0';
	char logPath[128];									    // ������������Ա/������Աʹ��,��־���·������ʽ"##/5-smart/log##"�����û��, ��ʹlogPath[0] = '\0';
	unsigned char 			        cliType;				// �ͻ�������, sdk ��Ҫ���ݲ�ͬ�Ŀͻ����������������ȡ��ͬ������, ȡֵ��ΧCLI_TYPE_EN;
	unsigned long 			        clientIndex;			// �ͻ���ȫ��Ψһindex, ��web ����������,���û����0;��ֵ�ɱ��ṹ���pComEventFunc ��������;
	unsigned long 					mngIp;					// ���������IP ��ַ,���û����0;��ֵ�ɱ��ṹ���pComEventFunc ��������;
	unsigned short					mngPort;				// ����������˿�,���û����0;��ֵ�ɱ��ṹ���pComEventFunc ��������;		
	char 							paramReserved[3952];	// ����Ԥ���ռ�;
	HW_STREAM_RECV_CB		        pStreamRecvFunc;		// ��������Ƶ���ص�����;	
	HW_PLAYBACK_RECV_CB	  	        pPlaybackRecvFunc;		// ���ջط�����Ƶ���ص�����;
	HW_SEARCH_RECORD_RES_CB         pSearchRecordResFunc;	// ¼������������ػص�����;
	HW_DEV_REPORT_MSG_CB	        pDevReportMsgFunc;		// �豸�ϱ���Ϣ�ص�����;	
	HW_DEV_ONOFF_CB			        pDevOnOffFunc;			// �豸�����߻ص�����;	
	HW_DEV_RECV_PIC_CB		        pDevRecvPicFunc;	    // ���յ�ͼƬ�ص�����;
	FN_COM_EVENT_CB			        pComEventFunc;			// �¼��ص�, ��Ҫ����һЩ�Ƚ�ͨ�õĻص�����;
	FN_UPDATE_PERCENT_CB	        pUpdatePercentFunc;		// �������Ȼص�;
    HWSDK_GET_WIFILIST_CB           pGetWifilistFunc;       // ��ȡwifi�б�ص�;
    HWSDK_FORMAT_PERCENT_CB         pFormatPercentFunc;     // ��ʽ��sd���Ȼص�;
    HWSDK_SEARCH_DEV_RESULT_CB      pSearchDevResFunc;      // �豸�������ػص�;
    FN_COM_DATA_CB					pComDataFunc;			// ͨ�����ݻص�
	char			          		funcReserved[7*1024 - 16]; 	// �ص�����Ԥ���ռ�;
} PACK_ALIGN INIT_HWSDK_PARAM_T;

#ifdef WIN32
#pragma pack(pop)
#undef PACK_ALIGN
#else
#undef  PACK_ALIGN
#endif

#endif // __HWSDKTYPE_H__

