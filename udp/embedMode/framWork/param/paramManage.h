#ifndef __PARAMMANAGE_H__
#define __PARAMMANAGE_H__

#include "paramConfig.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// �ָ���������
void ParamSetFactoryConfigure();

// �ָ�Ĭ�ϲ���
void ParamSetDefaultParam();

// ϵͳ��������
int ParamGetBaseInfo(PARAM_CONFIG_BASE_INFO *pParam);
int ParamSetBaseInfo(PARAM_CONFIG_BASE_INFO *pParam);

// �������
int ParamGetNetwork(PARAM_CONFIG_NETWORK *pParam);
int ParamSetNetwork(PARAM_CONFIG_NETWORK *pParam);

// �ͻ��˻�IE��¼�û�����
int ParamGetClientUser(int n, PARAM_CONFIG_CLIENT_USER *pParam);
int ParamSetClientUser(int n, PARAM_CONFIG_CLIENT_USER *pParam);

// ��Ƶ���빫������
int ParamGetVideoEncodePublic(PARAM_CONFIG_VIDEO_ENCODE_PUBLIC *pParam);
int ParamSetVideoEncodePublic(PARAM_CONFIG_VIDEO_ENCODE_PUBLIC *pParam);

// ��������Ƶ�������
int ParamGetVideoEncode(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam);
int ParamSetVideoEncode(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam);

//��������Ƶ�������
int ParamGetVideoEncodeSlave(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam);
int ParamSetVideoEncodeSlave(int n, PARAM_CONFIG_VIDEO_ENCODE *pParam);

// ��Ƶ�ɼ���������
int ParamGetVideoBaseParam(int n, PARAM_CONFIG_VIDEO_BASE_PARAM *pParam);
int ParamSetVideoBaseParam(int n, PARAM_CONFIG_VIDEO_BASE_PARAM *pParam);

// logo OSD ����
int ParamGetOsdLogo(int n, PARAM_CONFIG_OSD_LOGO *pParam);
int ParamSetOsdLogo(int n, PARAM_CONFIG_OSD_LOGO *pParam);

// ʱ�� OSD ����
int ParamGetOsdTime(int n, PARAM_CONFIG_OSD_TIME *pParam);
int ParamSetOsdTime(int n, PARAM_CONFIG_OSD_TIME *pParam);

// ��Ƶ����
int ParamGetAudio(PARAM_CONFIG_AUDIO_ENCODE *pParam);
int ParamSetAudio(PARAM_CONFIG_AUDIO_ENCODE *pParam);

// �Զ�ά������
int ParamGetAutoMaintain(PARAM_CONFIG_AUTO_MAINTAIN *pParam);
int ParamSetAutoMaintain(PARAM_CONFIG_AUTO_MAINTAIN *pParam);

// ¼�񹫹�����
int ParamGetRecordPublic(PARAM_CONFIG_RECORD_PUBLIC *pParam);
int ParamSetRecordPublic(PARAM_CONFIG_RECORD_PUBLIC *pParam);

// ¼��ͨ������
int ParamGetRecordParam(int n, PARAM_CONFIG_RECORD_PARAM *pParam);
int ParamSetRecordParam(int n, PARAM_CONFIG_RECORD_PARAM *pParam);

// IO������������
int ParamGetAlarmIo(PARAM_CONFIG_ALARM_IO *pParam);
int ParamSetAlarmIo(PARAM_CONFIG_ALARM_IO *pParam);

// ���ڲ���
int ParamGetSerial(PARAM_CONFIG_SERIAL *pParam);
int ParamSetSerial(PARAM_CONFIG_SERIAL *pParam);

// NTP
int ParamGetNtp(PARAM_CONFIG_NTP *pParam);
int ParamSetNtp(PARAM_CONFIG_NTP *pParam);

// Email����
int ParamGetEmail(PARAM_CONFIG_EMAIL *pParam);
int ParamSetEmail(PARAM_CONFIG_EMAIL *pParam);

