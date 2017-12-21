/*
*******************************************************************************
**  Copyright ( c ) 2012, ���������޹�˾, All rights reserved.
**  ���ߣ����Ž�
**  ��ǰ�汾��v1.0
**  ��������: 2015.10.26
**  �ļ�˵��: �ͻ���sdk �ӿں���
    ʹ��ע������: 
    1. ���к����ķ���ֵ, ���û���ر�˵��, �򷵻�0 ��ʾ�ɹ�; ����-1 ��ʾʧ��δ֪����;
    	��������ֵ�������������μ�ö�� CERROR_TYPE_EN;
    	�ر�ע��: ��������ķŻ�ֵΪָ��, ����ΪNULL, ��������ں����� detail ��������,
    	��ʽΪ "errno=%d",����APP ���Ը���detail ���ص�ֵ��ǰ5 ���ֽ��Ƿ�Ϊ"errno "��
    	�ж��Ǵ�����Ϣ���Ա��ػ��Ƿ�����;
    2. ÿ����¼���û�ֻ֧��1 ·�ط�, ��֧�ֶ�·�ط�;
    3. ��������Ĳ���ע���д�"out" �ؼ���, ���ʾ�ò����з���ֵ;
    4. �������нӿ�, ����Hwsdk ��ͷ, �������ǽӿڷ��ʵĶ���ؼ���(���û�����ʾ���ؽӿ�), 
       Ȼ����ǽӿ���ʵ�ֵĹ���;
       �ӿڷ��ʵĶ���ؼ���Ϊ:
       1) Mng ���������
       2) Dev �����豸
       3) P2pd p2p ������
    5. ����ָ����������, ������˵������ΪNULL, ������ΪNULL;
    6. ���������������, ���Ϊ����, ��ΪUTF-8 ��ʽ;
    7. ����"+++" �ؼ��ֲ���Ϊ�Խ�ʱ�Ƚ����׷����󲿷�, ������ϸ��;
    8. ����ƽ̨ͳһ�����:
       1) ���к����ķ���ֵʹ�ô���ű�ʾ;
       2) �������ֵ��ָ��, ���ڷ��ص���ϸ��Ϣ������ϴ����, ����:
       		"This device is not exist|errno=40125"
       '|' ǰ���ʾ��ϸ��Ϣ; 
       '|' �����ʾ�����; 
*******************************************************************************
*/ 

#ifndef __HWSDK_H__
#define __HWSDK_H__

#ifdef WIN32
#define HWSDK_API extern "C" __declspec(dllexport)
#else
#define HWSDK_API // extern "C"
#endif // #ifdef WIN32

#include "hwsdkType.h"
#include "const.h"

/*
* fn: ��ʼ��SDK, �ڵ��������ӿں���ǰ�����ȵ��ñ��ӿڳ�ʼ����Դ;
* param: ��ʼ���ṹ��, ����ĳ�Ա���û���ر�˵��,
		����븳ֵ, ����ΪNULL, ��������δ֪����.
*/
HWSDK_API int HwsdkInit( INIT_HWSDK_PARAM_T *param );
//test 

void HwsdkTestDoorBeel(char *hostFromEngineer, unsigned long mngHostFromApp, unsigned short mngPortFromApp );


/*
* fn: ȥ��ʼ��SDK, �������ʹ��sdk �ӿ�, ������Ҫ���³�ʼ��, ��
      ��Ҫ�ȵ��ñ��ӿڽ����ͷ���Դ.
*/
HWSDK_API int HwsdkDeInit();

/*
* fn: �����˺��Ƿ�����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: 0, ����; -1, ������.
*/
HWSDK_API int HwsdkMngCheckRigster( char *account, char *language, char *detail, int detailSize );

/*
* fn: ����ע����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* oemId�����OEM�ͻ��Ŀͻ����룬�ڶ������ʱ��������, ��"oem8001";
* oemBrand��OEMƷ�����ƣ��ڶ������ʱ��������, �� "nobrand"Ϊ����;
* timezone: ʱ��, [-12, +11];
* rigsterCode: out, ע����;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngApplyRigsterCode( char *account, char *language, char *oemId, 
										char *oemBrand, float timezone, char rigsterCode[16],
										char *detail, int detailSize );

/*
* fn: ע���û�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd1: ��һ�����������;
* pwd2: �ڶ������������;
* rigsterCode: �ӽӿ�HwsdkMngApplyRigsterCode() ��ȡ����ע����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* from: �û���Դ��Ϊ�ͻ��˶�Ӧ��IP;
* oemId�����OEM�ͻ��Ŀͻ����룬�ڶ������ʱ��������, ��"oem8001";
* oemBrand��OEMƷ�����ƣ��ڶ������ʱ��������, �� "nobrand"Ϊ����;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngRigster( char *account, char *pwd1, char *pwd2, char *rigsterCode, 
								char *language, char *from, char *oemId, 
								char *oemBrand, char *detail, int detailSize );

/*
* fn: �����һ�����, ����������ʱ, �ñ��ӿ�����һ����֤��, ��ΪHwsdkMngRecoverPwd()
	  �����, �����һ�����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* oemId�����OEM�ͻ��Ŀͻ����룬�ڶ������ʱ��������, ��"oem8001";
* oemBrand��OEMƷ�����ƣ��ڶ������ʱ��������, �� "nobrand"Ϊ����;
* identifyCode: out, ��֤��;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngApplyRecoverPwd( char *account, char *language, char *oemId, 
										char *oemBrand, float timezone, char *identifyCode,  
										char *detail, int detailSize );

/*
* fn: �һ�����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* identifyCode: ��֤��, ���ڴ�HwsdkMngApplyRecoverPwd() �ӿڲ���identifyCode ���ص�ֵ;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngRecoverPwd( char *account, char *pwd, char *language,
							char *identifyCode, char *detail, int detailSize );

/*
* fn: ʹ�þ������޸�������;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* newPwd: ������;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngModifyPwd( char *account, char *pwd, char *language,
							char *newPwd, char *detail, int detailSize );

/*
* fn: ��ѯ�豸��ӵ���߰Ѹ��豸�������Щ�û�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devChannels: Ҫ��ѯ���豸ͨ��, ��ʽΪ"AAAABBBB-ABCD-1234-ABCD-123456789001:2",
				":" ��ǰ��ʾ�豸ID, �����ʾͨ����;
* accountWhoIndate: out, �Ѹ��豸�������Щ�˺�(������Ч��), ����˺���","�ֿ�, 
			�˺ź���Ч����";"�ֿ�, �����Ч��Ϊ"0000-00-00 00:00:00" ��ʾ������Ч,
			����: "15818757328;2016-10-10 00:00:00,13922589635;0000-00-00 00:00:00",
			һ���豸����ܷ����8 ���û�;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngGetDevShareAccount( char *account, char *pwd, char *language, 
										 	char *devChannels, char accountWhoIndate[1024], 
										 	char *detail, int detailSize );

/*
* fn: �����豸��ӵ���߰Ѹ��豸�������Щ�û�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devChannels: Ҫ������豸ͨ��, ":" ��ǰ��ʾ�豸ID, �����ʾͨ����, ���ͨ����","����,
			   ���� "AAAABBBB-ABCD-1234-ABCD-123456789001:2,AAAABBBB-ABCD-1234-ABCD-123456789002:1",
* accountWhoIndate: �Ѹ��豸�������Щ�˺�(������Ч��), ����˺���","�ֿ�, 
			�˺ź���Ч����";"�ֿ�, �����Ч��Ϊ"0000-00-00 00:00:00" ��ʾ������Ч,
			����: "15818757328;2016-10-10 00:00:00,13922589635;0000-00-00 00:00:00",
			һ���豸����ܷ����8 ���û�;
* detail: out, ������Ϣ, ���ͬʱ�޸Ķ��ͨ��, ����detail �з��ش����;
* detailSize: detail ָ��ռ�ĳ���;
* ʹ��˵��: ����ʱ, ���ӿ�֧�ֵ��豸ͨ�����û�����, Ҳ֧�ֶ��豸ͨ�����û�����,
            ʹ��ʱ����ʵ���������������;
*/
HWSDK_API int HwsdkMngSetDevShareAccount( char *account, char *pwd, char *language, 
											char *devChannels, char accountWhoIndate[1024],
											char *detail, int detailSize );
											
