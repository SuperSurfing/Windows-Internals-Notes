### Abstract
&emsp;&emsp;������Ҫ���� Windows service �ı��ģʽ�� SCM ����ع��ܡ�



### Content

- [����֪ʶ](#����֪ʶ)
  - [What is Windows Service](#what_is_windows_service)
  - [SCM](#scm)
  - [Service Programs](#service_programs)
  - [Event Trace for Windows](#etw)
- [�ؼ�����](#�ؼ�����)
  - [Service Entry Point](#service_entry_point)
  - [ServiceMain](#servicemain)
  - [Service Control Handler](#service_control_handler)
- [Simple Windows Service in C++](#simple_service)
- [Service���������߼�](#service���������߼�)


### ����֪ʶ

#### What_is_Windows_Service

���� Windows Service �Ķ��壬���Բο� [Wiki: Windows Service](https://en.wikipedia.org/wiki/Windows_service) ,�ܽ����£�  
1. Windows Services ���� Unix Daemon ���ػ����̣�������һ�ֳ�פ�ڴ��**��̨����**��  
2. Windows Services ������ר���˻��������У����������û���¼ǰ���С�  
3. Windows Services �ֱ������������û��˻���System, Network and Local �����ǵ�Ȩ�޸�����ͬ��  
4. Windows Services ��Ҫ���� SCM �Ľӿڹ淶��Э�顣  
5. SCM ������� Windows Services���������鿴״̬��������ֹͣ�ȡ�  

�ο� [MSDN - About Services](https://docs.microsoft.com/en-us/windows/desktop/services/about-services) ��֪��Windows Services �������¼�����Ҫ֪ʶ�㣺  
- Service Control Manager
- Service program
- Service configuration program
- Service control program


#### SCM

SCM - [Service Control Manager](https://en.wikipedia.org/wiki/Service_Control_Manager)����һ�������ϵͳ���̣�������� Windows Services ��  

> The SCM executable, Services.exe, runs as a Windows console program and is launched by the Wininit process early during the system startup. Its main function, SvcCtrlMain(), launches all the services configured for automatic startup.

SCM ͨ���������ע���������ʼ�����ġ�internal database��

> HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services, which contains the actual database of services and device drivers and is read into SCM's internal database.

���仰˵��HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services �а����� Windows Services �ĸ�����Ϣ��

[��Windows��������������⡷](https://blog.csdn.net/Sagittarius_Warrior/article/details/87193389) CH3 �е� LoadNTDriver.exe ʾ��������ʾ�����ͨ�� SCM ���غ�ж��һ�� Windows Service �����ĺ��ĺ����� [CreateService()](https://docs.microsoft.com/en-us/windows/desktop/services/installing-a-service) ��  


##### services.msc

ͨ�� **services.msc** ������Դ� SCM �� console ��


���� SCM ����ϸ�����ϣ����Բο� [MSDN - SCM](https://docs.microsoft.com/en-us/windows/desktop/services/service-control-manager)������Ҳ�ṩ��һ��������ʾ������ - [The Complete Service Sample](https://docs.microsoft.com/en-us/windows/desktop/services/the-complete-service-sample)��


##### Database

�ο� [MSDN - About Services](https://docs.microsoft.com/en-us/windows/desktop/services/about-services) ��֪��SCM ��Ҫ��ͨ�����ݿ������� services����

> The service control manager (SCM) maintains a database of installed services and driver services, and provides a unified and secure means of controlling them. The database includes information on how each service or driver service should be started. It also enables system administrators to customize security requirements for each service and thereby control access to the service.


#### Service_Programs

�ο� [MSDN - Service Programs](https://docs.microsoft.com/en-us/windows/desktop/services/service-programs)��

Ϊ�˷��� SCM �Ľӿ�Ҫ��Windows Services�������������������֣�  
- Service Entry Point
- Service ServiceMain Function
- Service Control Handler Function


#### ETW

ͨ�� CMD ���� **eventvwr.msc** ���Բ鿴 Windows Services ����ļ��ء�ж�ء�������ֹͣ�ͱ����ȵȼ�¼��



### �ؼ�����

�ӽ��̴����ĽǶ�������Services ��������Ҫ�������¼������裺  
1. CreateService/OpenService �� SCM ע�� service ���õ����  
2. SCM �� Service Program ����������Ҫ���������ں˶���
3. ����ϵͳ��⵽�µĽ����ں˶���󣬻�Ϊ�����䡰�����ַ�ռ䡱������Image�ļ���module�ļ������ص��õ�ַ�ռ�
4. ����ϵͳ�������̣߳�ִ�� Service Program �� main ����
5. main ����ִ���� StartServiceCtrlDispatcher ���� SCM ע�� ServiceMain ����ָ�룩���˳���  
6. StartService �� service controller ��������service controller ��ǰ�洴���Ľ��̵�ַ�ռ��д������̣߳����� ServiceMain  
7. ServiceMain �ٴ����̣߳�ִ�� service tasks ��  
8. ServiceMain ��ֱ��ִ��  service tasks �����Ǹ����� controller ���������� service �� start/stop ��  
9. ServiceMain ���� SCM ע�� Service Control Handler �ص�����������Ҫֹͣʱ��SCM ���������ص�������  
10. Service Control Handler ������ STOP �¼���ServiceMain �յ��¼��󼴿ɼ���ִ�С�  

#### Service_Entry_Point

> Services are generally written as console applications. The entry point of a console application is its main function. The main function receives arguments from the ImagePath value from the registry key for the service.

��Ҫע����ǣ�services ������ console �����������ں�̨���������ڡ���Ȼ��������ں���ֻ���� main() ������  

##### main

Services �����ִ������ SCM �� main() ����֮����һ���л��Ķ��������������ǣ�  
1. SCM ���� service ���򣬽��� main() ����
2. main() ִ��һЩ��ʼ������
3. main() ���� StartServiceCtrlDispatcher() ������������Ȩ��ת���� SCM ��

> When the SCM starts a service program, it waits for it to call the StartServiceCtrlDispatcher function. 

##### StartServiceCtrlDispatcher

 StartServiceCtrlDispatcher() �����ܹ����� SCM ���ڸ� service ��һЩ��Ϣ��  

> The StartServiceCtrlDispatcher function takes a **SERVICE_TABLE_ENTRY** structure for each service contained in the process. Each structure specifies the service name and the entry point for the service.

##### SERVICE_TABLE_ENTRY

SERVICE_TABLE_ENTRY ��һ���ַ����뺯��ָ���ӳ���������һ�����̿���ע���� ServiceMain ������

��ϵǰ������ݣ���ʵ�ϣ�main() �봫ͳ����� win32 console ����� main() ��ȫ��ͬ���������ǽ���һЩ��������ʼ������Ȼ����� SCM ��������ڵ㺯����ServiceMain�����ġ�

##### service type

main() �����ĳ�ʼ�������� service type ��أ��������� type:  
- SERVICE_WIN32_OWN_PROCESS 
- SERVICE_WIN32_SHARE_PROCESS 

ǰ���������� StartServiceCtrlDispatcher ������ service ��������ִ�г�ʼ����������Ҫ�ڵ� StartServiceCtrlDispatcher ����һЩ��������ʼ������Ҳ���Կ����߳�ִ�������������ʼ������  


##### ʾ��

�ܽ���˵��service �� main �����ܼ򵥣���Ҫ���� StartServiceCtrlDispatcher ���������롰Service Name���͡�ServiceMain����

```
void __cdecl _tmain(int argc, TCHAR *argv[]) 
{ 
    // If command-line parameter is "install", install the service. 
    // Otherwise, the service is probably being started by the SCM.

    if( lstrcmpi( argv[1], TEXT("install")) == 0 )
    {
        SvcInstall();
        return;
    }

    // TO_DO: Add any additional services for the process to this table.
    SERVICE_TABLE_ENTRY DispatchTable[] = 
    { 
        { SVCNAME, (LPSERVICE_MAIN_FUNCTION) SvcMain }, 
        { NULL, NULL } 
    }; 
 
    // This call returns when the service has stopped. 
    // The process should simply terminate when the call returns.

    if (!StartServiceCtrlDispatcher( DispatchTable )) 
    { 
        SvcReportEvent(TEXT("StartServiceCtrlDispatcher")); 
    } 
} 
```




#### ServiceMain

ServiceMain() ���� service ���������Ĺ��ܿ�ʼִ�еĵط����������ֿ�������ָ��������Ҫ�� SERVICE_TABLE_ENTRY ���漴�ɡ�  

> When a service control program requests that a new service run, the Service Control Manager (SCM) starts the service and sends a start request to the control dispatcher. The control dispatcher creates a new thread to execute the ServiceMain function for the service. 

ServiceMain �� main ����ͬһ���߳��С����ǣ�����Ӧ����ͬһ�����������Ļ����У��Ҳ£���

ServiceMain ����Ҫ�������£�  

1. ��ʼ�����е�ȫ�ֱ������ο���Windows���ı�̡�CH4�����̡���һ���Windows�����ȫ�ֱ�����ʼ������ mainCRTStartup �����С�    
2. ע��ص�������
> Call the **RegisterServiceCtrlHandler** function immediately to register a Handler function to handle control requests for the service. The return value of RegisterServiceCtrlHandler is a service status handle that will be used in calls to notify the SCM of the service status.  
3. ִ��������ʼ�������� 
4. ���� STOP �¼���  
5. �� service ״̬��Ϊ ��SERVICE_RUNNING�������� service controller �� service ��׼��������  
6. ���̣߳�ִ�С�service tasks��  
7. �ȴ� STOP �¼���  
8. ���� STOP ״̬��ִ�����������˳���


#### Service_Control_Handler

�ο� [MSDN - Service Control Handler](https://docs.microsoft.com/en-us/windows/desktop/services/service-control-handler-function) ��

> Each service has a control handler, the Handler function, that is invoked by the control dispatcher when the service process receives a control request from a service control program. Therefore, this function executes in the context of the control dispatcher. 

Service Control Handler ��һ���ص����������л�ά��һ�� switch - cases��ִ�� Controller dispatcher ��һЩת��������һЩ���� service �� STOP �� PENDING ��صĲ�����

### Simple_Service

[Simple Windows Service in C++](https://www.codeproject.com/Articles/499465/Simple-Windows-Service-in-Cplusplus) ��һ���ǳ�С�ɵ��ǹ��ܼ����� Windows Service ����  

���������֪ʶ�㽲�⣬���Ժ����ɵ����� Windows Service ����ļܹ���  

����֮�⣬[MSDN - CPP Windows Service](https://code.msdn.microsoft.com/windowsapps/CppWindowsService-cacf4948) ʾ��������ʾ�� service ����ļ��ء�������ֹͣ��ж�أ�Ҳ���Բο���  



### Service���������߼�


���� Windows service ������˵�������˿������ÿ����Զ������⣬������һ��ǳ����õ��ص㡪���Զ�������Auto restart������ Windows service �������ⱼ��֮��ϵͳ���Զ������� service���������������Ĵ������ο���[Auto restart a windows service if it crashes](https://stackoverflow.com/questions/36309449/how-to-restart-a-windows-service-using-task-scheduler)  

ServiceMain ���������� SCM ������һ�㲻�������ڵ��߳�ִ�� tasks���Է����� service ����ˣ����ǵ�������� ServiceMain �д����µ��߳�ִ�� service tasks ����  

Service ������Ϊһ�ֳ�פ�ڴ�ĺ�̨���̣�һ�㶼�������� watch dog ���ڳ�����Ƶ�ʱ�򣬿����� Service �����ڴ�����������ȥִ������������ƿ��Ա���Service ���̵�ַ�ռ�Ķ����ԣ��������� service ����ı���������  