// �ƶ�������
int ParamGetAlarmMoveDetect(int n, PARAM_CONFIG_ALARM_MOVE_DETECT *pParam);
int ParamSetAlarmMoveDetect(int n, PARAM_CONFIG_ALARM_MOVE_DETECT *pParam);

// ��Ƶ�ڵ�
int ParamGetVideoOverlay(int n, PARAM_CONFIG_VIDEO_OVERLAY *pParam);
int ParamSetVideoOverlay(int n, PARAM_CONFIG_VIDEO_OVERLAY *pParam);

// ��Ƶ��ʧ��������
int ParamGetAlarmVideoLose(int n, PARAM_CONFIG_ALARM_VIDEO_LOSE *pParam);
int ParamSetAlarmVideoLose(int n, PARAM_CONFIG_ALARM_VIDEO_LOSE *pParam);

// ftp ����
int ParamGetFtp(PARAM_CONFIG_FTP *pParam);
int ParamSetFtp(PARAM_CONFIG_FTP *pParam);

// ��ʱץ��
int ParamGetSnapTimer(int n, PARAM_CONFIG_SNAP_TIMER *pParam);
int ParamSetSnapTimer(int n, PARAM_CONFIG_SNAP_TIMER *pParam);

// ICMP
int ParamGetIcmp(int n, PARAM_CONFIG_ICMP *pParam);
int ParamSetIcmp(int n, PARAM_CONFIG_ICMP *pParam);

// ddns ����
int ParamGetDdns(int n, PARAM_CONFIG_DDNS *pParam);
int ParamSetDdns(int n, PARAM_CONFIG_DDNS *pParam);

// dtu ����
int ParamGetDtu( PARAM_CONFIG_DTU *pParam);
int ParamSetDtu( PARAM_CONFIG_DTU *pParam);

// wifi ���Ӳ���
int ParamGetWifiConnect( PARAM_CONFIG_WIFI_CONNECT_T *pParam );
int ParamSetWifiConnect( PARAM_CONFIG_WIFI_CONNECT_T *pParam );

int ParamGetThreeg( PARAM_CONFIG_THREEG_T *pParam );
int ParamSetThreeg( PARAM_CONFIG_THREEG_T *pParam );

// ��Ƶ�ڵ�
int ParamGetAlarmVideoShelter( int n, PARAM_CONFIG_ALARM_VIDEO_SHELTER *pParam );
int ParamSetAlarmVideoShelter( int n, PARAM_CONFIG_ALARM_VIDEO_SHELTER *pParam );

//���в���
int ParamGetAllParam(SYS_CONFIG *pParam);
int ParamSetAllParam(SYS_CONFIG *pParam);

// ���ô��̳�ʼ��,������������ն�, �ն��������鵽�ò���, Ȼ����д��̳�ʼ��
// (�Ѵ��̷ֳ�2��������ʽ��), Ȼ��Ž�������Ӧ��
int ParamSetDiskInit( PARAM_CONFIG_DISK_INIT *pParam );
int ParamGetDiskInit( PARAM_CONFIG_DISK_INIT *pParam );

// ����IPC ͨ��UDP Э����ָ����IP+�˿ڷ�������RTP��
int ParamGetSendRtp( PARAM_CONFIG_SEND_RTP_T *pParam );
int ParamSetSendRtp( PARAM_CONFIG_SEND_RTP_T *pParam );

//error�ļ�
int ParamGetErrorFilePath( PARAM_CONFIG_ERRORFILE_PATH_T  *pParam );
int ParamSetErrorFilePath( PARAM_CONFIG_ERRORFILE_PATH_T  *pParam );

int ParamGetPtzInfo( PARAM_PTZ_INFO_T  *pParam );
int ParamSetPtzInfo( PARAM_PTZ_INFO_T  *pParam );


// wifi�б�
//int ParamGetWifiList( CONFIG_WIFI_LIST_T *pParam );
//int ParamSetWifiList( CONFIG_WIFI_LIST_T *pParam );


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PARAMMANAGE_H__

