### Abstract
&emsp;&emsp;本文主要介绍 Windows service 的编程模式和 SCM 的相关功能。



### Content

- [基础知识](#基础知识)
  - [What is Windows Service](#what_is_windows_service)
  - [Service的登陆账户](#service的登录账户)
  - [SCM](#scm)
  - [Service Programs](#service_programs)
  - [Event Trace for Windows](#etw)
- [关键函数](#关键函数)
  - [Service Entry Point](#service_entry_point)
  - [ServiceMain](#servicemain)
  - [Service Control Handler](#service_control_handler)
- [Simple Windows Service in C++](#simple_service)
  - [sample介绍](#sample介绍)
  - [加载和卸载](#加载和卸载)
  - [windbg调试](#windbg调试)
- [Service程序的设计逻辑](#service程序的设计逻辑)
  - [auto_restart](#auto_restart)
  - [Watch Dog](#watchdog)


### 基础知识

#### What_is_Windows_Service

关于 Windows Service 的定义，可以参考 [Wiki: Windows Service](https://en.wikipedia.org/wiki/Windows_service) ,总结如下：  
1. Windows Services 类似 Unix Daemon （守护进程），它是一种常驻内存的**后台进程**。  
2. Windows Services 运行在专用账户上下文中，可以先于用户登录前运行。  
3. Windows Services 分别运行在三类用户账户：System, Network and Local 。它们的权限各不相同。  
4. Windows Services 需要符合 SCM 的接口规范和协议。  
5. SCM 负责管理 Windows Services，包括：查看状态、启动、停止等。  

参考 [MSDN - About Services](https://docs.microsoft.com/en-us/windows/desktop/services/about-services) 可知，Windows Services 包括以下几个主要知识点：  
- Service Control Manager
- Service program
- Service configuration program
- Service control program


#### Service的登陆账户

Windows Services 运行在三类用户账户中，观察 SCM 首页最后一列“Log On As”可知：  


Log On As | Description
---|---
Local System | 系统级的服务，比如 w3p.exe
Local Service| 普通本地服务
Network Service| 网络服务，比如 MSMQ

这三类账户的权限逐渐降低：Local System 账户不需要密码（本地系统账户），默认启动，所有登陆用户都可见；Local Service 账户需要用当前登陆用户的账号和密码；Network Service 也需要当前登陆用户的账号和密码。  


![](https://github.com/SuperSurfing/Windows-Internals-Notes/blob/master/Windwos%20Service%20and%20SCM/Images/service_lonin.png?raw=true)



#### SCM

SCM - [Service Control Manager](https://en.wikipedia.org/wiki/Service_Control_Manager)，是一个特殊的系统进程，负责管理 Windows Services 。  

> The SCM executable, Services.exe, runs as a Windows console program and is launched by the Wininit process early during the system startup. Its main function, SvcCtrlMain(), launches all the services configured for automatic startup.

SCM 通过读下面的注册表项来初始化它的“internal database”

> HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services, which contains the actual database of services and device drivers and is read into SCM's internal database.

换句话说，HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services 中包含了 Windows Services 的各种信息。

[《Windows驱动开发技术详解》](https://blog.csdn.net/Sagittarius_Warrior/article/details/87193389) CH3 中的 LoadNTDriver.exe 示例程序演示了如何通过 SCM 加载和卸载一个 Windows Service 。它的核心函数是 [CreateService()](https://docs.microsoft.com/en-us/windows/desktop/services/installing-a-service) 。 

下图是 SCM 显示的 service 属性：

![](https://github.com/SuperSurfing/Windows-Internals-Notes/blob/master/Windwos%20Service%20and%20SCM/Images/service_common.png?raw=true)


##### services.msc

通过 **services.msc** 命令可以打开 SCM 的 console 。


关于 SCM 更详细的资料，可以参考 [MSDN - SCM](https://docs.microsoft.com/en-us/windows/desktop/services/service-control-manager)，其中也提供了一个完整的示例程序 - [The Complete Service Sample](https://docs.microsoft.com/en-us/windows/desktop/services/the-complete-service-sample)。


##### Database

参考 [MSDN - About Services](https://docs.microsoft.com/en-us/windows/desktop/services/about-services) 可知“SCM 主要是通过数据库来管理 services”：

> The service control manager (SCM) maintains a database of installed services and driver services, and provides a unified and secure means of controlling them. The database includes information on how each service or driver service should be started. It also enables system administrators to customize security requirements for each service and thereby control access to the service.


#### Service_Programs

参考 [MSDN - Service Programs](https://docs.microsoft.com/en-us/windows/desktop/services/service-programs)。

为了符合 SCM 的接口要求，Windows Services程序必须包含这三个部分：  
- Service Entry Point
- Service ServiceMain Function
- Service Control Handler Function


#### ETW

通过 CMD 命令 **eventvwr.msc** 可以查看 Windows Services 程序的加载、卸载、启动、停止和崩溃等等记录。



### 关键函数

从进程创建的角度来看，Services 的启动需要经过以下几个步骤：  
1. CreateService/OpenService 向 SCM 注册 service 和拿到句柄  
2. SCM 将 Service Program 调起，其中需要创建进程内核对象
3. 操作系统检测到新的进程内核对象后，会为它分配“虚拟地址空间”，并将Image文件（module文件）加载到该地址空间
4. 操作系统创建主线程，执行 Service Program 的 main 函数
5. main 函数执行完 StartServiceCtrlDispatcher （向 SCM 注册 ServiceMain 函数指针）后退出。  
6. StartService 向 service controller 发起请求，service controller 在前面创建的进程地址空间中创建新线程，调用 ServiceMain  
7. ServiceMain 再创建线程，执行 service tasks 。  
8. ServiceMain 不直接执行  service tasks ，它会等待线程函数的结束。  
9. ServiceMain 会向 SCM 注册 Service Control Handler 回调函数，当需要停止时，SCM 会调用这个回调函数。  
10. Service Control Handler 会设置 STOP 事件，线程函数收到后，结束线程循环。  

#### Service_Entry_Point

> Services are generally written as console applications. The entry point of a console application is its main function. The main function receives arguments from the ImagePath value from the registry key for the service.

需要注意的是，services 程序都是 console 程序，它运行在后台，不带窗口。显然，它的入口函数只能是 main() 函数。  

##### main

Services 程序的执行流在 SCM 与 main() 函数之间有一个切换的动作，具体流程是：  
1. SCM 启动 service 程序，进入 main() 函数
2. main() 执行一些初始化操作
3. main() 调用 StartServiceCtrlDispatcher() 函数，将控制权又转交给 SCM ，然后就退出了。

> When the SCM starts a service program, it waits for it to call the StartServiceCtrlDispatcher function. 

##### StartServiceCtrlDispatcher

 StartServiceCtrlDispatcher() 函数能够告诉 SCM 关于该 service 的一些信息：  

> The StartServiceCtrlDispatcher function takes a **SERVICE_TABLE_ENTRY** structure for each service contained in the process. Each structure specifies the service name and the entry point for the service.

调用 StartServiceCtrlDispatcher 失败后，GetLastError() = 0x00000427  
> 服务进程无法连接到服务控制器上。   

从这里可以看出，**main 函数并不是注册 service 本身（CreateService 函数负责注册 service 本身），而只是注册 ServiceMain 函数**。



##### SERVICE_TABLE_ENTRY

SERVICE_TABLE_ENTRY 是一个字符串与函数指针的映射表，它标明一个进程可以注册多个 ServiceMain 函数。

联系前面的内容，事实上，main() 与传统意义的 win32 console 程序的 main() 完全不同，它仅仅是进行一些“公共初始化”，然后告诉 SCM 真正的入口点函数（ServiceMain）在哪。

##### service type

main() 函数的初始化操作与 service type 相关，共有两种 type:  
- SERVICE_WIN32_OWN_PROCESS 
- SERVICE_WIN32_SHARE_PROCESS 

前者立即调用 StartServiceCtrlDispatcher ，并在 service 启动后再执行初始化；后者需要在调 StartServiceCtrlDispatcher 进行一些“公共初始化”，也可以开新线程执行这个“公共初始化”。  


##### 示例

总结来说，service 的 main 函数很简单，主要调用 StartServiceCtrlDispatcher 函数，传入“Service Name”和“ServiceMain”。

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

ServiceMain() 才是 service 程序真正的功能开始执行的地方。它的名字可以任意指定，仅需要在 SERVICE_TABLE_ENTRY 保存即可。  

> When a service control program requests that a new service run, the Service Control Manager (SCM) starts the service and sends a start request to the control dispatcher. The control dispatcher creates a new thread to execute the ServiceMain function for the service. 

ServiceMain 与 main 不在同一个线程中。但是，它们应该在同一个进程上下文环境中（我猜）。

ServiceMain 的主要任务如下：  

1. 初始化所有的全局变量。参考《Windows核心编程》CH4“进程”，一般的Windows程序的全局变量初始化是在 mainCRTStartup 函数中。    
2. 注册回调函数。
> Call the **RegisterServiceCtrlHandler** function immediately to register a Handler function to handle control requests for the service. The return value of RegisterServiceCtrlHandler is a service status handle that will be used in calls to notify the SCM of the service status.  
3. 执行其他初始化工作。 
4. 创建 STOP 事件。  
5. 将 service 状态设为 “SERVICE_RUNNING”，告诉 service controller 该 service 已准备就绪。  
6. 开线程，执行“service tasks”  
7. 等待 STOP 事件。  
8. 设置 STOP 状态，执行清理工作，退出。


#### Service_Control_Handler

参考 [MSDN - Service Control Handler](https://docs.microsoft.com/en-us/windows/desktop/services/service-control-handler-function) ：

> Each service has a control handler, the Handler function, that is invoked by the control dispatcher when the service process receives a control request from a service control program. Therefore, this function executes in the context of the control dispatcher. 

Service Control Handler 是一个回调函数，其中会维护一个 switch - cases，执行 Controller dispatcher 的一些转发过来的一些关于 service 的 STOP 或 PENDING 相关的操作。

### Simple_Service

#### sample介绍

[Simple Windows Service in C++](https://www.codeproject.com/Articles/499465/Simple-Windows-Service-in-Cplusplus) 是一个非常小巧但是功能集备的 Windows Service 程序。  

对照上面的知识点讲解，可以很轻松地掌握 Windows Service 程序的架构。  

除此之外，[MSDN - CPP Windows Service](https://code.msdn.microsoft.com/windowsapps/CppWindowsService-cacf4948) 示例程序演示了 service 程序的加载、启动、停止和卸载，也可以参考。  

CPP Windows Service 示例程序中 wmain() 函数包含了三个执行流分支：install, remove, run ，分别对应不同的命令行参数。其中 run 分支对应的就是普通 service program 的 main 函数逻辑。 


#### 加载和卸载

Simple Windows Service in C++ 的作者给出的是命令行的加载方式。

关于 service 的加载，还可以参考 [install a service](https://stackoverflow.com/questions/8164859/install-a-windows-service-using-a-windows-command-prompt)  

[MSDN - install and uninstall service](https://docs.microsoft.com/en-us/dotnet/framework/windows-services/how-to-install-and-uninstall-services) 给出的是 VS 自带的加载工具。  


#### windbg调试

设置好符号路径，通过 windbg.exe 打开 SampleService.exe   

```
bp SampleService!wMain
g
g
k
```
可以查看它的 main 函数的调用堆栈

```
0:000:x86> k
 # ChildEBP RetAddr  
00 00cff7f4 009122ae SampleService!wmain [e:\code\learning\sampleservice\sampleservicemain.cpp @ 15] 
01 00cff808 00912117 SampleService!invoke_main+0x1e [d:\agent\_work\3\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl @ 90] 
02 00cff864 00911fad SampleService!__scrt_common_main_seh+0x157 [d:\agent\_work\3\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl @ 288] 
03 00cff86c 00912328 SampleService!__scrt_common_main+0xd [d:\agent\_work\3\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl @ 331] 
04 00cff874 762a0179 SampleService!wmainCRTStartup+0x8 [d:\agent\_work\3\s\src\vctools\crt\vcstartup\src\startup\exe_wmain.cpp @ 17] 
05 00cff884 77ac662d KERNEL32!BaseThreadInitThunk+0x19
06 00cff8e0 77ac65fd ntdll_77a60000!__RtlUserThreadStart+0x2f
07 00cff8f0 00000000 ntdll_77a60000!_RtlUserThreadStart+0x1b
```

从上面的堆栈信息可以明显发现，wmain 是程序的入口函数，它由 wmainCRTStartup 调用，在主线程执行。  


### Service程序的设计逻辑

#### auto_restart

对于 Windows service 程序来说，它除了可以设置开机自动启动外，它还有一项非常有用的特点——自动重启（Auto restart）。当 Windows service 程序意外奔溃之后，系统会自动重启该 service，可以设置重启的次数。参考：[Auto restart a windows service if it crashes](https://stackoverflow.com/questions/36309449/how-to-restart-a-windows-service-using-task-scheduler)    

下图是 SCM - service 属性中设置重启的页面：

![](https://github.com/SuperSurfing/Windows-Internals-Notes/blob/master/Windwos%20Service%20and%20SCM/Images/servicerestore.png?raw=true)   

这些设置都可以在注册表中找到

> HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\CppWindowsService


#### WatchDog

ServiceMain 函数用于与 SCM 交互，一般不在其所在的线程执行 tasks，以防阻塞 service 。因此，明智的设计是在 ServiceMain 中创建新的线程执行 service tasks 任务。 

除了多线程的设计模式，还有一种更复杂的多进程设计模式：    
1. 将 Service 进程作为一个 watch dog 进程。  
2. 在 ServiceMain 函数中，根据不同的任务，创建不同的进程，比如：工作进程、更新进程等。  
3. 在 ServiceMain 函数中创建一个 watch dog 线程，监视它的子进程。  
4. 在子进程中创建“命名事件对象”，提供给 watch dog 监测。

一般不直接将子进程的“进程对象”作为监视目标，因为一当子进程崩溃并重启后，它的进程对象也改变了（PID 不同）。



