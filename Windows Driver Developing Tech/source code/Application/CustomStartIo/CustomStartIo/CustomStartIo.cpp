﻿// CustomStartIo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <process.h>

UINT WINAPI Thread(LPVOID context)
{
	printf("Enter Thread\n");
	OVERLAPPED overlap = { 0 };
	overlap.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	UCHAR buffer[10];
	ULONG ulRead;

	BOOL bRead = ReadFile(*(PHANDLE)context, buffer, 10, &ulRead, &overlap);
	printf("%d\n", ulRead);
	WaitForSingleObject(overlap.hEvent, INFINITE);
	return 0;
}

int main()
{
	HANDLE hDevice =
		CreateFile(L"\\\\.\\HelloDDK",
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,//此处设置FILE_FLAG_OVERLAPPED
			NULL);

	if (hDevice == INVALID_HANDLE_VALUE)
	{
		printf("Open Device failed!");
		return 1;
	}

	HANDLE hThread[2];
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, Thread, &hDevice, 0, NULL);
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, Thread, &hDevice, 0, NULL);

	//主线程等待两个子线程结束
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

	//创建IRP_MJ_CLEANUP IRP
	CloseHandle(hDevice);

	return 0;
}

