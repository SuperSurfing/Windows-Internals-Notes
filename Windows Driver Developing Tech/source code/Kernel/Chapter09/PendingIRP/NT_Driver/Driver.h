/************************************************************************
* �ļ�����:Driver.h                                                 
* ��    ��:�ŷ�
* �������:2007-11-1
*************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include <NTDDK.h>
#ifdef __cplusplus
}
#endif 

#define PAGEDCODE code_seg("PAGE")
#define LOCKEDCODE code_seg()
#define INITCODE code_seg("INIT")

#define PAGEDDATA data_seg("PAGE")
#define LOCKEDDATA data_seg()
#define INITDATA data_seg("INIT")

#define arraysize(p) (sizeof(p)/sizeof((p)[0]))

typedef struct _DEVICE_EXTENSION {
	PDEVICE_OBJECT pDevice;
	UNICODE_STRING ustrDeviceName;	//�豸����
	UNICODE_STRING ustrSymLinkName;	//����������
	PLIST_ENTRY pIRPLinkListHead;
} DEVICE_EXTENSION, *PDEVICE_EXTENSION;

typedef struct _MY_IRP_ENTRY
{
	PIRP pIRP;
	LIST_ENTRY ListEntry;
} MY_IRP_ENTRY, *PMY_IRP_ENTRY;

// ��������

NTSTATUS CreateDevice (IN PDRIVER_OBJECT pDriverObject);
VOID HelloDDKUnload (IN PDRIVER_OBJECT pDriverObject);
NTSTATUS HelloDDKDispatchRoutin(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp);
NTSTATUS HelloDDKRead(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp);
NTSTATUS HelloDDKCleanUp(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp);