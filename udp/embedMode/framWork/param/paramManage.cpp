/*
*******************************************************************************
**  Copyright (c) 2012, ���������޹�˾, All rights reserved.
**  ���ߣ����Ž�
**  ��ǰ�汾��v1.0
**  ��������: 2012.11.10
**  �ļ�˵��: ��������
*******************************************************************************
*/

#include <string.h>

#include "debug.h"
#include "const.h"
#include "linuxFile.h"

#include "paramConfig.h"
#include "paramManage.h"
#include "vencParamEasy.h"

// �ָ���������(����Ҳ�ָ�)
void ParamSetFactoryConfigure()
{	
	SysConfigInitMemberAddr();
	SysConfigRestoreFactoryConf();
	//SaveParamConfig();
	SyncParamConfig();
}

// �ָ�Ĭ�ϲ���(���粻�ָ�)
void ParamSetDefaultParam()
{	
	SysConfigInitMemberAddr();
	SysConfigSetDefaultParam();
	//SaveParamConfig();
	// ֱ��д��flash
	SyncParamConfig();
}

// ϵͳ��������
int ParamGetBaseInfo(PARAM_CONFIG_BASE_INFO *pParam)
{
	int ret;

	ret = GetParamConfig(INDEX_PARAM_CONFIG_BASE_INFO, pParam, sizeof(*pParam), 0);
	Strcpy( pParam->softwareVersion, DEV_SOFTWARE_VERSION );
	Strcpy( pParam->hardwareVersion, DEV_HARDWARE_VERSION );
	Strcpy( pParam->configureVersion, DEV_CONFIG_VERSION );
	Strcpy( pParam->serialNo, DEV_SERIAL_NUM );

	return ret;
}
int ParamSetBaseInfo(PARAM_CONFIG_BASE_INFO *pParam)
{
	PARAM_CONFIG_BASE_INFO param;
	int ret;

	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetBaseInfo( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_BASE_INFO, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// �������
int ParamGetNetwork(PARAM_CONFIG_NETWORK *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_NETWORK, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetNetwork(PARAM_CONFIG_NETWORK *pParam)
{
	PARAM_CONFIG_NETWORK param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetNetwork( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_NETWORK, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// �ͻ��˻�IE��¼�û�����
int ParamGetClientUser(int n, PARAM_CONFIG_CLIENT_USER *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_CLIENT_USER, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetClientUser(int n, PARAM_CONFIG_CLIENT_USER *pParam)
{
	PARAM_CONFIG_CLIENT_USER param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetClientUser( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_CLIENT_USER, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��Ƶ���빫������
int ParamGetVideoEncodePublic(PARAM_CONFIG_VIDEO_ENCODE_PUBLIC *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE_PUBLIC, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetVideoEncodePublic(PARAM_CONFIG_VIDEO_ENCODE_PUBLIC *pParam)
{
	PARAM_CONFIG_VIDEO_ENCODE_PUBLIC param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetVideoEncodePublic( &param );
	if( FI_SUCCESS == ret )
	{
		ret = FI_FAIL;
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			//VencParamEasySetVideoStandard( pParam->videoStandard );
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE_PUBLIC, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();				
			}
		}
	}
	
	return ret;
}

// ��������Ƶ�������
int ParamGetVideoEncode(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetVideoEncode(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam)
{
	PARAM_CONFIG_VIDEO_ENCODE param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetVideoEncode( n, &param );
	if( FI_SUCCESS == ret )
	{
		ret = FI_FAIL;
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			VencParamEasySetResolution( n, pParam->resolution );
			VencParamEasySetFramerate( n, pParam->frameRate );
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

//��������Ƶ�������
int ParamGetVideoEncodeSlave(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE_SLAVE, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetVideoEncodeSlave(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam)
{
	PARAM_CONFIG_VIDEO_ENCODE param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetVideoEncodeSlave( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_ENCODE_SLAVE, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��Ƶ�ɼ���������
int ParamGetVideoBaseParam(int n, PARAM_CONFIG_VIDEO_BASE_PARAM *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_BASE_PARAM, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetVideoBaseParam(int n, PARAM_CONFIG_VIDEO_BASE_PARAM *pParam)
{
	PARAM_CONFIG_VIDEO_BASE_PARAM param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetVideoBaseParam( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_BASE_PARAM, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// logo OSD ����
int ParamGetOsdLogo(int n, PARAM_CONFIG_OSD_LOGO *pParam)
{
	int x, y;
	int ret;
	
	//if ( n > 0 ) return FI_FAIL; // ipc ֻ��һ��ͨ��
	ret = GetParamConfig(INDEX_PARAM_CONFIG_OSD_LOGO, pParam, sizeof(*pParam), n);
	x = pParam->xPos;
	y = pParam->yPos;

	if( 0 != (x % 16) )
	{
		x = x - (x % 16);
	}
	if( 0 != (y % 16) )
	{
		y = y - (y % 16);
	}

	pParam->xPos = x;
	pParam->yPos = y;

	return ret;
}
int ParamSetOsdLogo(int n, PARAM_CONFIG_OSD_LOGO *pParam)
{
	PARAM_CONFIG_OSD_LOGO param;
	int ret;

	//if ( n > 0 ) return FI_FAIL;// ipc ֻ��һ��ͨ��
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetOsdLogo( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_OSD_LOGO, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ʱ�� OSD ����
int ParamGetOsdTime(int n, PARAM_CONFIG_OSD_TIME *pParam)
{
	int x, y, ret;

	//if ( n>0 ) return FI_FAIL;
	ret = GetParamConfig(INDEX_PARAM_CONFIG_OSD_TIME, pParam, sizeof(*pParam), n);

	x = pParam->xPos;
	y = pParam->yPos;

	if( 0 != (x % 16) )
	{
		x = x - (x % 16);
	}
	if( 0 != (y % 16) )
	{
		y = y - (y % 16);
	}

	pParam->xPos = x;
	pParam->yPos = y;

	return ret;
}

int ParamSetOsdTime(int n, PARAM_CONFIG_OSD_TIME *pParam)
{
	PARAM_CONFIG_OSD_TIME param;
	int ret;

	if ( n>0 ) return FI_FAIL;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetOsdTime( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_OSD_TIME, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��Ƶ����
int ParamGetAudio(PARAM_CONFIG_AUDIO_ENCODE *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_AUDIO, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetAudio(PARAM_CONFIG_AUDIO_ENCODE *pParam)
{
	PARAM_CONFIG_AUDIO_ENCODE param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAudio( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			#if 0
			VencParamEasySetAudioSampleRate( pParam->sampleRate );
			VencParamEasySetAudioBitWidth( pParam->bitWidth );
			VencParamEasySetAudioEncodeType( pParam->encodeType );
			VencParamEasySetAudioChMode( pParam->chMode );
			#endif
			ret = SetParamConfig(INDEX_PARAM_CONFIG_AUDIO, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// �Զ�ά������
int ParamGetAutoMaintain(PARAM_CONFIG_AUTO_MAINTAIN *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_AUTO_MAINTAIN, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetAutoMaintain(PARAM_CONFIG_AUTO_MAINTAIN *pParam)
{
	PARAM_CONFIG_AUTO_MAINTAIN param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAutoMaintain( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_AUTO_MAINTAIN, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ¼�񹫹�����
int ParamGetRecordPublic(PARAM_CONFIG_RECORD_PUBLIC *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_RECORD_PUBLIC, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetRecordPublic(PARAM_CONFIG_RECORD_PUBLIC *pParam)
{
	PARAM_CONFIG_RECORD_PUBLIC param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetRecordPublic( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_RECORD_PUBLIC, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ¼��ͨ������
int ParamGetRecordParam(int n, PARAM_CONFIG_RECORD_PARAM *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_RECORD_PARAM, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetRecordParam(int n, PARAM_CONFIG_RECORD_PARAM *pParam)
{
	PARAM_CONFIG_RECORD_PARAM param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetRecordParam( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_RECORD_PARAM, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// IO������������
int ParamGetAlarmIo(PARAM_CONFIG_ALARM_IO *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_ALARM_IO, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetAlarmIo(PARAM_CONFIG_ALARM_IO *pParam)
{
	PARAM_CONFIG_ALARM_IO param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAlarmIo( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_ALARM_IO, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}


// ���ڲ���
int ParamGetSerial(PARAM_CONFIG_SERIAL *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_SERIAL, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetSerial(PARAM_CONFIG_SERIAL *pParam)
{
	PARAM_CONFIG_SERIAL param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetSerial( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_SERIAL, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// NTP����
int ParamGetNtp( PARAM_CONFIG_NTP *pParam )
{
	int ret = GetParamConfig( INDEX_PARAM_CONFIG_NTP, pParam, sizeof(*pParam), 0 );

	return ret;
}
int ParamSetNtp(PARAM_CONFIG_NTP *pParam)
{
	PARAM_CONFIG_NTP param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetNtp( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_NTP, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// email����
int ParamGetEmail(PARAM_CONFIG_EMAIL *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_EMAIL, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetEmail(PARAM_CONFIG_EMAIL *pParam)
{
	PARAM_CONFIG_EMAIL param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetEmail( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_EMAIL, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// �ƶ���ⱨ������
int ParamGetAlarmMoveDetect(int n, PARAM_CONFIG_ALARM_MOVE_DETECT *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_ALARM_MOVE_DETECT, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetAlarmMoveDetect(int n, PARAM_CONFIG_ALARM_MOVE_DETECT *pParam)
{
	PARAM_CONFIG_ALARM_MOVE_DETECT param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAlarmMoveDetect( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_ALARM_MOVE_DETECT, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��Ƶ�ڵ�
int ParamGetVideoOverlay(int n, PARAM_CONFIG_VIDEO_OVERLAY *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_OVERLAY, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetVideoOverlay(int n, PARAM_CONFIG_VIDEO_OVERLAY *pParam)
{
	PARAM_CONFIG_VIDEO_OVERLAY param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetVideoOverlay( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_OVERLAY, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��Ƶ��ʧ��������
int ParamGetAlarmVideoLose(int n, PARAM_CONFIG_ALARM_VIDEO_LOSE *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_ALARM_VIDEO_LOSE, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetAlarmVideoLose(int n, PARAM_CONFIG_ALARM_VIDEO_LOSE *pParam)
{
	PARAM_CONFIG_ALARM_VIDEO_LOSE param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAlarmVideoLose( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_ALARM_VIDEO_LOSE, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ftp ����
int ParamGetFtp( PARAM_CONFIG_FTP *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_FTP, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetFtp( PARAM_CONFIG_FTP *pParam )
{
	PARAM_CONFIG_FTP param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetFtp( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_FTP, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ��ʱץ��
int ParamGetSnapTimer(int n, PARAM_CONFIG_SNAP_TIMER *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_SNAP_TIMER, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetSnapTimer(int n, PARAM_CONFIG_SNAP_TIMER *pParam)
{
	PARAM_CONFIG_SNAP_TIMER param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetSnapTimer( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_SNAP_TIMER, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// icmp ����
int ParamGetIcmp(int n, PARAM_CONFIG_ICMP *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_ICMP, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetIcmp(int n, PARAM_CONFIG_ICMP *pParam)
{
	PARAM_CONFIG_ICMP param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetIcmp( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_ICMP, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// ddns ����
int ParamGetDdns(int n, PARAM_CONFIG_DDNS *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_DDNS, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetDdns(int n, PARAM_CONFIG_DDNS *pParam)
{
	PARAM_CONFIG_DDNS param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetDdns( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_DDNS, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// dtu ����
int ParamGetDtu( PARAM_CONFIG_DTU *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_DTU, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetDtu( PARAM_CONFIG_DTU *pParam)
{
	PARAM_CONFIG_DTU param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetDtu( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_DTU, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// wifi���Ӳ���
int ParamGetWifiConnect( PARAM_CONFIG_WIFI_CONNECT_T *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_WIFI_CONNECT, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetWifiConnect( PARAM_CONFIG_WIFI_CONNECT_T *pParam )
{
	PARAM_CONFIG_WIFI_CONNECT_T param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetWifiConnect( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_WIFI_CONNECT, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

#if 0
int ParamGetWifiList( CONFIG_WIFI_LIST_T *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_WIFI_LIST, pParam, sizeof(*pParam), 0);

	return ret;
}

int ParamSetWifiList( CONFIG_WIFI_LIST_T *pParam )
{
	CONFIG_WIFI_LIST_T param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetWifiList( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_WIFI_LIST, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				printf("SetParamConfig success\n");
				//SaveParamConfig();
			}
		}
	}
	
	return ret;

}
#endif

int ParamGetThreeg( PARAM_CONFIG_THREEG_T *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_THREEG, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetThreeg( PARAM_CONFIG_THREEG_T *pParam )
{
	PARAM_CONFIG_THREEG_T param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetThreeg( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_THREEG, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

int ParamGetAlarmVideoShelter( int n, PARAM_CONFIG_ALARM_VIDEO_SHELTER *pParam )
{
	if ( n>0 ) return FI_FAIL;
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_VIDEO_SHELTER, pParam, sizeof(*pParam), n);

	return ret;
}
int ParamSetAlarmVideoShelter( int n, PARAM_CONFIG_ALARM_VIDEO_SHELTER *pParam )
{
	PARAM_CONFIG_ALARM_VIDEO_SHELTER param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAlarmVideoShelter( n, &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_VIDEO_SHELTER, pParam, sizeof(*pParam), n);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}


// ���в���
int ParamGetAllParam(SYS_CONFIG *pParam)
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_TOTAL, pParam, sizeof(*pParam), 0);

	return ret;
}
int ParamSetAllParam(SYS_CONFIG *pParam)
{
	SYS_CONFIG param;
	int ret;
	
	memset( &param, 0x00, sizeof(param) );
	ret = ParamGetAllParam( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_TOTAL, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}
	}
	
	return ret;
}

// �ú���һ��ֻ��ϵͳ������ʱ�����,�����ж��Ƿ���Ҫ�Դ��̽��з�������ʽ���Ȳ���
int ParamGetDiskInit( PARAM_CONFIG_DISK_INIT *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_DISK_INIT, pParam, sizeof(*pParam), 0);

	return ret;
}
// ���ô��̳�ʼ��,������������ն�, �ն��������鵽�ò���, Ȼ����д��̳�ʼ��
// (�Ѵ��̷ֳ�2��������ʽ��), Ȼ��Ž�������Ӧ��
int ParamSetDiskInit( PARAM_CONFIG_DISK_INIT *pParam )
{
	int ret = -1;
	
	if( 0 <= pParam->initNum && pParam->initNum <= MAX_DISK_NUM )
	{
		ret = SetParamConfig(INDEX_PARAM_CONFIG_DISK_INIT, pParam, sizeof(*pParam), 0);
		if( FI_SUCCESS == ret )
		{
			SaveParamConfig();
		}	
	}
	
	return ret;
}

int ParamGetSendRtp( PARAM_CONFIG_SEND_RTP_T *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_SEND_RTP, pParam, sizeof(*pParam), 0);

	return ret; 
}
int ParamSetSendRtp( PARAM_CONFIG_SEND_RTP_T *pParam )
{
	int ret;
	PARAM_CONFIG_SEND_RTP_T param;
	ret = ParamGetSendRtp( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_SEND_RTP, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				//SaveParamConfig();
			}
		}			
	}	
	
	return ret;
}

int ParamGetErrorFilePath( PARAM_CONFIG_ERRORFILE_PATH_T  *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_ERRORFILE_PATH, pParam, sizeof(*pParam), 0);

	return ret; 
}

int ParamSetErrorFilePath( PARAM_CONFIG_ERRORFILE_PATH_T  *pParam )
{
	int ret;
	PARAM_CONFIG_ERRORFILE_PATH_T param;
	ret = ParamGetErrorFilePath( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_ERRORFILE_PATH, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SaveParamConfig();
			}
		}			
	}	
	
	return ret;
}

int ParamGetPtzInfo( PARAM_PTZ_INFO_T  *pParam )
{
	int ret = GetParamConfig(INDEX_PARAM_CONFIG_PTZ, pParam, sizeof(*pParam), 0);

	return ret; 
}

int ParamSetPtzInfo( PARAM_PTZ_INFO_T  *pParam )
{
	int ret;
	PARAM_PTZ_INFO_T param;
	ret = ParamGetPtzInfo( &param );
	if( FI_SUCCESS == ret )
	{
		if( 0 != memcmp(&param, pParam, sizeof(param)) )
		{
			ret = SetParamConfig(INDEX_PARAM_CONFIG_PTZ, pParam, sizeof(*pParam), 0);
			if( FI_SUCCESS == ret )
			{
				SyncParamConfig();
			}
		}			
	}	
	
	return ret;
}


