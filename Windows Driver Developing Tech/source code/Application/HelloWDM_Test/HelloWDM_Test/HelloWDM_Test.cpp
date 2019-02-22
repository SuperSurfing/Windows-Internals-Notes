// HelloWDM_Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <winioctl.h>

#include "function.h"

#include "guid.h"

int main()
{
	HANDLE hDevice = GetDeviceViaInterface((LPGUID)&MY_WDM_DEVICE, 0);

	if (hDevice == INVALID_HANDLE_VALUE)
	{
		printf("Failed to obtain file handle to device: "
			"%s with Win32 error code: %d\n",
			"MyWDMDevice", GetLastError());
		return 1;
	}

	CloseHandle(hDevice);
	return 0;
}