/*
* fn: ȡ���豸����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devChannels: Ҫ��ѯ���豸ͨ��, ��ʽΪ"AAAABBBB-ABCD-1234-ABCD-123456789001:2",
				":" ��ǰ��ʾ�豸ID, �����ʾͨ����;
* accountWho: ����Щ�˺�ȡ������, ����˺���","�ֿ�, 			
			����: "15818757328,13922589635", һ���豸����ܷ����8 ���û�;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* ʹ��˵��: ȡ���豸����ʱ, ���ӿ�֧�ֵ����豸ͨ�����û��û�����, Ҳ֧�ֶ��豸ͨ�����û�����,
            ʹ��ʱ����ʵ���������������;
*/
HWSDK_API int HwsdkMngDelDevShareAccount( char *account, char *pwd, char *language, 
											char *devChannels, char accountWho[1024], 
											char *detail, int detailSize );

/* 
* fn: ȡ���������豸����;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devChannels: Ҫ��ѯ���豸ͨ��, ��ʽΪ"AAAABBBB-ABCD-1234-ABCD-123456789001:2",
				":" ��ǰ��ʾ�豸ID, �����ʾͨ����;
	���ͨ����','����, ����:"AAAABBBB-ABCD-1234-ABCD-123456789001:2,AAAABBBB-ABCD-1234-ABCD-123456789001:0";
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* ʹ��˵��: ȡ���豸����ʱ, ���ӿ�֧�ֵ����豸ͨ�����û��û�����, Ҳ֧�ֶ��豸ͨ�����û�����,
            ʹ��ʱ����ʵ���������������;
*/
HWSDK_API int HwsdkMngDelBeshareDevs( char *account, char *pwd, char *language, 
									char *devChannels, char *detail, int detailSize );


/*  
* fn: �û���½;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* oemId�����OEM�ͻ��Ŀͻ����룬�ڶ������ʱ��������, ��"oem8001";
* oemBrand��OEMƷ�����ƣ��ڶ������ʱ�������ã��� "nobrand"Ϊ����;
* pLoginRes: out, ������½�ӿ�, ����һЩ�򵥵��û���Ϣ;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: 0, ��½�ɹ�; �����½ʧ��, ʧ����Ϣ��detail ����;
*/
HWSDK_API int HwsdkMngLogin( char *account, char *pwd, char *language,
							char *oemId, char *oemBrand, LOGIN_RES_T *pLoginRes, 
							char *detail, int detailSize );

/* 
* fn: ����豸;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* nodeName: �豸���ڵĽڵ�����, �����ӵ����ڵ�, �ñ���Ϊ NULL;
* devIds: �豸ID�����кţ���ÿ̨�豸��Ψһʶ���룬����ͬʱ�ύ�����ÿ��ID֮��ʹ�ð�Ƕ��ŷָ�;
			��: "ABCD-HUAWU-123,ABCD-HUAWU-125";
* groupName: ��������, ����������豸ʱָ������;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: �������ID ����ӳɹ�, �򷵻سɹ�(0); ���򷵻�ʧ�ܵ�ID �͸�ID ��Ӧ��ʧ����Ϣ;
	����ж���豸���ʧ��, ���÷ֺŸ���, ����:
	123456789000:The device ID has been used by other user.;999000999000:The device ID has been used by other user.;
*/
HWSDK_API int HwsdkMngAddDev( char *account, char *pwd, char *language, char *nodeName,
								char *devIds, char *groupName, char *detail, int detailSize );

/* 
* fn: �޸�ͨ��;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd���û�����;        
* language���û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId���豸ID(���к�), �������豸ID,ʹ�ö��Ÿ���,����"AAAABBBB-ABCD-1234-ABCD-123456789002,
		AAAABBBB-ABCD-1234-ABCD-123456789003,AAAABBBB-ABCD-1234-ABCD-123456789007,AAAABBBB-ABCD-1234-ABCD-123456789008",
		����֮����豸ID �Ƕ�����, ������ͬ;      
* channels: ���ͨ����ʱ����Ҫʹ�ö��Ÿ���,����"0,1,2,3";
* chnType: ��HW_CHN_TYPE_EN, ��Ҫ��ʽ�����ַ���, ���ͨ����ʱ����Ҫʹ�ö��Ÿ���,����"0,0,2,1",
			����ֵȡ���ڻ�ȡ�豸�б�ķ���ֵ�е�ͨ���ṹ��, ���������ͨ�������� WEBS_DEV_INFO_T 
			�µ�CAMERA_ATTR_T(Ŀǰֻ�����,�Ժ������豸���ͺ����չ) ����, ��ô chnType == CHN_TYPE_CAMERA;
* channelNames: Ҫ�޸ĵ�ͨ������, dev_ch�ж��ٸ�����, �����ж��ٸ�����, ������Ҫʹ��UTF-8 ����(�����ֽڱ�ʾһ������);
	// ����: ���ſ�,�ֿ����,pingyin,���� ��
	// %E5%A4%A7%E9%97%A8%E5%8F%A3,%E4%BB%93%E5%BA%93%E8%B4%A7%E6%9E%B6,pingyin,%E5%90%8E%E9%97%A8
* group: ����, ��ӷ�����������, �ѱ������ӵ�������, ����"group_a1,group_a2,group_a1,group_0";
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;	  
* return: �������ͨ���޸ĳɹ�, �򷵻سɹ�(0); ���򷵻�ʧ�ܵ�ID;
	����ж��ͨ���޸�ʧ��, ���÷ֺŸ���, ����:0:ʧ��ԭ��,����Ϊ��;1:ʧ��ԭ��,����Ϊ��;
* +++ʹ���ر�˵��: 
	1. ͨ����Ŵ�0��ʼ;
	2. �豸ID(�ǿ�), �豸ͨ��(�ǿ�)��ͨ������(����Ϊ��)����������(����Ϊ��), ����һһ��Ӧ;
  ����: devId: "AAAABBBB-ABCD-1234-ABCD-123456789002,
				AAAABBBB-ABCD-1234-ABCD-123456789003,
				AAAABBBB-ABCD-1234-ABCD-123456789007,
				AAAABBBB-ABCD-1234-ABCD-123456789008";
		channels: "0,1,2,3"; 
		chnType: "0,0,1,2"
		channelNames:"A,B,C,D"; 
		group:"G1,G2,,GN"; 
  ��ʾ:
  1. �豸AAAABBBB-ABCD-1234-ABCD-123456789002 ͨ��1 ��Ƶͨ�� ����Ϊ A, ���ֵ�G1 ��;
  2. �豸AAAABBBB-ABCD-1234-ABCD-123456789003 ͨ��2 ��Ƶͨ�� ����Ϊ B, ���ֵ�G2 ��;
  3. �豸AAAABBBB-ABCD-1234-ABCD-123456789007 ͨ��3 ����ͨ�� ����Ϊ C, ���ֵ�Ĭ����;
  4. �豸AAAABBBB-ABCD-1234-ABCD-123456789008 ͨ��4 ����ͨ�� ����Ϊ D, ���ֵ�GN ��;
* detail: out, ������Ϣ, ���ͬʱ�޸Ķ��ͨ��, ����detail �з��ش����;
* detailSize: detail ָ��ռ�ĳ���
*/
HWSDK_API int HwsdkMngModifyChn( char *account, char *pwd, char *language,
						char *devId, char *channels, char *chnType, char *channelNames, 
						char *group, char *detail, int detailSize );

