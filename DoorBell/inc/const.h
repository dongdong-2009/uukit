#ifndef __CONST_H__
#define __CONST_H__

typedef unsigned int 	uint;
typedef unsigned long 	ulong;
typedef unsigned char 	uchar;
typedef unsigned short  ushort;  
typedef  char 			sharechar; // �û�ShareMalloc
#ifdef WIN32
#include "BaseTsd.h"
typedef UINT64 uint64_t;
#else
//typedef unsigned long long uint64_t;
#endif

#define SIZE_64K				(64*1024)
#define SIZE_256				256
#define SIZE_128				128
#define SIZE_48					48
#define SIZE_64					64
#define SIZE_20					20
#define SIZE_12K				(12*1024)
#define SIZE_32					32
#define SIZE_16					16
#define SIZE_256K				(256*1024)
#define SIZE_1K					1024
#define SIZE_4K					(4*1024)
#define SIZE_8					8
#define SIZE_512K				(512*1024)
#define SIZE_1M					(1024*1024)
#define SIZE_5000				5000
#define SIZE_512				512
#define SIZE_128K				(128*1024)
#define SIZE_132K				(132*1024)
#define	SIZE_2K					(2*1024)
#define	SIZE_12					12
#define	SIZE_52					52
#define	SIZE_16K				(16*1024)
#define	SIZE_84K				(84*1024)
#define	SIZE_32K				(32*1024)
#define	SIZE_8K					(8*1024)
#define SIZE_252K				(252*1024)
#define SIZE_20000				20000
#define SR_MNG_DELAY			15000	// �͹���������Ľ�����ʱʱ��;

#define	FI_SUCCESS				0	// �ɹ�
#define	FI_FAIL					-1	// ʧ��
#define FI_SUCCESSFUL 			FI_SUCCESS
#define FI_FAILED				FI_FAIL
#define	FI_TRUE					1	// ��
#define	FI_FALSE				0	// ��

#define NET_ADDRSIZE 			20		// "192.168.188.168" ��20��bytes;"00:AB:BB:CC:BA:00" ��18���ֽ�
#define MAX_PATH_LEVEL			20		// ���Ŀ¼����
#define COM_BUF_SIZE 			256		// ����buf ��С
#define MAX_CHANNEL_NUM			16		// ���ͨ����
#define MAX_PB_NUM				4		// �ط����ͨ����
#define DATE_LEN				12		// "2012-11-18" �ĳ���
#define TIME_LEN				12		// "10:20:28" �ĳ���
#define NORMAL_USER_NAME_LEN	32 		// һ���û����ĳ���
#define NORMAL_PASSWD_LEN		32 		// һ������ĳ���
#define NORMAL_URL_LEN			128		// һ�������ĳ���
#define MAX_WEEK_DAY			7 		//һ����7��
#define MAX_DAY_TIME_SEG		4		//һ���ṩ�ĸ�ʱ���ѡ��
#define MAX_SUPPORT_WIN			64		// �ͻ������֧��64 ������
#define MAX_UNVARNISHED_TRANSMISSION_SIZE	1168		// ÿ��͸��������ֽ���

#define MTU_SIZE				1000 // ql debug 1200	// �ͻ������֧��64 ������
#define P2P_SEND_DATA_LEVEL     64
#define ONE_DAY_SECOND 			86400	//(24*3600)


// producer consumer open flag
typedef enum _OpenEn_
{
	OPEN_RDONLY = 0,
	OPEN_WRONLY
} OPEN_EN;

typedef enum _BlockEn_
{
	BLOCK_NO = 0,	// �Է������ķ�ʽ
	BLOCK_YES		// �������ķ�ʽ
} BLOCK_EN;

#endif  // __CONST_H__