/* 
* fn: ɾ���豸;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId���豸ID, ɾ���豸ֻ��һ��һ��ɾ��;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngDelDev( char *account, char *pwd, char *language, char *devId, 
										char *detail, int detailSize );

/* �ر�ע��: �ڵ�ĸ��������ڶ��������
* fn: ��ӽڵ�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����; 
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* nodeName���ڵ�����;
* parentNodeName: ���ڵ�����, ���ΪNULL, ��ʾ���ڵ�;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/						
HWSDK_API int HwsdkMngAddNode( char *account, char *pwd, char *language, char *nodeName, 
								char *parentNodeName, char *detail, int detailSize );

/* 
* fn: �޸Ľڵ�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* nodeName���ڵ�����;
* parentNodeName: ���ڵ�����, ���ΪNULL, ��ʾ���ڵ�;
* nodeIndex: �ýڵ��ȫ��Ψһ����;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/						
HWSDK_API int HwsdkMngModifyNode( char *account, char *pwd, char *language, char *nodeName, 
						char *parentNodeName, unsigned int nodeIndex, 
						char *detail, int detailSize );

/* 
* fn: ɾ���ڵ�;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* nodeName���ڵ�����;
* parentNodeName: ���ڵ�����, ���ΪNULL, ��ʾ���ڵ�;
* nodeIndex: �ýڵ��ȫ��Ψһ����;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngDelNode( char *account, char *pwd, char *language, char *nodeName, 
				 		char *parentNodeName, unsigned int nodeIndex, 
				 		char *detail, int detailSize );

/* 
* fn: ��ѯ�豸��Ϣ;
* account: �˺ţ���Ϊ�ֻ��š�����;;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId���豸ID(���к�);
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: �ӷ�������ȡ�����豸����Ϣ, ���ΪNULL, ���ȡʧ�ܻ����豸������,
	��ϸʧ����Ϣ�� detail ����;
* �ر�ע��: ���صĽ������ʹ��HwsdkMngReleaseDevInfo() �ͷ�, ������ܻ�����ڴ�й©;
*/
HWSDK_API WEBS_DEV_INFO_T *HwsdkMngGetDevInfo( char *account, char *pwd, char *language, char *devId, 
													char *detail, int detailSize );

/* 
* fn: �ͷ�HwsdkMngGetDevInfo() �ķ���ֵ;
*/
HWSDK_API void HwsdkMngReleaseDevInfo( WEBS_DEV_INFO_T *pDevInfo );

/* 
* fn: ��ȡ�豸�б�;
* account: �˺ţ���Ϊ�ֻ��š�����;;
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: �ӷ�������ȡ�����豸����Ϣ, ���ΪNULL, ���ȡʧ�ܻ����豸������,
	��ϸʧ����Ϣ�� detail ����;
* ע��: ���ص�ֵ����ʹ�� HwsdkMngReleaseDevList �ͷ�;
*/
HWSDK_API WEBS_DEV_LIST_T *HwsdkMngGetDevList( char *account, char *pwd, char *language,
												char *detail, int detailSize );
/* 
* fn: �ͷ�HwsdkMngGetDevList() �ķ���ֵ;
*/
HWSDK_API void HwsdkMngReleaseDevList( WEBS_DEV_LIST_T *pDevList );

/*
* fn:  ��ȡ�ͻ���������Ϣ;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* user_lang %s���û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* oemId�����OEM�ͻ��Ŀͻ����룬�ڶ������ʱ��������, ��"oem8001";
* oemBrand��OEMƷ�����ƣ��ڶ������ʱ�������ã��� "nobrand"Ϊ����;
* appOs: app �����ڵĲ���ϵͳ, "android" or "ios" or "windows", ����Ϊ��;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: �ӷ�������ȡ�����豸����Ϣ, ���ΪNULL, ���ȡʧ�ܻ����豸������,
	��ϸʧ����Ϣ�� detail ����;
* ע��: �ýӿڵķ���ֵ����ʹ�� HwsdkMngReleaseClientInfo() �ͷ�;
*/
HWSDK_API WEBS_CLIENT_INFO_T *HwsdkMngGetClientInfo( char *language, char *oemId, char *oemBrand,
													char *appOs, char *detail, int detailSize );

/*
* fn: �ͷ�HwsdkMngGetClientInfo() �ķ���ֵ;
*/
HWSDK_API void HwsdkMngReleaseClientInfo( WEBS_CLIENT_INFO_T *pClientInfo );

/* 
* fn: ��ȡ��Ϣ���Ͳ���;
* account: �˺ţ���Ϊ�ֻ��š�����
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* timezone: ʱ��, [-12, +11];
* pntq: out, ��Ϣ����ʱ���(Push Notification time quantum), ȡֵ��Χ�� HW_PNTQ_EN;
* dayScheme: out, ��pntq = PNTQ_DAYʱ��Ч, ������Ե�ʱ���ѡ��,ÿ���ֽڱ�ʾ��Сʱ,48 = 24Сʱ X 2;
	ʹ��ʮ�����Ʊ�ʾ, ���� dayScheme[0] == 0x1, ���ʾ00:00:00~00:30:00 ��Ч, ������Ч, ����ʱ�������;
* nightScheme: out, ��pntq = PNTQ_NIGHTʱ��Ч, ���ϲ��Ե�ʱ���ѡ��,ÿ���ֽڱ�ʾ��Сʱ,48 = 24Сʱ X 2;
  	ʹ��ʮ�����Ʊ�ʾ, ���� nightScheme[0] == 0x1, ���ʾ00:00:00~00:30:00 ��Ч, ������Ч, ����ʱ�������;
  ע���������ϵ�ʱ���������ȫ����.
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngGetPushNotificationScheme( char *account, char *pwd, char *language, float timezone,
											int *pntq, char dayScheme[48], char nightScheme[48],
											char *detail, int detailSize );

/*
* fn: ������Ϣ���Ͳ���;
* account: �˺ţ���Ϊ�ֻ��š�����
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* pntq: ��Ϣ����ʱ���(Push Notification time quantum), ȡֵ��Χ�� HW_PNTQ_EN;
* dayScheme: ��pntq = PNTQ_DAYʱ��Ч, ������Ե�ʱ���ѡ��,ÿ���ֽڱ�ʾ��Сʱ,48 = 24Сʱ X 2;
	ʹ��ʮ�����Ʊ�ʾ, ���� dayScheme[0] == 0x1, ���ʾ00:00:00~00:30:00 ��Ч, ������Ч, ����ʱ�������;
* nightScheme: ��pntq = PNTQ_NIGHTʱ��Ч, ���ϲ��Ե�ʱ���ѡ��,ÿ���ֽڱ�ʾ��Сʱ,48 = 24Сʱ X 2;
  	ʹ��ʮ�����Ʊ�ʾ, ���� nightScheme[0] == 0x1, ���ʾ00:00:00~00:30:00 ��Ч, ������Ч, ����ʱ�������;
  ע���������ϵ�ʱ���������ȫ����.
* timezone: ʱ��, [-12, +11];
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngSetPushNotificationScheme( char *account, char *pwd, char *language,
											int pntq, char dayScheme[48], char nightScheme[48],
											float timezone, char *detail, int detailSize );

/*
* fn: �޸��û���Ϣ
* account: �˺ţ���Ϊ�ֻ��š�����
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* nickname���ǳ�;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngModifyUsrInfo( char *account, char *pwd, char *language, char *nickname, 
			  							char *detail, int detailSize );

/*
* fn: ��ȡͷ��ͼƬ
* account: �˺ţ���Ϊ�ֻ��š�����
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* headPic��out, head picture, ͷ��ͼƬ, �ݶ�ΪJPG ��ʽ;
* headPicSize: in, headPic ָ��ռ�Ĵ�С; out, ͷ��ͼƬ�Ĵ�С
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngGetHeadPic( char *account, char *pwd, char *language, 
									char *headPic, int *headPicSize,
				  					char *detail, int detailSize );

/*
* fn: �޸�ͷ��ͼƬ
* account: �˺ţ���Ϊ�ֻ��š�����
* pwd: ����;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* headPic��head picture, ͷ��ͼƬ, �ݶ�ΪJPG ��ʽ;
* headPicSize: ͷ��ͼƬ�Ĵ�С
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngModifyHeadPic( char *account, char *pwd, char *language, 
								char *headPic, int headPicSize,
			  					char *detail, int detailSize );

/*
* fn: ��ȡ����ͨ��������Ϣ������;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* timezone: ʱ��, [-12, +11];
* days: ���ر��������;
* recType: ��¼����, �μ�HW_REC_TYPE_EN;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ����ͨ��δ������Ϣ����, �Լ�������ϢͼƬ������(�������);
*/
HWSDK_API ALL_NEW_MSG_SIZE_T *HwsdkMngGetHistoryAlarmSize( char *account, char *pwd, char *language, 										
											float timezone, int days, int recType, char *detail, int detailSize );

/* 
* fn: �ͷ� HwsdkMngGetHistoryAlarmSize() ���ص�����;
* ptr: �ӿ� HwsdkMngGetHistoryAlarmSize() �ķ���ֵ;
*/														
HWSDK_API void HwsdkMngFreetHistoryAlarmSizeResult( ALL_NEW_MSG_SIZE_T *ptr );	

/*
* fn: ��ȡ����ͨ��������Ϣ������;
	HwsdkMngGetHistoryAlarmSizeEx() ��HwsdkMngGetHistoryAlarmSize() ��������
	1. HwsdkMngGetHistoryAlarmSizeEx(): ���صĽ��û�����ڵĸ���;
	2. HwsdkMngGetHistoryAlarmSize():���صĽ�������ֽ��졢���졢ǰ�졢����ǰ;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* timezone: ʱ��, [-12, +11];
* days: ���ر��������;
* recType: ��¼����, �μ�HW_REC_TYPE_EN;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ����ͨ��δ������Ϣ����, �Լ�������ϢͼƬ������(�������);
*/
HWSDK_API ANYDAY_NEW_MSG_SIZE_T *HwsdkMngGetHistoryAlarmSizeEx( char *account, char *pwd, char *language, 										
										float timezone, int days, int recType, char *detail, int detailSize );
/* 
* fn: �ͷ�HwsdkMngGetHistoryAlarmSizeEx() ���ص�����;
* ptr: �ӿ�HwsdkMngGetHistoryAlarmSizeEx() �ķ���ֵ;
*/														
HWSDK_API void HwsdkMngFreetHistoryAlarmSizeResultEx( ANYDAY_NEW_MSG_SIZE_T *ptr );


/*
* fn: ��ѯ��ʷ������Ϣ, �����û��Ĳ���, ��Ϊ��ʱ��β�ѯ����������ѯ����������ѯ;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId: �豸ID(���к�);
* chnType: ͨ������, ��HW_CHN_TYPE_EN, ����ֵӦ����HwsdkMngGetHistoryAlarmSize() ����ֵ�е�
			anyDay->chnType һ��;
* chn: ͨ����, �ò�����chnType ���ʹ��, ��ʾ��ͬͨ�����͵�ͨ����;
* tsBegin: ��ʼʱ��, ��ʽΪ "2016-01-02 00:30:22", ��AA_TIME == appAction, ʱ��Ч;
* tsEnd: ����ʱ��, ��ʽΪ "2016-01-02 00:30:22", ��AA_TIME == appAction, ʱ��Ч;
* timezone: ʱ��, [-12, +11], ��AA_TIME == appAction, ʱ��Ч;
* appAction: �����û��Ĳ���, ȡֵ��Χ�� APP_ACTION_EN;
* msgIndex: ��Ӧ ALARM_MSG_T ����� msgIndex, ����appAction���ʹ��, ��ʾ��ĳ����Ϣ��ʼ����;
* days: ���ر��������;
* recType: ��¼����, �μ�HW_REC_TYPE_EN;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ��ʷ������Ϣ����, ��������Ҫʹ��HwsdkMngReleaseHistoryAlarmMsgResult() �ͷ�;
* ע��: ÿ����෵��500 ��;
*/
HWSDK_API ALARM_MSG_T *HwsdkMngGetHistoryAlarmMsg( char *user, char *pwd, char *language, 
													char *devId, unsigned char chnType, int chn,
													char tsBegin[20], char tsEnd[20],float timezone,
													unsigned char appAction, unsigned int msgIndex, 
													int days, int recType, char *detail, int detailSize );										
/*
* fn: �ͷ�HwsdkMngGetHistoryAlarmMsg() ���ص�����;
* ptr: �ӿ�HwsdkMngGetHistoryAlarmMsg() �ķ���ֵ;
*/														
HWSDK_API void HwsdkMngReleaseHistoryAlarmMsgResult( ALARM_MSG_T *ptr );
HWSDK_API void HwsdkDoorBellsRelease( DOOR_BELL_T *ptr ); //door bells


/*
* fn: ��ѯ��ʷ������Ϣ, �����û��Ĳ���, ��Ϊ��ʱ��β�ѯ����������ѯ����������ѯ;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId: �豸ID(���к�);
* chnType: ͨ������, ��HW_CHN_TYPE_EN, ����ֵӦ����HwsdkMngGetHistoryAlarmSizeEx() ����ֵ�е�
			anyDay->chnType һ��;
* chn: ͨ����, �ò�����chnType ���ʹ��, ��ʾ��ͬͨ�����͵�ͨ����;
* ts: ĳ�������ʱ��, ��ʽΪ "2016-01-02 00:30:22", ��AA_TIME == appAction, ʱ��Ч;
* timezone: ʱ��, [-12, +11], ��AA_TIME == appAction, ʱ��Ч;
* appAction: �����û��Ĳ���, ȡֵ��Χ�� APP_ACTION_EN;
* msgIndex: ��Ӧ ALARM_MSG_T ����� msgIndex, ����appAction���ʹ��, ��ʾ��ĳ����Ϣ��ʼ����;
* days: ���ر��������;
* recType: ��¼����, �μ�HW_REC_TYPE_EN;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ��ʷ������Ϣ����, ��������Ҫʹ�� HwsdkMngReleaseHistoryAlarmMsgResultEx() �ͷ�;
* ע��: ÿ����෵��500 ��;
*/
HWSDK_API ALARM_MSG_T *HwsdkMngGetHistoryAlarmMsgEx( char *user, char *pwd, char *language, 
													char *devId, unsigned char chnType, int chn,
													char ts[20],float timezone,
													unsigned char appAction, unsigned int msgIndex, 
													int days, int recType, char *detail, int detailSize );


/*
this is a funtion about getting door bell from webs
data:12.08
*/

HWSDK_API DOOR_BELL_T *HwsdkMegGetDoorBell( char *user, char *pwd, char *language, 
											char *devId, unsigned char chnType, int chn,
											float timezone,											
											char *detail, int detailSize );


/* 
* fn: �ͷ�HwsdkMngGetHistoryAlarmMsgEx() ���ص�����;
* ptr: �ӿ�HwsdkMngGetHistoryAlarmMsgEx() �ķ���ֵ;
*/
HWSDK_API void HwsdkMngReleaseHistoryAlarmMsgResultEx( ALARM_MSG_T *ptr );

/* 
* fn: ��ӷ���;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* groupName: �������;
* groupNum: ����Ŀǰ���������1, ȡֵ��Χ[1,10]. ����Ŀǰ�ж��ٸ���, ��10 ����ʾ��ӵ����;
* groupIndex: out, ����������ȫ��Ψһ��index;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngAddGroup( char *account, char *pwd, char *language, 
								char groupName[48], int groupNum,
								unsigned int *groupIndex, char *detail, int detailSize );

/* 
* fn: �޸ķ���;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* groupName: �������, ���޸�;
* groupIndex: ���ȫ��Ψһ��index, �����޸�. �����Դ������ӿڻ��߲�ѯ�豸�б�ӿڻ�ȡ;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngModifyGroup( char *account, char *pwd, char *language, 
								char groupName[48], unsigned int groupIndex, 
								char *detail, int detailSize );
/* 
* fn: ɾ������;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* groupName: �������, ���޸�;
* groupIndex: ���ȫ��Ψһ��index, �����޸�. �����Դ������ӿڻ��߲�ѯ�豸�б�ӿڻ�ȡ;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ��ʷ������Ϣ����, ��������Ҫʹ��HwsdkMngFreetHistoryAlarmMsgResult() �ͷ�;
*/
HWSDK_API int HwsdkMngDeleteGroup( char *account, char *pwd, char *language, 
								char groupName[48], unsigned int groupIndex, 
								char *detail, int detailSize );
/*
* fn: ����������;
* account: �˺ţ���Ϊ�ֻ��š�����;
* pwd: Ҫ�޸ĵ�������;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* groupIndexs: string, �������index, �ð�Ƕ���","����, ����:"50,59,47,48,52,53,54,55,56,49";
* groupNums: string, �������number, �ð�Ƕ���","����, ����:"1,2,3,4,54,5,6,7,8,9,10";
  ע��: groupIndexs �� groupNums ����һһ��Ӧ;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
* return: ��ʷ������Ϣ����, ��������Ҫʹ��HwsdkMngFreetHistoryAlarmMsgResult() �ͷ�;
*/
HWSDK_API int HwsdkMngSortGroup( char *account, char *pwd, char *language, 
									char *groupIndexs, char *groupNums,
									char *detail, int detailSize );
/*
* fn: �ϱ��ֻ���Ϣ;
* 1) user_name����ע���û���;
* 2) user_pws���û�����;
* 3) user_lang���û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* 4) latitudeNs: γ�ȷ���, ����CD_NORTHERN_LATITUDE ��CD_SOUTH_LATITUDE;
* 5) latitude: λ��γ�ȣ�������, ���ַ�����ʾ, ����"25.32456923542";
* 6) longitudeEw: ���ȷ���,����CD_WEST_LONGITUDE ��CD_EAST_LONGITUDE;
* 7) longitude: λ�þ��ȣ�������, ���ַ�����ʾ, ����"25.32456923546";
* 8) alias: �������̶�ʹ�ÿͻ���Ʒ�ƣ���������Եģ���Ϊnobrand���ñ������������ͷ�����ע��(����С������), ����ΪNULL;
* 9) regid: �ͻ��������ͷ������Ǽǵ��˺ţ�Ĭ��ʹ��"C"�ӿͻ�������Ϊʶ�����磺C10002, ����ΪNULL;
* 10) mobile_brand: �ֻ�Ʒ�ƣ��磺SAMSUNG, ����ΪNULL;
* 11) mobile_model: �ֻ��ͺ�, ����ΪNULL;
* 12) os: ����ϵͳ, ����ΪNULL;
* 13) version: ����ϵͳ�汾��, ����ΪNULL;
* 14) cpu: ��������Ϣ����: 1.2GHz 4��, ����ΪNULL;
* 15) memory: �洢������, ����ΪNULL;
* 16) kernel: �ں˰汾, ����ΪNULL;
* 17) baseband: �����汾, ����ΪNULL;
* 18) timezone: ʱ��, ����ΪNULL;
* 19) clientBrand: �ͻ���Ʒ�ƣ���������԰汾���ݶ�nobrand, ����ΪNULL;
* 20) clientVersion: �ͻ���APP ����汾, ����ΪNULL;
* 21) countryCode: ���Ҵ��룬���й���CN, ����ΪNULL;
* 22) countryName: �������ƣ��磺China, ����ΪNULL;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngReportPhoneInfo( char *user, char *pwd, char *language, char latitudeNs, char *latitude, 
								char longitudeEw, char *longitude, char *alias, char *regid, char *mobileBrand, 
								char *mobileModel, char *os, char *version, char *cpu, char *memory, 								
								char *kernel, char *baseband, 	
								float timezone, char *clientBrand, char *clientVersion, char *countryCode, char *countryName, 
								char *detail, int detailSize );
/*
* fn: �ϱ��豸��Ϣ;
* user_name����ע���û���;
* user_pws���û�����;
* user_lang���û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devId: �豸ID;
* latitudeNs: γ�ȷ���, ����CD_NORTHERN_LATITUDE ��CD_SOUTH_LATITUDE;
* latitude: λ��γ�ȣ�������, ���ַ�����ʾ, ����"25.32456923541";
* longitudeEw: ���ȷ���,����CD_WEST_LONGITUDE ��CD_EAST_LONGITUDE;
* longitude: λ�þ��ȣ�������, ���ַ�����ʾ, ����"25.32456923542";
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngReportDeviceInfo( char *user, char *pwd, char *language, char *devId,
								char latitudeNs, char *latitude, char longitudeEw, char *longitude,
								char *detail, int detailSize );

/*
* fn: �û�����;
* user_name����ע���û���;
* user_pws���û�����;
* user_lang���û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* user_email %s: �û�email;
* user_mobile %s: �û��ֻ�����;
* client_brand %s: �̱�, ����"5-smart";
* client_version %s: �ͻ���APP �汾��,����(V1.0.0.1);
* content: �û��ϱ�������;
* detail: out, ������Ϣ
* detailSize: detail ָ��ռ�ĳ���
*/
HWSDK_API int HwsdkMngUserFeekback( char *user, char *pwd, char *language, char *userEmail,
						char *userMobile, char *clientBrand, char *clientVersion,
						char *content, char *detail, int detailSize );								

/*
* fn: ����豸ID �Ƿ�����
* user: �û���
* pwd: ���� 
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д
* devId: �豸ID;
* devCode: out, �豸����;
* detail: out, ������Ϣ;
	ע��: ����ѯ��ID ����, ���ұ������û�ռ��, ��ô�ڱ�������ͬʱ����ռ�ø�ID ���˺���Ϣ,
	��ʽΪ: "ʧ����Ϣ|dev_user=ռ�ø�ID ���˺���Ϣ", ����:
	"The device is used by other user. you can contact your provider. |dev_user=156****5961",
	'|dev_user=' ǰ��Ϊʧ����Ϣ, "|dev_user=" ����Ϊռ�õ��˺���Ϣ(�������);
* detailSize: detail ָ��ռ�ĳ���
*/
int HwsdkMngCheckDevId( char *user, char *pwd, char *language,  
					char *devId, char *devCode, char *detail, int detailSize );

/*
* fn: �����֤���Ƿ����;
* user: �û���;
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* identifying_code����Ҫ������֤��;
* timezone: ʱ��;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
HWSDK_API int HwsdkMngCheckCfgCode( char *user, char *language, char *cfgCode, 
				  					float timezone, char *detail, int detailSize );

/*
* fn: ��ȡ�豸�����汾��Ϣ;
* user: �˺�;
* pwd: ����; 
* language: �û����Դ��룬��: zh-cn��en-us�ȣ����չ��ʱ�׼������д;
* devCode: �豸����, ������������豸�б�ṹ���devCode;
* pVersionParam: out, �������������Ӧ��һЩ������Ϣ;
* pRomInfo: out, �����������Ϣ;
* romInfoSize: pRomInfo ָ��ռ�Ĵ�С, ����APP ��8K �Ŀռ����;
* detail: out, ������Ϣ;
* detailSize: detail ָ��ռ�ĳ���;
*/
int HwsdkMngGedDevRomInfo( char *user, char *pwd, char *language, char *devCode, 
					   		HWSDK_DEV_VERSION_PARAM *pVersionParam, char *pRomInfo, 
					   		int romInfoSize, char *detail, int detailSize );

/*
* fn: ����ʵʱ��;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* chnType; 0, ������; 1, ������;
* context: out( out ��ʾ�ò���������,��ͬ ), �������ɹ�, ���ɸò�������ȡ����������,
			�ú�����������, ��Ƶ�����Իص��ķ�ʽ����APP;
* return: ==0, ��ʾ����ɹ�; ����, ʧ��. ����ʧ��, ���ӳ�20 �������µ��ñ�����;
*/
HWSDK_API int HwsdkDevRealTimeStreamStart( unsigned int devIndex, int channel, unsigned char chnType, unsigned long *context );

/*
* fn: ֹͣĳ��ͨ����ʵʱ��;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* chnType; 0, ������; 1, ������;
* context: �� HwsdkDevRealTimeStreamStart() �õ��� context;
* ע��: ���Ҫʵ��ĳ��ͨ���Ķ�������, �����ʹ�ñ��ӿ��ͷ� HwsdkRealTimeStreamStart()
        �����ɹ���ռ�õ���Դ;
*/
HWSDK_API int HwsdkDevRealTimeStreamStop( unsigned int devIndex, int channel, unsigned char chnType, 
													unsigned long *context );

/*
* fn: ������Ƶ��ָ��;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ������豸�Ǹ�ͨ������;
 */
HWSDK_API int HwsdkDevAudioStart( unsigned int devIndex, int channel );

/*
* fn: ֹͣ��Ƶ��ָ��;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ������豸�Ǹ�ͨ������;
*/
HWSDK_API int HwsdkDevAudioStop( unsigned int devIndex, int channel );

/*
* fn: ����ĳ��ͨ����¼���ļ�;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* date[20]: ¼������,����������, ʱ���ʽ"2016-03-28";
* type: ¼������,����֧�������������¼�¼��;
* searchNum: ������, 1������������,2������������;
* searchChnType: �����طŵ�������,0����,1����;
* context: out, ������, �ط�ʱ, ���Ը�����������ʶ�ص�¼���APP;
* ע��: ����¼��Ľ���Իص��ķ�ʽ����, �ο� HW_SEARCH_RECORD_RES_CB;
*/
HWSDK_API int HwsdkDevSearchRecord( unsigned int devIndex, int channel, char date[20],
                                    unsigned char type, unsigned char searchNum, unsigned char searchChnType, unsigned long *context );

/*
* fn: �ͷ� HwsdkDevSearchRecord() ��ȡ������Դ;
	1. �����豸�Ҳ��ٹ��ĸ�����Ļط�������;
	2. �ͷŸ�����طŵı�����Դ;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* chnType: �طŵ�������,0 ����,1 ����,ͬ�طſ��������chnType����һ��;
*/
HWSDK_API int HwsdkDevReleaseSearchRecord( unsigned int devIndex, int channel, unsigned char chnType );

/*
* fn: �طſ���;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* cmd: �ط�����μ� REPLAY_CMD_EN;
* param: �طŲ���:
    1. ���cmd ��RC_SPEED, ��˲�����ʾ�ٶȣ��μ�REPLAY_CMD_EN;
    2. ���������RC_FILE, �˲�����ʾ�ӵ�ǰʱ��εĵڼ����ӽ��лط�, 
       ȡֵ��Χ�� REPLAY_START_CB �ص��Ĳ���howManyFile���ص�ֵ���;
    3. ���cmd ������ֵ���ò�����Ч;
* dt: ʱ�����: 
    1. ���cmd ��RC_FILE, ��ʽ"2016-03-30 18:30:00",��cmd ��RC_FILE ʱ, ��ʾ�ѻط�ʱ��;
        �л�����ʱ��Ŀǰ��ȷ������, Ҳ�������һ��ð�ź��������Ϊ00;
    2. ���cmd ������ֵ���ò�����Ч;
* chnType: �ط������ȣ�0���壬 1����;
* playbackCnt: ÿ����һ�λطŻ��л��ط��ļ���1, ���ڷ�ֹ�л��ط��ļ�ʱ�յ��ϴλطŵ�����,��Χ[1,127];
* return: �ú�����������, �طŵ������Իص��ķ�ʽ����APP, �ص�����С�����ݣ���Ҫ�ڻص������������Ƶ��;
*/
HWSDK_API int HwsdkDevPlaybackCtlChntype( unsigned int devIndex, int channel, int cmd, int param, char dt[20], char chnType, unsigned char playbackCnt );

/*
* fn: �ͻ������豸�˷���������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: һ���ֻ��1 ��mic, ��0 ����;
* pAudioData: ���ֻ����ߵ��Բɼ���������Ƶ����, ����;
* len: ��Ƶ�������ݳ���;
* encType: ��������: 100, g711a; 101, g711u, Ĭ��100;
* sampleRate: ������: 0, 8000; 1, 16000, Ĭ��0;
* bitWidth: λ��: 0, 8bit; 1, 16bit, Ĭ��1, Ŀǰ��˼��оƬֻ֧��16bit;
* chnMod: ͨ��ģʽ: 0, ��ͨ��(Mone); 1, ������, Ĭ��0;
 */
HWSDK_API int HwsdkDevTalkBackCuToDu( unsigned int devIndex, int channel, char *pAudioData, int len,
										unsigned char encType, unsigned char sampleRate, 
										unsigned char bitWidth, unsigned char chnMod );

/*
* fn: ��ȡ�豸״̬;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* model[32]: out, �豸�ͺ�;
* id[52]: out, �֧��48 ���ֽڵĵ�ID;
* devType[16]:out, �豸���� "nvr/ipc/dvr";
* version[16]: out, �汾��,��"v1.23";
* vch: out, ��Ƶͨ����;
* ach: out, ��Ƶͨ����;
* kin: out, ���뿪��������;
* kout: out, �������������;
* vencStandard[16]: out, ��ǰ��Ƶ�����׼, ��"jpeg/fmpeg4/h.264/h.265";
* aencStardard[16]: out, ��ǰ��Ƶ�����׼, ��"AAC/g711a/g711u/g726/mp3";
* allResolution[84]: out, �豸��֧�ֵ����зֱ���, �ð�Ƿֺ����ֿ���: "1920X1080;1080X720;640X360;704X576";
* diskNum: out, �ܹ��ж��ٸ�����, ���֧��8 ��;
* diskAttr[8]: out, ÿ��Ӳ�̵���Ϣ����;
* pNetInfo:  out, ������Ϣ; 
*/
HWSDK_API int HwsdkDevStatus( unsigned int devIndex, char model[32], char id[52], char devType[16], char version[16],
                                 unsigned char *vch, unsigned char *ach, unsigned char *kin, unsigned char *kout,
                                 char vencStandard[16], char aencStardard[16], char allResolution[84], unsigned char *diskNum,
                                 HWSDK_DISK_ATTR_T *diskattr, HWSDK_NET_INFO_T *pNetInfo );

/*
* fn: ��ȡ�豸�������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* pMultiConf: out,�豸�����Ľṹָ��;
*/
HWSDK_API int HwsdkGetMultiConf( unsigned int devIndex, int channel, HWSDK_GET_MULTI_CONF_T *pMultiConf );

/*
* fn: ��̨����, ͨ�����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* type: �������ͣ�ȡֵ��PTZ_CTRL_E;
* motion: ��ʱ����;
* param: ���Ʋ���, ����Ϊ:
			1. �ƶ��ٶȷ�Χ��speed [0,63];
			2. Ѳ���켣��Χ��Track [1-16]; 
			3. Ԥ�õ㷶Χ: SelprePoint[1-255].
            4. Ԥ��λ��[0, 55];
*/
HWSDK_API int HwsdkDevPtzCtl( unsigned int devIndex, int channel, unsigned char type,
                           			unsigned char motion, unsigned char param );

/*
* fn: ǿ�Ʋ���I֡, ͨ�����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
*/
HWSDK_API int HwsdkDevForceIframe( unsigned int devIndex, int channel );

/*
* fn: ����Ч������( ������----�����ԣ�����Ӧ���� ), ͨ�����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* level: �ȼ�[1,10];
   1-5  ��Ӧ����������2048kbps��1536kbps��1024kbps��768kbps��512kbps;
   6-10 ��Ӧ��������  512kbps��384kbps��256kbps��128kbps��80kbps;
*/
HWSDK_API int HwsdkDevSelfAdaption( unsigned int devIndex, int channel, unsigned char level );

/*
* fn: ��ȡ�豸WIFI ����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* user[33]: out, �û���;
* passwd[65]: out, ����;
*/
HWSDK_API int HwsdkDevGetWifiAttr( unsigned int devIndex, char user[33], char passwd[65] );

/*
* fn: �豸WIFI ��������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* user[33]: �û���;
* passwd[65]: ����;
*/
HWSDK_API int HwsdkDevSetWifiAttr( unsigned int devIndex, char user[33], char passwd[65] );

/*
* fn: ��ȡ�ƶ��������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* armFlag: out, 0, ����(�豸�������ƶ����); 1, ����(�豸�����ƶ����);
* sensitiveLevel: out, ������, [1,5], ֵԽ��������Խ��;
*/
HWSDK_API int HwsdkDevGetMdConf( unsigned int devIndex, int channel, unsigned char *armFlag, unsigned char *sensitiveLevel );

/*
* fn: �����ƶ��������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* armFlag: 0, ����(�豸�������ƶ����); 1, ����(�豸�����ƶ����);
* sensitiveLevel: ������, [1,5], ֵԽ��������Խ��;
*/
HWSDK_API int HwsdkDevSetMdConf( unsigned int devIndex, int channel, unsigned char armFlag, unsigned char sensitiveLevel );

/*
* fn: ����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
*/
HWSDK_API int HwsdkDevUpdate( unsigned int devIndex );

/*
* fn: �ָ�Ĭ�ϲ���;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* defaultNetwork: 0, ���ûָ��������, Ҳ����˵�ָ�������������������������; ��Ҫ�ָ��������;
*/
HWSDK_API int HwsdkDevCtlDefaultParam( unsigned int devIndex, unsigned char defaultNetwork );

/*
* fn: ����;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
*/
HWSDK_API int HwsdkDevReboot( unsigned int devIndex );

/*
* fn: ��ȡһ��ͼƬ;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* picType: Ҫ��ȡ��ͼƬ����, ȡֵ��Χ�μ�:PIC_TYPE_EN;
* eventType: 
	1) ��PIC_TYPE_REALTIME == picType, ��ʾ��ʾ��ȡ�豸��ǰ��ȡ��һ��ͼƬ, eventType ��Ч;
	2) ��PIC_TYPE_ALARM = picType, Ϊ��������, ��ӦALARM_MSG_T �����AlmType ����;
	3) PIC_TYPE_PRESET == picType, ��ʾ��ʾ��ȡ��ȡĳ��Ԥ��λ��ͼƬ, eventType ��Ч;
* chn: 
	1) ��PIC_TYPE_REALTIME == picType, ��ʾ��Ƶ��ͨ����;
	2) ��PIC_TYPE_ALARM = picType, ��ӦALARM_MSG_T �����chn ����;
	3) PIC_TYPE_PRESET == picType, ��ʾԤ��λ���ڵ���Ƶͨ����;
* context: ������,
	1) ��PIC_TYPE_REALTIME == picType, �ò���û����;
	2) ��PIC_TYPE_ALARM = picType,��ӦALARM_MSG_T �����picture ����;
	3) PIC_TYPE_PRESET == picType, ��ʾԤ��λ��[1,8], ���ַ�����ʾ, ����:"1"��"2"��"3";
* ע��: ͼƬ���Իص��ķ�ʽ����;
*/
HWSDK_API int HwsdkDevGetPic( unsigned int devIndex, unsigned int picType, unsigned int eventType, int chn, char context[64] );

/*
 * fn: һ�λ�ȡ����ͼƬ
 * devIndex: �豸��ȫ��Ψһ����, ��web ����������;
 * picParms: ��������
 * picNum: picParms ����Ĵ�С
*/
HWSDK_API int HwsdkDevGetBulkPic( unsigned int devIndex, HWSDK_GET_PIC_PARAM_T *picParms, int picNum );

/*  
* fn: smartLink����IPC;
* devId: �豸ID;
* localAddr: �ֻ���ǰwifi ��IP ��ַ, ��ʽΪ"192.168.111.222";
* passwdBuff: �ֻ��������ӵ�wifi�����룬���ó���64�ֽ�;
*/
HWSDK_API int HwsdkDevSeekWifi( char *devId, char *localAddr,char *ssidBuff,  char *passwdBuff );

/*
* fn: ֹͣsmartlink����
*/
HWSDK_API int HwsdkDevStopSeekWifi();

/*  
* fn: ����IPC�˵�ʱ��, �ýӿ���HwsdkDevSeekWifi() �Ļص�����(���� pCallback)����smart link �Ľ����ʹ��,
	  ���smart link �ɹ�, ����ñ��������豸������ʱ��, ����, ���õ��ñ�����;
* timeZone: �ֻ���ǰ����ʱ��;
* timeZoneMin: ʱ��С����Ӧ�ķ�����,��:ʱ��Ϊ8.5,timeZone=8,timeZoneMin=30;
* utcDate: utcʱ�䣬��ʽΪ "2016-10-01 22:00:11";
* devIP: �豸��ip��ַ, ��ֵ��HwsdkSeekWifi() �Ļص�����(���� pCallback)�з���;
* ����ֵ: ���ý�����غ���, �ɹ�Ϊ0��ʧ��Ϊ-1;
*/
HWSDK_API int HwsdkDevSynDate(int timeZone, unsigned char timeZoneMin, char *utcDate, char *devIP);

/*
fn : Ӧ�ò�ͨ���ýӿڸ�sdk �����¼�
* event: �μ� COM_EVENT_EN;
* param1: ����event �Ĳ�ͬ���в�ͬ������;
* param2: ����event �Ĳ�ͬ���в�ͬ������;
	event��param1��param2 �������:
   	event  						| param1                |  param2
    1(APP�����̨����)    		| ������       			|  ������  
    2(APP�Ӻ�̨���߷���)		| ������				|  ������
    3(APP������״̬�����仯)	| ��ǰ��������IP ��ַ	|  ������

* ʹ��˵��: 
	(1) ��event == 3 ʱ, param1 Ϊ�ֻ���ǰ��������IP ��ַ, �����Ǳ����׽��ֵ�unsigned int ��ʽ,
	����: �����ǰʹ��IP �� "192.168.99.91", ��param1 Ϊ0xC0A8635B;	
*/
int HwsdkEventFromAppToSdk( unsigned int event, unsigned int param1, unsigned int param2 );

/*
* fn: ��ȡ¼������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* isOnlyAlarmRec: out, �Ƿ�ֻ¼�Ʊ���¼��;
* isOnlyAlarmRec: out, ¼��ʱ�Ƿ�¼����Ƶ;
*/
int HwsdkDevGetRecordConf( unsigned int devIndex, unsigned char *isOnlyAlarmRec, unsigned char *isAudioRec );

/*
* fn: ����¼������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* isOnlyAlarmRec: �Ƿ�ֻ¼�Ʊ���¼��;
* isAudioRec: ¼��ʱ�Ƿ�¼����Ƶ;
*/
HWSDK_API int HwsdkDevSetRecordConf( unsigned int devIndex, unsigned char isOnlyAlarmRec, unsigned char isAudioRec );

/*
* fn: ��ʽ������;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
*/
HWSDK_API int HwsdkDevFormatDisk( unsigned int devIndex );

/*
* fn: ��ȡ�豸��wifi�б�
*     �����б��ڻص����� pGetWifilistFunc ��
*/
HWSDK_API int HwsdkDevGetWifilist( unsigned int devIndex );

/*
* fn: ���û��淭ת
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* rotate: 0, ����ת; 1, 180�ȷ�ת; ... �� HW_ROTATE_EN;
*/
HWSDK_API int HwsdkDevSetRotate( unsigned int devIndex, int channel, unsigned char rotate );

/*
* fn: ���õ�ԴƵ��
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* pwrFreq: �豸��ԴƵ��, һ����˵ֻ��50Hz ��60Hz������ѡ��;
*/
HWSDK_API int HwsdkDevSetPwrFreq( unsigned int devIndex, unsigned short pwrFreq );

/*
* fn: �豸��¼,��Ҫ���ڸ��ݱ�����Ϣ���ӵ��豸,��ȡ����ͼƬ;
* devIndex: �豸�Լ���index, ȫ��Ψһ������;
* ip: �豸��IP;
* p2pIp: P2P ��������IP ��ַ;
* p2pPort: P2P ��������IP �˿�;
* tssIp: ת��������IP ��ַ;
* tssPort: ת���������˿�;
* return: 0,��������;����,����;
*/
HWSDK_API int HwsdkOpenDev( unsigned int devIndex, char *ip, char *p2pIp, unsigned short p2pPort,
    char *tssIp, unsigned short tssPort );

/*
* fn: �����豸ID�鲥�����豸��,�豸��ƥ��ɹ��󷵻�,�û���ֱ������豸;
*     ��Ҫ��ʹ�ó�����:
*        �豸��ʹ���������ӵķ�ʽ���ӵ����磨û�л�δʹ��wifi,Ŀ�ĺ�smarLink��ͬ��;
*     ע�⣺�ӿ��������ʱ����3s���豣֤�豸�˺Ϳͻ�����ͬһ����,��������޷������豸
* devId: �豸ID;
* tz:    �ͻ���ʱ��
* tzMin: ʱ��С����Ӧ�ķ�����,��:ʱ��Ϊ8.5,tz=8,tzMin=30;
* time:  �ͻ���ʱ��
* retrun: 0,�ɹ�;-1,δ֪����;����,����HW_CERROR_TYPE_EN;
*/
HWSDK_API int HwsdkMulticastFindDev( char *devId, int tz, unsigned char tzMin, unsigned int time );

/*
* fn: ���ö�̬����;
* ����: ����ͻ���ÿ3S��ʧ����[7,10]֡ʱ���󽵵�����,��ʱ�������ж���ͻ��˲���ͬһ���豸ͨ������Ƶ;
*      ��һ�������ʵ�λ,��֮����2�ּ������ʵ�λ�����10������Ϊ5��,7������Ϊ4����,�������ʺ�״̬�����ȶ�һ��ʱ��,�޸�״̬��Ϊ�ȶ�;
*      �ȶ�״̬ά�ֽϳ�ʱ�䣨20S���ϣ���,�����������,ÿ�����һ��;ѭ���������;
*/
HWSDK_API void HwsdkStartVarBitrate();

/*
* fn: �رն�̬����;
*/
HWSDK_API void HwsdkStopVarBitrate();

/*
* fn: ��ȡѸ���豸ģʽ����,�����5S;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* xmInsMode: out, ����ֵ�� HWSDK_XM_INS_MODE_E;
* xmFisheyeMode: out, ����ģʽ, ����ֵ�� HWSDK_XM_FISHEYE_MODE_E;
*/
HWSDK_API int HwsdkDevGetXMSetting( unsigned int devIndex, int channel, unsigned char *xmInsMode, unsigned char *xmFisheyeMode );

/*
* fn: ����Ѹ���豸ģʽ����,�����3S;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
* channel: ͨ����,[0,�豸֧�ֵ�ͨ����);
* xmInsMode: ����ֵ�� HWSDK_XM_INS_MODE_E;
* xmFisheyeMode: ����ģʽ, ����ֵ�� HWSDK_XM_FISHEYE_MODE_E;
*/
HWSDK_API int HwsdkDevSetXMSetting( unsigned int devIndex, int channel, unsigned char xmInsMode, unsigned char xmFisheyeMode );

/*
* fn: ���ɴ�����������������,wave ��ʽ;
* wifiSsid: wifi ����;
* wifiPwd: wifi ����;
* localAddr: �ֻ���ǰwifi ��IP ��ַ,  ��ʽΪ"192.168.111.222";
* pBuf: out, ������ɺ��wave ��������;
* bufSize: pBuf ��ָ��ռ�Ĵ�С����������ڴ�2M;
* resultSize: out, ����pBuf �����ݵĳ���;
* platform:  ƽ̨��ѡ��1  ��˼   2 ���� 

* pBufSsid: out, ������ɺ��wave ����Ssid����,��������ڴ�1M;
* bufSizeSsid: pBuf ��ָ��ռ��Ssid��С;
* resultSizeSsid: out, ����pBuf �����ݵ�Ssid����;

* �ر�˵��: ���������ķ�ʽ����豸, ��Ҫͬʱʹ�ñ��ӿں� HwsdkMulticastFindDev �ӿ�;
*/
HWSDK_API int HwsdkGenWtoswSoundData( char *wifiSsid, char *wifiPwd, char *localAddr, char *pBuf, int bufSize, int *resultSize ,int platform,char *pBufSsid, int bufSizeSsid, int *resultSizeSsid);

/*
* fn: ��ȡNVR�豸��ͨ��״̬��Ϣ;
* devIndex: �豸��ȫ��Ψһ����, ��web ����������;
*/
HWSDK_API int HwsdkDevGetNVRChannelState( unsigned int devIndex );

/*
* fn: �����豸����;
* devIndex: �豸��ȫ��Ψһ����,��web ����������;
* volume: ����,��Χ[0-100];
* slaveVolume: �ӻ�����������[0-100];
* micVol: ��˷�����[0-100];
* slaveMicVol: �ӻ���˷�����[0-100];
*/
HWSDK_API int HwsdkDevSetDevVolume( unsigned int devIndex, unsigned char volume, unsigned char slaveVolume, unsigned char micVol, unsigned char slaveMicVol );

/*
* fn: ��������;
* devIndex: �豸Ψһ��ʶID;
* param: ���Ų���;
*/
HWSDK_API int HwsdkDevPlayRing( unsigned int devIndex, unsigned char param );

/*
* fn: ֪ͨ�豸��������;
* devIndex: �豸Ψһ��ʶID;
*/
HWSDK_API int HwsdkDevUpdateRing( unsigned int devIndex );

/*
* fn: ��ȡ�豸����,���ͨ���¼�(CE_DEV_ELECTRICITY)�ص�����,�豸��Ҳ�������ϱ��豸����;
* devIndex: �豸Ψһ��ʶID;
*/
HWSDK_API int HwsdkDevGetElectricity( unsigned int devIndex );

/*
* fn: ����PIR,����ʽ����̽�⹦��;
* devIndex: �豸Ψһ��ʶID;
* pirSnap: ��Ӧ���� 0,�ر� 1,��;
*/
HWSDK_API int HwsdkDevSetPIR( unsigned int devIndex, unsigned char pirSnap );

/*
* fn: ���������豸;
* devIndex: �豸Ψһ��ʶID;
* retrun: 0,����ɹ�;��0Ϊ�쳣����;
*/
HWSDK_API int HwsdkDevWakeupDoorbell(unsigned int devIndex);

/*
* fn: ����ĳ��ģ�⿪������״̬;
* devIndex: �豸��index;
* chnKout: �豸��kout ͨ��, ȡֵ��Χ[0,8), Ŀǰ���֧��8 ��ͨ�� ;
* state: 0, ��; 1, ��;
*/
HWSDK_API int HwsdkDevSetSwitchKout( unsigned int devIndex, unsigned char chnKout, char state );

/*
* fn: ��ȡ�豸����ģ�⿪������״̬, Ŀǰ���֧��8, �豸ʵ���ж��ٸ�, ��Ҫ����
      �豸�б�ṹ��WEBS_DEV_INFO_T ��koutNum ��Ա;
* devIndex: �豸��index;
* chnKout: �豸��kout ͨ��, ȡֵ��Χ[0,8), Ŀǰ���֧��8 ��ͨ�� ;
* state: 0, ��; 1, ��;
*/
HWSDK_API int HwsdkDevGetSwitchKout( unsigned int devIndex, char koutState[8] );

/*
* fn: ͸������ӿ�;
* devIndex: �豸��index;
* data: Ҫ͸��������;
* len: ͸������ĳ���, ����<= 1168;
* ˵��: Ut = unvarnished transmission;
*/
HWSDK_API int HwsdkDevUtFromClientToDev( uint devIndex, char *data, int len );

#endif // __HWSDK_H__

