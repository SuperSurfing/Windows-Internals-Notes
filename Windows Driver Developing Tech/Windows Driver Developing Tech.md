#### Abstract
&emsp;&emsp;如果推荐 Windows 驱动开发的入门书，我强烈推荐《Windows驱动开发技术详解》。但是由于成书的时间较早，该书中提到的很多工具和环境都已不可用或找不到，而本文搜集了大部分的工具，并在 win10X64 上安装开发环境，在 win7x86 上进行实验，趟过了不少实际编译和测试中遇到的坑。此外，本文也对相关章节的重点进行了总结，全文目录如下：

- [全书导读](#全书导读)
- [开发和调试](#开发和调试)
  - [驱动开发工具](#驱动开发工具)
  - [WinDbg](#windbg)
- [CH2 Windows操作驱动的基本概念](#驱动相关的操作系统知识)
- [CH3 驱动编译环境配置、安装和调试](#驱动程序的编译和调试)
  - [HelloDDK](#helloddk)
  - [LoadNTDriver](#loadntdriver)
  - [HelloWDM](#hellowdm)
    - [SubKey](#subkey)
    - [INF](#inf)
    - [安装HelloWDM](#安装hellowdm)
- [CH4 驱动程序的基本结构](#驱动程序的基本结构)
  - [驱动程序的数据结构](#驱动程序的数据结构)
    - [DRIVER_OBJECT](#驱动对象)
    - [DEVICE_OBJECT](#设备对象)
    - [DEVICE_EXTENSION](#设备扩展)
  - [驱动程序的加载过程](#驱动程序的加载过程)
    - [设备名与符号链接](#设备名与符号链接)
    - [WinObj观察驱动对象和设备对象](#winobj观察驱动对象和设备对象)
  - [WDM驱动的基本结构](#wdm驱动的基本结构)
    - [PDO and FDO](#pdo_and_fdo)
    - [Major IRP and Minor IRP](#major_irp_and_minor_irp)
  - [驱动的层次结构](#驱动的层次结构)
    - [设备对象堆栈](#设备对象堆栈)
    - [水平串联](#水平串联)
  - [实验](#实验)
- [CH5 Windows内存管理](#windows内存管理)
  - [内存管理的基本概念](#内存管理的基本概念)
  - [通用链表](#通用链表)
  - [Lookaside](#lookaside)
  - [内核内存操作函数](#内核内存操作函数)
- [CH6 Windows内核函数](#windows内核函数)
- [CH7 派遣函数](#派遣函数)
  - [IRP与派遣函数](#irp与派遣函数)
  - [缓存区方式读写与直接读写](#缓存区方式读写与直接读写)
  - [DeviceIoControl](#deviceiocontrol)
- [CH8 驱动程序的同步处理](#驱动程序的同步处理)
  - [同步与异步](#同步与异步)
  - [中断请求级别](#中断请求级别)
  - [自旋锁](#自旋锁)
  - [内核模式下的同步对象](#内核模式下的同步对象)
  - [其他同步方法](#其他同步方法)
- [CH9 IRP的同步](#irp的同步)
  - [同步操作与异步操作的原理](#同步操作与异步操作的原理)
  - [IRP的同步完成与异步完成](#irq的同步完成与异步完成)
  - [StartIO例程](#startio例程)
  - [中断服务例程](#中断服务例程)
  - [DPC例程](#dpc例程)
- [CH10 定时器](#定时器)
  - [定时器的实现方法一](#定时器的实现方法一) 
  - [定时器的实现方法二](#定时器的实现方法二)
  - [四种等待](#四种等待)
  - [时间内核函数](#时间内核函数)
  - [IRP超时处理](#irp超时处理)
- [CH11 驱动程序调驱动程序](#驱动程序调驱动程序)
  - [以文件句柄形式调用](#以文件句柄形式调用)
  - [通过设备指针调用](#通过设备指针调用)
  - [获取设备指针的方法](#获取设备指针的方法)
- [CH12 分层驱动程序](#分层驱动程序)
  - [分层驱动程序概念](#分层驱动程序概念)
  - [完成例程](#完成例程)
  - [将irp分解成多个irp](#将irp分解成多个irp)
  - [wdm驱动程序架构](#wdm驱动程序架构)
- [CH13 即插即用](#即插即用)
  - [即插即用IRP](#即插即用irp)
  - [通过设备接口（GUID）寻找设备](#通过设备接口寻找设备)
  - [实验一](#实验一)
- [CH21 再论IRP](#再论irp)
  - [转发IRP](#转发irp)
  - [创建IRP](#创建irp)
- [CH22 过滤驱动程序](#过滤驱动程序)
  - [文件过滤驱动程序](#文件过滤驱动程序)
  - [nt式过滤驱动程序](#nt式过滤驱动程序)
- [CH23 高级调试技巧](#高级调试技巧)
  


### 全书导读

&emsp;&emsp;《Windows驱动开发技术详解》全书由浅入深分为四个部分：入门篇、进阶篇、实用篇和提高篇，可以参考 [目录结构](https://www.jb51.net/books/256394.html)。

- 入门篇
  - CH1 两个简单的驱动
  - CH2 Windows 操作驱动的基本概念
  - CH3 驱动编译环境配置、安装和调试
  - CH4 驱动程序的基本结构
  - CH5 Windows 内存管理
  - CH6 Windows 内核函数
  - CH7 派遣函数
- 进阶篇
  - CH8 驱动程序的同步
  - CH9 IRP的同步
  - CH10 定时器
  - CH11 驱动程序调用驱动程序
  - CH12 分层驱动程序
  - CH13 即插即用（PnP - [Plug and Play](https://en.wikipedia.org/wiki/Plug_and_play)）
- 实用篇
- 提高篇
  - CH21 再论IRP
  - CH22 过滤驱动程序
  - CH23 高级调试技巧

  
### 开发和调试

#### 驱动开发工具

《Windows驱动开发技术详解》和《Windows内核安全编程》配套的 Driver Build 工具都是 WDK7600。它可以从 MSDN 上下载，也可以直接从如下链接下载，选择“Full Development Environment” ，默认路径安装即可（无须设置环境变量）。

[WinDDK 下载安装](https://infosys.beckhoff.com/english.php?content=../content/1033/tc3_c/54043195639122187.html&id=)

[DriverStudio 安装配置](https://blog.csdn.net/u012052268/article/details/53219441)


#### 驱动日志工具

最经典的驱动日志工具是 [sysinternals - DbgView.exe](https://docs.microsoft.com/en-us/sysinternals/downloads/debugview)，通过 C 风格的 [KdPrint()](https://blog.csdn.net/whatday/article/details/9530723) 函数输出日志。需要注意的是：KdPrint() 的日志只在 **Checked Build** 版本中才可见，在 Free Build 版本不可见。  

此外，Microsoft 也提供了一套 Driver 日志机制—— [WPP + TraceView.exe](https://blog.csdn.net/Sagittarius_Warrior/article/details/51205607)，适合有 PDB 文件的日志分析。

#### 驱动运行状态观察工具

Procexp.exe 可以观察驱动的运行状态，此外，还有 livekd.exe 和 kd.exe。

[DriverView.exe](https://www.nirsoft.net/utils/driverview.html) 用于观察系统已安装的全部驱动程序，也可以使用 CMD - systeminfo 命令查看驱动信息。


#### 驱动安装工具

[KmdManager.exe](https://bbs.pediy.com/thread-176945.htm) 是驱动加载和测试工具，[Link](http://www.website.masmforum.com/tutorials/kmdtute/index.html)。如下图所示，它提供了驱动的注册、启动服务（net start ***）和发送相关 IOControl 的功能。   

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/4283944C5E88492798B6D513B24B23FE/13082)  

[srvinstw.exe](http://xiazai.zol.com.cn/detail/45/442282.shtml) 是《Windows内核安全编程》推荐的一款驱动加载工具，并配有详细的操作步骤。

需要注意的是：KmdManager.exe 和 srvinstw.exe 都需要使用“**管理员权限**”运行。

除了 Driver Studio，Windows 驱动安装首选 [devcon.exe](https://blog.csdn.net/Sagittarius_Warrior/article/details/51262671)。它是附在 Windows WDK 中的一个工具。


#### WinDbg


### 驱动相关的操作系统知识

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/2EB720E4D9AD482A9A0CECEA2BEA14D9/14557)

其中，native api 对应的 PE 是 ntdll.dll，其 API 一般都以 Nt开头；而“系统服务函数”对应的 PE 是 ntosknrl.exe，其 API 一般都以 Zw 开头。此外，可以通过 Dependency walker.exe 查看其导出函数。

[城里城外看SSDT](https://blog.csdn.net/vangoals/article/details/4359042)



### 驱动程序的编译和调试

这一章主要介绍 Windows 驱动程序的开发环境搭建，驱动程序安装和驱动程序调试，主要参考《Windows驱动开发技术详解》的第三章和《Windows内核安全编程》第一章。其中，examples 用的是前者的，而开发环境和工具都使用的是后者的。

#### HelloDDK

HelloDDK 是一个 NT驱动，也就是说，它是一个非 PnP 驱动，仅以系统服务的形式存在，并不与设备相关。

1. 安装好 WDK7600后，启动 “Windows Driver Kits - x86 Checked Build Environment” 命令窗口，导航到源码目录。
2. 输入 “build” 指令，生成 sys 文件。
3. 在目标机器运行 srvinstw.exe ，安装该服务驱动。
4. cmd - net start/stop helloddk ，开启/停止该服务。

需要注意：
1. 安装该服务后，可以在如下注册表中看到

```
HKLM\SYSTEM\CurrentControlSet\services\HelloDDK
```
从《Windows驱动开发技术详解》第三章可知，服务安装的过程，实际上就是写注册表的过程。
2. 用 DbgView.exe 观察的时候，需要“管理员权限运行”和开启“Capture Kernel + Enable Verbose Kernel Output”。
3. 需要重启才能在 DeviceManager 中看到该新安装的“非即插即用设备”。
4. 

#### LoadNTDriver

LoadNTDriver 程序演示了如何调用 SCM 加载/卸载 NT 驱动程序，该程序源码(main.cpp)可疑放到一个 VS2017 的 win32 console 应用程序中 build，仅需修改以下几处：

1. Unicode 改为 “多字节字符集”
2. LoadNTDriver 和 UnloadNTDriver 形成增加 const 修饰
3. getch -> _getch
4. 可以将**运行时**改为 MT
5. 


#### HelloWDM

##### SubKey

HelloWDM 是一个 PnP 驱动，它注册的时候会创建三个子健：

Hardware子健

```
HKLM\SYSTEM\CurrentControlSet\Enum
```

Class子健

```
HKLM\SYSTEM\CurrentControlSet\Control\Class
```

service子健

```
HKLM\SYSTEM\CurrentControlSet\services\
```

##### INF

与 NT 驱动不同，WDM 驱动的注册表信息和设备信息都是在 INF 文件中定义的。《Windows驱动开发技术详解》CH1&CH3 都有对 INF 文件很详细的介绍。

[MSDN - INF](https://docs.microsoft.com/zh-cn/windows-hardware/drivers/install/overview-of-inf-files)

[INF 文件的节](https://blog.csdn.net/whatday/article/details/9382031)


##### 安装HelloWDM

通过 DeviceMgr - root 选择“安装过时硬件”  - 手动安装 - 从磁盘安装。

安装过程的日志会记录在 C:\Windows\INF\Setupapi.dev.log 文件中。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/3620E36E57C24DC0858703D7A48D0763/13162)


##### WDM驱动程序的结构

《Windows驱动开发技术详解》CH1简洁地解析了 HelloWDM 驱动程序每一行的意义，后面各章节更深入展开具体的技术细节。



### 驱动程序的基本结构

#### 驱动程序的数据结构

Windows驱动程序虽然是 C 语言实现的，但是它还是采用了 OOP 的编程模式，其中数据结构就是 OOP 中重要的基石。通俗点说，数据结构（struct）就是Windows驱动程序的对象的载体。

##### 驱动对象

OOP 编程模式中，一个对象代表一类实例。很明显，一个驱动对象就代表一个驱动程序。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/92305AAE956B4E72B4FF3625E0953EEB/13203)

##### 设备对象

设备对象是驱动对象的一个子对象，它对应一个设备。

[Introduction to device object](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-device-objects)


```
typedef struct _DEVICE_OBJECT {
  ...
  struct _DRIVER_OBJECT  *DriverObject;
  struct _DEVICE_OBJECT  *NextDevice;
  struct _DEVICE_OBJECT  *AttachedDevice;
  struct _IRP  *CurrentIrp;
  PIO_TIMER                   Timer;
  ULONG                       Flags;
  ULONG                       Characteristics;
  __volatile PVPB             Vpb;
  PVOID                       DeviceExtension;
  DEVICE_TYPE                 DeviceType;
  CCHAR                       StackSize;
  ...
} DEVICE_OBJECT, *PDEVICE_OBJECT;
```

需要特别注意的是 **NextDevice** 和 **AttachedDevice** ，NextDevice 是水平串联的设备的驱动对象，AttachedDevice则是分层驱动中垂直挂载的设备（虚拟设备）的驱动对象。


##### 设备扩展

在驱动编程中，应该尽量避免使用全局变量。设备对象记录“通用”设备的信息，其他“特殊”的信息则放在设备扩展（结构体）中。很明显，程序员自定义的一些变量尽量放在设备扩展（结构体）中。


#### 驱动程序的加载过程

这一节描述了驱动程序有 SYSTEM 进程加载的过程，驱动对象的创建，设备对象的创建等知识，非常重要。

##### 设备名与符号链接

前者只在内核模式下可以设备，后者相当于前者的别名。这一节对这两个知识点有很详细的介绍，非常清晰。


##### WinObj观察驱动对象和设备对象

这一节最后还介绍了如何用 sysinternals - winobj.exe 查看设备对象和驱动对象。主要包括：驱动对象、设备对象和符号链接。

此外，也可以用 [DeviceTree.exe](https://www.osronline.com/article.cfm?article=97) 查看这些信息。


#### WDM驱动的基本结构

WDM 驱动完成一个设备操作需要至少两个设备对象（垂直结构）—— PDO 和 FDO。

##### PDO_and_FDO

当检测到设备时，PDO 有总线驱动程序创建。FDO 由自定义的驱动程序创建并附加到 PDO 上。

注意：在驱动的层次结构中，**越靠近硬件的层**，越“下”。


##### major_irp_and_minor_irp

IRP 的编号由主编号和辅助编号一起指定，表明这个 IRP 的作用。

#### 驱动的层次结构

所谓“驱动的层次结构”，实际上是指设备对象的层次结构，包括 PDO 和 FDO。借助 [DeviceTree.exe](https://www.osronline.com/article.cfm?article=97) 可以很清晰地观察设备对象的层次结构。

##### 设备对象堆栈

底层设备对象依靠 DEVICE_OBJECT 中的 AttachedDevice 查找上层设备对象，如果 AttachedDevice 为空，则到达顶层。而高层设备对象则依靠 DEVICE_EXTENSION 记录下层的设备对象。也就是，双向查询的链路都是通畅的。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/BFA9C3DCB1A64D3FBC373BE474F7966F/13298)


##### 水平串联

同一个驱动对象创建出来的设备对象之间的关系描述为水平结构。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/6CB73670FA0D4B678052297DE10DE844/13338)


#### 实验

第一个实验是在原有的 HelloDDK 驱动程序的基础上，增加一个水平的设备对象，可以复用原有的 HelloDDK 中的 makefile和Sources文件，也可以使用原先的 LoadNTDriver.exe 程序进行测试。

第二个实验是在原有的 HelloWDM 驱动程序的基础上，增加垂直设备对象和水平设备对象的打印信息，可以复用原有的 HelloWDM 中的 makefile，Sources 和 INF 文件。


### Windows内存管理

这一章主要介绍内存管理方面的基本知识和在内核编程中需要注意的内存操作方法。

#### 内存管理的基本概念

内存管理的基本概念包括：物理内存管理（分段和分页）、虚拟内存管理（地址空间映射）、内核态地址空间和用户态地址空间、驱动程序与进程的关系、分页内存和非分页内存。  
这些知识在“操作系统”课程中讲解的更加详细，《Windows驱动开发技术详解》仅做了简单介绍。其中特别需要注意的是：  
1. Windows驱动程序的不同例程（routines）运行在不同的进程。DriverEntry和AddDevice运行在SYSTEM进程中。而其他如 IRP_MJ_READ 和 IPR_MJ_WRITE 的派遣函数运行在应用程序“上下文”中，只能访问对应的进程的虚拟内存地址。
2. 通过打印 log，可以查看当前例程所在的进程（PsGetCurrentProcess）。
3. 当程序的中断请求级别在 DISPATCH_LEVEL 之上时（包括DISPATCH_LEVEL），程序只能使用非分页内存，否则将 BSOD。


#### 通用链表

“操作系统”课程中的 ucore 也大量使用了“通用链表”，它是一种双向链表，一般作为子结构体嵌入到其他对象（结构体）中，从而实现跨不同对象的串联。

Windows 内核中的链表结构如下，Blink指向前一个对象（Before），Flink指向后一个对象（Follow）。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/0FF42E71603E4EA4AE3E20BC40CB2162/13466)

《Windows驱动开发技术详解》对 Windows 驱动中的链表有详细的操作（增删改查）介绍和相关的实验，适合编程时参考。

#### Lookaside

Lookaside 结构主要是为了避免内核内存碎片化而设计的，可以将它看作为内核内存池（容器）。


```
#pragma INITCODE
VOID LookasideTest() 
{
	//初始化Lookaside对象
	PAGED_LOOKASIDE_LIST pageList;
	ExInitializePagedLookasideList(&pageList,NULL,NULL,0,sizeof(MYDATASTRUCT),'1234',0);

#define ARRAY_NUMBER 50
	PMYDATASTRUCT MyObjectArray[ARRAY_NUMBER];
	//模拟频繁申请内存
	for (int i=0;i<ARRAY_NUMBER;i++)
	{
		MyObjectArray[i] = (PMYDATASTRUCT)ExAllocateFromPagedLookasideList(&pageList);
	}

	//模拟频繁回收内存
	for (i=0;i<ARRAY_NUMBER;i++)
	{
		ExFreeToPagedLookasideList(&pageList,MyObjectArray[i]);
		MyObjectArray[i] = NULL;
	}

	ExDeletePagedLookasideList(&pageList);
	//删除Lookaside对象
}
```

#### 内核内存操作函数

《Windows驱动开发技术详解》介绍了 RtlCopyMemory 等内核内存操作函数的用法，这方面可以参考 MSDN 的文档。

其中，P136 演示了如何用 Dependency Walker.exe 查看驱动依赖的PE - ntosknrl.exe 的导出函数，包括用到的导出函数和全部的导出函数。


### Windows内核函数

这一章主要介绍内核中常用的函数，包括：
- 字符串处理函数
- 文件读写函数
- 注册表读写函数
- 

当然，这些都可以查 DDK 文档和 MSDN 文档。这些函数大部分都在 ntosknrl.exe 中，可以通过 Dependency Walker.exe 进行查看。


### 派遣函数

CH2.3 “从应用程序到驱动程序”一节已经介绍了这一连串过程：


```
graph LR
App --> win32子系统 
win32子系统 --> NativeAPI
NativeAPI --> 系统服务函数
系统服务函数 --> IO管理器
IO管理器 --> 驱动程序派遣函数
```

1. 从 NativeAPI 到 “系统服务函数” 通过“软中断”实现了**从用户模式**到**内核模式**的切换。
2. IRP 是由 IO 管理器创建并发送给驱动程序的。
3. 驱动程序的主要职责就是处理 IO 请求。
4. 派遣函数实际上就是“请求-响应”模式中的**响应函数**。


#### IRP与派遣函数

##### IRP

IRP - I/O Request Package，实际上是 Windows 内核中的一种数据结构（对象）。上层应用程序向操作系统发送 I/O 请求，操作系统（主要是 I/O 管理器）将 I/O 请求转换为 IRP 发送给对应的驱动程序，驱动程序根据 IRP 的类型分配给不同的派遣函数进行处理。

IRP 是一个很复杂的数据结构，其中 MajorFunction 和 MinoreFunction 是它的两个最基本的属性。

参考 HelloWDM 的 DriverEntry 的源码，可以发现 DriverObject 有一个函数指针数组 MajorFunction。通过设置这个数组，可以将 IRP 的类型与派遣函数管理起来。注意，MajorFunction 是**函数指针数组**。

不同的 I/O 请求对应不同的 IRP 类型，本节通过一个表格列出了全部的 IRP 类型。  
[IRP 类型](https://msdn.microsoft.com/zh-cn/us_en/data/ff550694)  

##### 派遣函数

P189 通过 ReadFile 函数的调用过程，详解了派遣函数是如何处理和返回应用程序发起的 I/O 请求的。

##### IRP垂直转发

IRP先发送到顶层 DeviceObject，如果它没有结束 IRP ，则会继续往下层设备对象转发。其中 IO_STACK_LOCATION 结构体会记录对应设备（本层）中的操作。显然，IRP 维护了一个 IO_STACK_LOCATION 结构体数组。

本节通过一个实验演示了如何打印 IRP 的信息，见源码 DispatchTest - NTDriver。

此外，也可以通过 IRPTrace.exe 跟踪 IRP 。


#### 缓存区方式读写与直接读写

驱动程序创建的设备一般有三种读写方式：缓存区方式读写、直接读写和其他。其中，常用的是“缓存区方式读写”和“直接读写”，它们在创建设备（IoCreateDevice）后，由设备对象的 Flags 属性指定。

缓存区方式读写时，内核会复制用户态的 buffer 数据到 IRP 的子域 AssociatedIrp.SystemBuffer 中；而直接读写则不复制数据，而是直接锁定用户态的 buffer，防止进程切换，然后通过 MDL 记录这段 buffer，最后进行虚拟地址重映射。注意：这个 buffer 指的是 output buffer 。

##### MDL

直接方式读写设备时，操作系统会先重映射将用户模式下的缓存区锁住，并用 MDL 记录这段内存，然后到内核模式后，再进行虚拟地址重映射。  

MDL 主要记录三个值：这段 buffer 的大小（mdl->ByteCount）、buffer 的首页地址（mdl->StartVa）和这段 buffer 在首页的偏移量（mdl->ByteOffset）。它们可以通过以下几个宏获得：  

- MmGetMdlByteCount
- MmGetMdlVirtualAddress
- MmGetMdlByteOffset


```
NTSTATUS HelloDDKRead(IN PDEVICE_OBJECT pDevObj,
								 IN PIRP pIrp) 
{
	KdPrint(("Enter HelloDDKRead\n"));

	PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;
	NTSTATUS status = STATUS_SUCCESS;

 	PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(pIrp);

 	ULONG ulReadLength = stack->Parameters.Read.Length;
	KdPrint(("ulReadLength:%d\n",ulReadLength));

	ULONG mdl_length = MmGetMdlByteCount(pIrp->MdlAddress);
	PVOID mdl_address = MmGetMdlVirtualAddress(pIrp->MdlAddress);
	ULONG mdl_offset = MmGetMdlByteOffset(pIrp->MdlAddress);
	
	KdPrint(("mdl_address:0X%08X\n",mdl_address));
	KdPrint(("mdl_length:%d\n",mdl_length));
	KdPrint(("mdl_offset:%d\n",mdl_offset));

	if (mdl_length!=ulReadLength)
	{
		//MDL的长度应该和读长度相等，否则该操作应该设为不成功
		pIrp->IoStatus.Information = 0;
		status = STATUS_UNSUCCESSFUL;
	}else
	{
		//用MmGetSystemAddressForMdlSafe得到MDL在内核模式下的映射
		PVOID kernel_address = MmGetSystemAddressForMdlSafe(pIrp->MdlAddress,NormalPagePriority);
		KdPrint(("kernel_address:0X%08X\n",kernel_address));
		memset(kernel_address,0XAA,ulReadLength);
		pIrp->IoStatus.Information = ulReadLength;	// bytes xfered
	}
	
	pIrp->IoStatus.Status = status;
	
	IoCompleteRequest( pIrp, IO_NO_INCREMENT );
	KdPrint(("Leave HelloDDKRead\n"));

	return status;
}
```

实验 MDL_Test 分别打印了应用模式下的 buffer 地址和内核模式下重映射后的 buffer 地址。要深入了解 MDL ，可以阅读 CH12.3 IRP 分解。


#### DeviceIoControl

DeviceIoControl 是一类特殊的 I/O 请求，它可以在一次 I/O 请求中同时完成设备的读写操作。同样地，它也有三种控制方式。



### 驱动程序的同步处理

本章介绍了驱动程序中常用的同步处理办法，并且将内核模式下的同步处理方法和用户模式下的同步处理方法做了比较。另外，本章还介绍了中断请求级、自旋锁等同步处理机制。

#### 同步与异步

##### 可重入与不可重入

函数的执行结果是否与执行顺序相关。

关于“同步和异步”，最好参考《Windows核心编程》CH10 异步设备I/O，它讲解的更加详细。

#### 中断请求级别

##### IRQL

Windows 的中断分为“软件中断”和“硬件中断”，并统一映射了“中断请求级别”（IRQL）。同步机制很大程度上依赖于 IRQL 。

软件中断有 “int n” 汇编指令产生，而硬件中断，又称为“外部中断”，由外部设备发起，经“中断控制器”（PIC），发送给 CPU 。

通过“DeviceMgr” - 查看 - 依连接排序资源，可以查看系统中的各个中断。

> 以《我是歌手》这个综艺节目来类比“中断”和“中断请求级别”：  
如果说舞台是CPU，主持人就是调度进程。首先是主持人上舞台发言，然后安排各位歌手（进程）上台演唱。  
突然，（舞台大屏幕）插播一条广告，这个“插播”实际上就是“软件中断”，它实际上也是写在剧目中的，换句话说，“软件中断”（int n）也是写在程序中的。  
当节目进行中，突然舞台大屏幕不亮了，这个时候，就需要暂停节目，请工作人员上舞台来维修大屏幕。“大屏幕坏了”实际上就是“硬件中断”。  
如果在维修大屏幕的时候，不小心电路短路，舞台起火了，这个时候，就得暂停维修，然保安同志上来灭火。很显然，“舞台起火了”比“大屏幕坏了”的中断请求级别高。


![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/FA99BF72C55B4A57B365F6BD2F0A4BF2/13762)

用户模式的代码运行在最低的 PASSIVE_LEVEL 级别，而驱动程序的 DriverEntry, DispatchFunction, AddDevice 等一般也运行在 PASSIVE_LEVEL 级别，必要时它们可以提升到 DISPATCH_LEVEL 。

Windwos 负责线程调度的组件是运行在 DISPATCH_LEVEL 。

在内核模式下，可以通过 KeGetCurrentIrql 函数获取当前的 IRQL 。


##### IRQL与线程优先级

线程优先级是相对应用程序而言，而应用程序都运行在 PASSIVE_LEVEL 级别。

##### IRQL与内存分页

对于等于或高于 DISPATCH_LEVEL 级别的程序不能使用分页内存。驱动程序的 StartIO 例程、DPC 例程、中断服务例程都运行在 DISPATCH_LEVEL 或者更高的 IRQL 级别，它们都不能使用分页内存。

##### IRQL的提升与降低


header 1 | header 2
---|---
KeGetCurrentIrql | 获取当前 IRQL
KeRaiseIrql | 提升当前 IRQL
KeLowerIrql | 降低当前 IRQL


#### 自旋锁

Spin Lock 用于内核同步，主要是各派遣函数之间的同步。


#### 内核模式下的同步对象

这一节讲解了如何在内核模式下开线程和进行线程同步的。

##### 用户模式同步对象

用户模式下的同步对象包括：Event（事件）, Mutex（互斥体）和 Semaphone（信号灯）等，它们实际上是内核模式下的同步对象的封装。

关于用户模式下的同步，《Windows核心编程》一书讲解的更详细，其中还包括“关键区”（Critical Section）等非内核对象的同步方法。

##### 内核模式下的同步对象

用户模式下，各个函数都是以句柄（handle，一个 32 位整数）操作同步对象的；而内核模式下，程序员可以获得真实的同步对象指针。每种同步对象在内核中都会对应一种结构体。

内核模式下的等待函数：

- KeWaitForSingleObject
- KeWaitForMultipleObjects

##### 系统线程和用户线程

内核模式下用 PsCreateSystemThread 创建新线程，它既可以创建用户线程，也可以创建系统线程。

##### 实验

这个实验并没有给出源码，但是可以直接按照书中代码，手敲，并加入 HelloDDK 工程（CH5）。


```
#pragma PAGEDCODE
VOID SystemThread(IN PVOID pContext)
{
	KdPrint(("Enter SystemThread\n"));
	PEPROCESS pEProcess = IoGetCurrentProcess();
	PTSTR ProcessName = (PTSTR)((ULONG)pEProcess + 0x174);
	KdPrint(("This thread run in %s process !\n", ProcessName));
	
	// 结束线程
	KdPrint(("Leave SystemThread\n"));
	PsTerminateSystemThread(STATUS_SUCCESS);
}

#pragma PAGEDCODE
VOID MyProcessThread(IN PVOID pContext)
{
	KdPrint(("Enter MyProcessThread\n"));
	PEPROCESS pEProcess = IoGetCurrentProcess();
	PTSTR ProcessName = (PTSTR)((ULONG)pEProcess + 0x174);
	KdPrint(("This thread run in %s process !\n", ProcessName));
	
	// 结束线程
	KdPrint(("Leave MyProcessThread\n"));
	PsTerminateSystemThread(STATUS_SUCCESS);
}

#pragma PAGEDCODE
VOID CreateThread_Test()
{
	HANDLE hSystemThread, hMyThread;
	
	// 创建进程线程
	NTSTATUS status = PsCreateSystemThread(&hSystemThread, 0, NULL, NULL, NULL, SystemThread, NULL);
	
	// 创建系统线程
	status = PsCreateSystemThread(&hMyThread, 0, NULL, NtCurrentProcess(), NULL, MyProcessThread, NULL);
}
```

需要注意的是，在 win7 32bit 系统中，并没有打印出正确的进程名。


##### 应用程序传递事件给驱动程序

- DeviceIoControl  
- ObReferenceObjectByHandle
- ObDereferenceObjcet

它实际是通过 DeviceIoControl 将用户模式的句柄（索引）传到内核，然后通过 ObReferenceObjectByHandle 将句柄转换为内核对象（结构体）的指针。  
> 需要指出的是，句柄是与进程相关的，也就意味着一个进程中的句柄只能在这个进程中有效。





##### 驱动程序之间传递同步对象

创建**命名同步对象**


#### 其他同步方法

主要是“自旋锁”及其变种。


### IRP的同步

#### 同步操作与异步操作的原理

这一块的内容，《Windows核心编程》CH10 讲解的更详细。

CreateFile 的第六个参数（属性）可以指定用“同步”或“异步”的方式访问设备。

同步方式访问时，ReadFile, WriteFile and DeviceIoControl 中的 **OVERLAP** 数据结构设为 NULL，而异步方式访问，需要设置这个结构体，在其中嵌入 Event 。

[OVERLAP](https://docs.microsoft.com/en-us/windows/desktop/api/minwinbase/ns-minwinbase-_overlapped) 又称为“重叠结构”，这个结构体中包含一个 event 句柄。这个 Event 由用户创建，并等待内核返回。

此外，使用 ReadFileEx 或 WriteFileEx 进行异步读写时，不需要设置 OVERLAP 的 Event 子域，但是要设置“完成例程”（也称“回调例程”Callback Function）。

##### APC

APC - Asynchronous Procedure Call （异步过程调用）。它需要设置 OVERLAP 的 Event 来实现异步操作，而是通过回调例程来实异步，类似于软件中断。

- ReadFileEx
- WriteFileEx
- 


AsyncOperate2 的源码可以直接在 VS2017 win32 console 工程中运行。


#### IRP的同步完成与异步完成

用户模式对设备的同步和异步操作需要得到驱动程序的的支持。一般同步模式，是在 IRP 的派遣函数中直接处理相关请求，然后返回。而异步模式，则先在派遣函数中直接返回，后面再处理。

同步模式：


```
graph LR
ReadFile-->NtReadFile
NtReadFile-->ntoskrnl.exe
ntoskrnl.exe-->IRP
IRP-->DispatchFunction
DispatchFunction-->IoCompleteRequest
```

这一节非常详细地列出了“同步完成”和两种方式的“异步完成”的具体步骤，极其重要！

需要注意的是：APC 异步方式，IoCompleteRequest 会将完成函数（回调例程）插入 APC 队列。应用程序进入 Alert 模式，APC 队列会自动出队，并执行完成函数。

> IRP 的同步完成就是在派遣函数中，调用 IoCompleteRequest 将 IRP 处理完毕。


> IRP 被“异步完成”指的就是不在派遣函数中调用 IoCompleteRequest 内核函数。调用 IoCompleteRequest 函数意味着 IRP 请求的结束，也标志着本次对设备操作的结束。

这一节的实验“PendingIrpTest”非常重要，它演示了“异步操作”和“队列”，自定义设备扩展项，内核链表的使用等多项内核编程技术。  

```
PMY_IRP_ENTRY my_irp_entry;
	while(!IsListEmpty(pDevExt->pIRPLinkListHead))
	{
		PLIST_ENTRY pEntry = RemoveHeadList(pDevExt->pIRPLinkListHead);
		my_irp_entry = CONTAINING_RECORD(pEntry,
                              MY_IRP_ENTRY,
                              ListEntry);
 		my_irp_entry->pIRP->IoStatus.Status = STATUS_SUCCESS;
 		my_irp_entry->pIRP->IoStatus.Information = 0;	// bytes xfered
 		IoCompleteRequest( my_irp_entry->pIRP, IO_NO_INCREMENT );
 
		ExFreePool(my_irp_entry);
	}
```

这个是链表释放的代码，其中最重要的有两步：首先从链表中取出 PLIST_ENTRY 指针，然后通过 CONTAINING_RECORD 推算出链表单元 MY_IRP_ENTRY 的首地址（指针）。

此外，我们可以扩展一下，在派遣函数中不仅是挂起 IRP，还可以开启一个新线程，在这个线程函数中，执行完一系列任务后，再调用 IoCompleteRequest 完成 IO 请求，最后切换到用户模式执行回调例程。

需要注意的是，回调例程还是和应用程序IO请求在一个线程中。

这个实验的驱动部分同前面的 NTDriver，拷贝 makefile 和 sources 后，使用 DDK build。而应用程序可以使用 VS 2017 build 。

#### CancelIRP

驱动程序可以在派遣函数中为当前 IRP 设置 CancelRoutine ，当应用程序调用 CancelIO 时，将触发 CancelRoutine。更详细的步骤是：应用程序 CancelIO 将调用内核的 IoCancelIrp，而 IoCancelIrp 将调用之前注册（设置）的 CancelRoutine，在 CancelRoutine 里需要设置 STATUS_CANCELLED 并调用 IoCompleteRequest，最后还要释放全局 cancel 自旋锁。

很明显，IoCancelIrp 会获取一个自旋锁，它将运行在 DISPATCH_LEVEL 级别。应该尽可能将 CancelRoutine 设计的简单。

有了 cancel 功能，一个异步队列的功能就完整了。

实验 CancelIRP 演示了如何取消 IO 请求，但是 CancelIO 函数的参数是设备句柄，而不是具体某次 IO 请求。


#### StartIO例程


> StartIO 例程能够保证各个并发的 IRP 顺序执行，即串行化。

所谓的“串行化”，我们可以想象一下“开车进长江隧道”的情形。假设过江隧道只允许单向一条车道通行，而隧道口是四股车流，此时就需要竞争，将四股车流合成一股，这就是“串行化”。

StartIO 是 DDK 提供的一个内部队列，并支持 IRP 取消函数、超时、同步插入队列等操作。


```
typedef struct _KDEVICE_QUEUE {
    CSHORT Type;
    CSHORT Size;
    LIST_ENTRY DeviceListHead;
    KSPIN_LOCK Lock;
    BOOLEAN Busy;
} KDIVECE_QUEUE, *PKDEVICE_QUEUE;
```

实验 StartIOTest 演示 向 DriverObject 注册 StartIO 例程和派遣函数通过 IoStartPacket 将 IRP 加入队列。

从“生产者”和“消费者”模型来看，StartIO 就是消费者，派遣函数是生产者。但是，具体的“入队”和“出队”操作是操作系统完成的。

需要注意的是，已出队的 IRP （进入 StartIO）不能取消。也就是说，只能取消队列中的 IRP 。

参考书中的 IoStartPacket 和 IoStartNextPacket 的伪代码


```
// 获取自旋锁
...

device->CurrentIrp = Irp;

// 释放自旋锁
...

device->DriverObject->DriverStartIo(device, Irp);
```

也就是说，IoStartPacket 和 IoStartNextPacket 会重新指定 device->CurrentIrp，并调用 StartIo 例程。

需要注意的是，这段伪代码仅展示了其中的一条逻辑分支，即“设备空闲”，可以调用 StartIo 例程，而没有展示另一个分支“设备忙”，需要插入队列。

因为 StartIo 和 CancelIrp 都是允许在 DISPATCH_LEVEL，在执行具体逻辑前，需要先加锁（全局锁），并判断对方是否已执行同一个 IRP。

学习后面的“自定义StartIO”，可以更加深入地了解内核队列的使用细节。“自定义StartIO”与内置的 StartIO 不同的是，它不是回调函数，而是一个普通函数，直接被派遣函数调用。

KeInsertDeviceQueue 函数的返回值表明当前设备是否“空闲”。也就是说，在生产者这一端就会判断是否需要入队。

另外，在 StartIo 例程中，开启了一个循环执行出队操作。一定要在多线程环境下去理解“自定义StartIO”，派遣函数和“自定义StartIO”都在多线程环境下并发。“入队”和“出队”的内核 API 应该也内置了互斥机制。


#### 中断服务例程

中断服务例程（ISR - Interupt Service Routine）


#### DPC例程

> DPC例程一般和 ISR 配合使用，它运行于相对 ISR 较低的 DISPATCH_LEVEL 级别。因此，一般将不需要紧急处理的代码放在DPC例程，而将需要紧急处理的代码放在ISR中。


### 定时器

本章总结了在内核模式下的四种等待方法，读者可以利用这些方法灵活地用在自己的驱动程序中。最后本章还介绍了如何对irp的超时情况进行处理。

>在驱动程序中有两种使用定时器（Timer）的方法，一种方法是使用IO定时器例程，另一种方法是使用DPC例程。

#### 定时器的实现方法一

利用 DDK 内置的 IO Timer，实现 ms 级的定时器。



#### IRP超时处理

> 首先初始一个定时器对象和一个DPC对象，并将DPC例程与定时器对象进行关联。在每次对IRP操作前，开启定时器，并设置好一定的超时。如果在指定的时间内对IRP的处理没有结束，那么操作系统就会进入DPC例程。  
在DPC例程中取消还在继续处理的IRP。如果驱动程序在超时前结束IRP的操作，则应该取消定时器，从而保证不会再次取消IRP。

实验“IRPTimeout”展示了 DPC例程和定时器的联合应用。这个实验比较简单，可以扩展“正常完成IRP则取消定时器”的功能。


### 驱动程序调驱动程序

> 本章主要介绍了分层驱动的概念。分层驱动可以将功能复杂的驱动程序分解为多个功能简单的驱动程序。多个分层的驱动程序形成一个设备堆栈，irp请求首先发送到设备堆栈的顶层，然后依次穿越每层的设备堆栈，最终完成irp请求。

本章将要介绍的是纯内核模式的编程，它可以很自由地跨越进程的边界。它也是前面所有章节知识的大揭秘，包括：同步与异步IRP 的实现原理、句柄与内核对象的转换方法、IRP 的实现原理等。

[IRP介绍](https://www.cnblogs.com/LittleHann/p/3450436.html)

#### 以文件句柄形式调用

在内核模式下以文件句柄形式调用其他驱动程序，实际上就是将用户模式下发起 I/O 的相关 win32 API （NTDLL.dll） 替换为其对应的内核 API （ntoskrnl.exe）即可，包括：  


win32 API | kernel api | IRP
---|---|---
CreateFile | [ZwCreateFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatefile) | IRP_MJ_CREATE
CloseHandle | ZwCloseFile | IRP_MJ_CLOSE
ReadFile | [ZwReadFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwreadfile) | IRP_MJ_READ
WriteFile | [ZwWriteFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwwritefile) | IRP_MJ_WRITE

需要注意的是：CreateFile 需要被操作设备的“符号链接”，而 ZwCreateFile 则可以直接通过设备名拿到 ObjectAttributes 对象的指针。其他几个函数都是操作设备句柄。  
此外，内核函数会直接发起相关的 IRP ，而用户模式是通过 I/O 管理器调用对应的内核函数发起相关的 IRP 。


##### 实验1

源码是以 VC 工程给出的，查看相关的 *.dsp 文件可以发现，在链接器 link.exe 中指明了它的输出文件：

```
/out:"MyDriver_Check/HelloDDKA.sys"
```

我们在改为 DDK build 时，需要修改 sources 文件中的 TARGETNAME。

```
TARGETNAME=HelloDDKA
TARGETTYPE=DRIVER
TARGETPATH=OBJ

INCLUDES=$(BASEDIR)\inc;\
         $(BASEDIR)\inc\ddk;\

SOURCES=Driver.cpp\
```

##### 异步调用

1. 调用 ZwReadFile 前，先为 IRP 设置一个完成例程（APC）。
2. 设置一个事件
3. 在完成例程中激发事件。

参考实验2的代码，与用户模式的异步不同的是，这里即设置了“回调例程”，也设置了同步事件，而用户模式APC不需要设置事件，它需要的是调用 SleepEx，让当前线程处于 Alert 状态即可。

##### 异步调用方法二

不另外再设置同步事件，而是直接使用文件对象的子域事件作为同步事件。

> 每打开一个设备，都会伴随存在一个关联的文件对象（FILE_OBJECT）。利用内核函数 ObReferenceObjectByHandle 可以获得和设备相关的文件对象指针。当 IRP_MJ_READ 请求被结束后，文件对象的子域 Event 会被设置，因此用文件对象的 Event 子域可以当做同步点。

##### 通过符号链接打开设备

内核中一般通过设备名来打开设备，但是，也可以通过符号链接来打开设备。

> 利用 ZwOpenSymbolicLinkObject 内核函数先得到（符号链接）设备的句柄，然后使用 ZwQuerySymbolicLinkObject 内核函数查找到设备名。

参考 Test4 源码


```
	UNICODE_STRING DeviceSymbolicLinkName;
	RtlInitUnicodeString( &DeviceSymbolicLinkName, L"\\??\\HelloDDKA" );

	//初始化objectAttributes
	OBJECT_ATTRIBUTES objectAttributes;
	InitializeObjectAttributes(&objectAttributes, 
							&DeviceSymbolicLinkName,
							OBJ_CASE_INSENSITIVE|OBJ_KERNEL_HANDLE, 
							NULL, 
							NULL );

	HANDLE hSymbolic;
	//设定了FILE_SYNCHRONOUS_IO_NONALERT或者FILE_SYNCHRONOUS_IO_ALERT为同步打开设备
	ntStatus = ZwOpenSymbolicLinkObject(&hSymbolic,FILE_ALL_ACCESS,&objectAttributes);
#define UNICODE_SIZE 50
	UNICODE_STRING LinkTarget;
	LinkTarget.Buffer = (PWSTR)ExAllocatePool(PagedPool,UNICODE_SIZE);
	LinkTarget.Length = 0;
	LinkTarget.MaximumLength = UNICODE_SIZE;

	ULONG unicode_length;
	ntStatus = ZwQuerySymbolicLinkObject(hSymbolic,&LinkTarget,&unicode_length);

	KdPrint(("DriverB:The device name is %wZ\n",&LinkTarget));

	InitializeObjectAttributes(&objectAttributes, 
							&LinkTarget,
							OBJ_CASE_INSENSITIVE, 
							NULL, 
							NULL );
	
	HANDLE hDevice;
	IO_STATUS_BLOCK status_block;
	//设定了FILE_SYNCHRONOUS_IO_NONALERT或者FILE_SYNCHRONOUS_IO_ALERT为同步打开设备
	ntStatus = ZwCreateFile(&hDevice,
		FILE_READ_ATTRIBUTES|SYNCHRONIZE,
		&objectAttributes,
		&status_block,
		NULL,FILE_ATTRIBUTE_NORMAL,FILE_SHARE_READ,
		FILE_OPEN_IF,FILE_SYNCHRONOUS_IO_NONALERT,NULL,0);

	if (NT_SUCCESS(ntStatus))
	{
		ZwReadFile(hDevice,NULL,NULL,NULL,&status_block,NULL,0,NULL,NULL);
	}
	
	ZwClose(hDevice);
	ZwClose(hSymbolic);
	ExFreePool(LinkTarget.Buffer);
```


#### 通过设备指针调用

以文件句柄形式调用驱动程序的方法与用户模式下的操作类似，而本节将介绍内核模式特有的直接通过“设备指针”调用的方法。

> 不借用 ZwCreateFile 和 ZwReadFile 等内核函数，而是手动构造各个 IRP，然后将 IRP 传递到相应驱动函数的派遣函数里。

##### [IoGetDeviceObjectPointer ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iogetdeviceobjectpointer)

> 每个内核中的句柄都会和一个内核对象的指针联系起来。


```
NTSTATUS IoGetDeviceObjectPointer(
  PUNICODE_STRING ObjectName,
  ACCESS_MASK     DesiredAccess,
  PFILE_OBJECT    *FileObject,
  PDEVICE_OBJECT  *DeviceObject
);
```

IoGetDeviceObjectPointer 内核函数可以通过设备名直接获得“文件对象”指针和“设备对象”指针。

> 当调用 IoGetDeviceObjectPointer 内核函数后，设备对象的引用计数会加 1， 当用完这个设备对象后，应该调用 ObDereferenceObject 内核函数，使其引用计数减 1。

##### 创建IRP

参考 [创建IRP的四种方法](https://blog.csdn.net/vangoals/article/details/4381567)
  
- [IoBuildSynchronousFsdRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildsynchronousfsdrequest)  
- [IoBuildAsynchronousFsdRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildasynchronousfsdrequest)
- [IoBuildDeviceIoControlRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuilddeviceiocontrolrequest)
- [IoAllocateIrp ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-ioallocateirp)
- IoCallDriver
- 

手动创建IRP的几个步骤：  
1. 先得到设备指针。一种方法是调用 IoGetDeviceObjectPointer；另一种方法是先调 ZwCreateFile 获得设备句柄，再调 [ObReferenceObjectByHandle](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-obreferenceobjectbyhandle) 内核函数通过设备句柄获得设备指针。
2. 使用上面提到的4个内核函数创建IRP。
3. 构造IRP的I/O堆栈
4. 调用 IoCallDriver 内核函数，它内部会调用设备对象的派遣函数。

实验5


```
	UNICODE_STRING DeviceName;
	RtlInitUnicodeString( &DeviceName, L"\\Device\\MyDDKDeviceA" );

	PDEVICE_OBJECT DeviceObject = NULL;
	PFILE_OBJECT FileObject = NULL;
	//得到设备对象句柄，计数器加1
	//如果是第一次调用IoGetDeviceObjectPointer，会打开设备，相当于调用ZwCreateFile
	ntStatus = IoGetDeviceObjectPointer(&DeviceName,FILE_ALL_ACCESS,&FileObject,&DeviceObject);

	KdPrint(("DriverB:FileObject:%x\n",FileObject));
	KdPrint(("DriverB:DeviceObject:%x\n",DeviceObject));

	if (!NT_SUCCESS(ntStatus))
	{
		KdPrint(("DriverB:IoGetDeviceObjectPointer() 0x%x\n", ntStatus ));

		ntStatus = STATUS_UNSUCCESSFUL;
		// 完成IRP
		pIrp->IoStatus.Status = ntStatus;
		pIrp->IoStatus.Information = 0;	// bytes xfered
		IoCompleteRequest( pIrp, IO_NO_INCREMENT );
		KdPrint(("DriverB:Leave B HelloDDKRead\n"));

		return ntStatus;
	}

	KEVENT event;
	KeInitializeEvent(&event,NotificationEvent,FALSE);
	IO_STATUS_BLOCK status_block;
	LARGE_INTEGER offsert = RtlConvertLongToLargeInteger(0);

	//创建同步IRP
	PIRP pNewIrp = IoBuildSynchronousFsdRequest(IRP_MJ_READ,
												DeviceObject,
												NULL,0,
												&offsert,&event,&status_block);
 	KdPrint(("DriverB:pNewIrp:%x\n",pNewIrp));

	PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(pNewIrp);
	stack->FileObject = FileObject;

	//调用DriverA，会一直调用到DriverA的派遣函数
	NTSTATUS status = IoCallDriver(DeviceObject,pNewIrp);

    if (status == STATUS_PENDING) {

		//如果DriverA的派遣函数没有完成IRP，则等待IRP完成
       status = KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            NULL);
        status = status_block.Status;
    }

	//将引用计数减1，如果此时计数器减为0，
	//则将关闭设备，相当于调用ZwClose
 	ObDereferenceObject( FileObject );
```

实验七演示了最原始的 IoAllocateIrp 内核函数的使用方法和手动构造 IRP 的方法，原书代码会BSOD，可以参考[CSDN博客](https://blog.csdn.net/qq125096885/article/details/47340291)。

> 所有对设备的操作都会转化为一个 IRP ，而所有的 IRP 最终都是由 IoAllocateIrp 内核函数创建的。


```
PIRP IoAllocateIrp(
  CCHAR   StackSize,
  BOOLEAN ChargeQuota
);
```

使用 IoAllocateIrp 创建了 IRP 后，需要使用 IoFreeIrp 释放相关的数据结构


```
	PDEVICE_OBJECT DeviceObject = NULL;
	PFILE_OBJECT FileObject = NULL;
	//通过设备名得到设备对象指针
	ntStatus = IoGetDeviceObjectPointer(&DeviceName,FILE_ALL_ACCESS,&FileObject,&DeviceObject);

	KdPrint(("DriverB:FileObject:%x\n",FileObject));
	KdPrint(("DriverB:DeviceObject:%x\n",DeviceObject));

	if (!NT_SUCCESS(ntStatus))
	{
		KdPrint(("DriverB:IoGetDeviceObjectPointer() 0x%x\n", ntStatus ));
		ntStatus = STATUS_UNSUCCESSFUL;
		// 完成IRP
		pIrp->IoStatus.Status = ntStatus;
		pIrp->IoStatus.Information = 0;	// bytes xfered
		IoCompleteRequest( pIrp, IO_NO_INCREMENT );
		KdPrint(("DriverB:Leave B HelloDDKRead\n"));

		return ntStatus;
	}

	KEVENT event;
	KeInitializeEvent(&event,NotificationEvent,FALSE);

	PIRP pNewIrp = IoAllocateIrp(DeviceObject->StackSize,FALSE);
	KdPrint(("pNewIrp->UserEvent :%x\n",pNewIrp->UserEvent));
	pNewIrp->UserEvent = &event;

	IO_STATUS_BLOCK status_block;
    pNewIrp->UserIosb = &status_block;
    pNewIrp->Tail.Overlay.Thread = PsGetCurrentThread();

	//因为DriverA是BUFFER IO设备
	pNewIrp->AssociatedIrp.SystemBuffer = NULL;
	
 	KdPrint(("DriverB:pNewIrp:%x\n",pNewIrp));

    // 构造I/O堆栈
	PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(pNewIrp);
	stack->MajorFunction = IRP_MJ_READ;
	stack->MinorFunction=IRP_MN_NORMAL;//0
	stack->FileObject = FileObject;

	//调用DriverA驱动
	NTSTATUS status = IoCallDriver(DeviceObject,pNewIrp);

    if (status == STATUS_PENDING) {
       status = KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
							NULL);
	   KdPrint(("STATUS_PENDING\n"));
    }

 	ObDereferenceObject( FileObject );
	IoFreeIrp(pNewIrp);
```

上述代码在实验中，发现会导致 BSOD，注释 IoFreeIrp 这一句后才解决这个问题。在学习完“分层驱动”之后，我们知道，一当调用了 IoCallDriver 后，IRP 的控制权就转交给了被调驱动程序，此后，只有在完成例程中才能拿回控制权。否则，在调用 IoCallDriver 后再设置 IRP，则会引起奔溃。参考 12.1 完成例程。




#### 获取设备指针的方法

这一节深入介绍了 Windows 内部如何获得设备对象指针，它实现了自定义的 IoGetDeviceObjectPointer 函数。


```
//模拟IoGetDeviceObjectPointer实现
NTSTATUS
MyIoGetDeviceObjectPointer(
    IN PUNICODE_STRING ObjectName,
    IN ACCESS_MASK DesiredAccess,
    OUT PFILE_OBJECT *FileObject,
    OUT PDEVICE_OBJECT *DeviceObject
    )
{
    PFILE_OBJECT fileObject;
    OBJECT_ATTRIBUTES objectAttributes;
    HANDLE fileHandle;
    IO_STATUS_BLOCK ioStatus;
    NTSTATUS status;

	//设置要打开的设备的设备名
    InitializeObjectAttributes( &objectAttributes,
                                ObjectName,
                                OBJ_KERNEL_HANDLE,
                                (HANDLE) NULL,
                                (PSECURITY_DESCRIPTOR) NULL );

	//ZwOpenFile打开设备，获得文件对象句柄
    status = ZwOpenFile( &fileHandle,
                        DesiredAccess,
                        &objectAttributes,
                        &ioStatus,
                        0,
                        FILE_NON_DIRECTORY_FILE );

    if (NT_SUCCESS( status )) 
	{
		//通过文件对象句柄，得到文件对象指针
        status = ObReferenceObjectByHandle( fileHandle,
                                            0,
                                            *IoFileObjectType,
                                            KernelMode,
                                            (PVOID *) &fileObject,
                                            NULL );
        if (NT_SUCCESS( status )) 
		{
            *FileObject = fileObject;
			//通过文件对象指针，得到设备对象指针
            *DeviceObject = IoGetBaseFileSystemDeviceObject( fileObject );
        }
        ZwClose( fileHandle );
    }
    return status;
}
```

[Troubleshooting: MULTIPLE_IRP_COMPLETE_REQUESTS ](https://troubleshooter.xyz/wiki/fix-multiple_irp_complete_requests-error/)


### 分层驱动程序

本章主要介绍了分层驱动的概念。分层驱动可以将功能复杂的驱动程序分解为多个功能简单的驱动程序。多个分层的驱动程序形成一个设备堆栈，irp请求首先发送到设备堆栈的顶层，然后依次穿越每层的设备堆栈，最终完成irp请求。

#### 分层驱动程序概念

分层驱动程序对应多个驱动程序，每个驱动程序创建一个设备对象，然后设备对象会一层一层地“挂载”在其他设备对象之上。

##### 设备对象

[DEVICE_OBJECT](https://msdn.microsoft.com/en-us/library/windows/hardware/ff543147(v=vs.85).aspx)

从设备对象的数据结构从设计上支持分层驱动程序。

[Introduction to device objects](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-device-objects)

##### 设备堆栈与挂载

```
PDEVICE_OBJECT IoAttachDeviceToDeviceStack(
  PDEVICE_OBJECT SourceDevice,
  PDEVICE_OBJECT TargetDevice
);
```

- [IoAttachDeviceToDeviceStack](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-ioattachdevicetodevicestack)
- [IoDetachDevice](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iodetachdevice)

注意：IoDetachDevice 只有一个参数——TargetDevice，它是被删除设备的下层设备。

##### IO堆栈

> 在 Windows 驱动模型中，还有一个概念叫“I/O堆栈”，用 IO_STACK_LOCATION 数据结构表示。它和设备堆栈紧密结合。

> 在 IRP 的数据结构中，存储着一个 IO_STACK_LOCATION 数组的指针。调用 IoAllocateIrp 内核函数创建 IRP 时，有一个 StackSize 参数，该参数就是 IO_STACK_LOCATION 数组的大小。

关于 IO_STACK_LOCATION 数组，还可以参考 CH7.1 节。

IRP 每穿越一次设备堆栈，就会用 IO_STACK_LOCATION 记录下本次操作的某些属性。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/6B4457CC0CC5442FBD1C8E26F6180BF3/14881)


##### 向下转发IRP

顶层驱动的设备对象收到 IRP，进入派遣函数后有三种处理方式：  
1. 调用 IoCompleteRequest 直接结束 IRP
2. 调用 StartIo 串行化 IRP，除当前 IRP 外，其他的进入 IRP 队列
3. 向下转发 IRP

向下转发 IRP 的时候，需要注意 IO_STACK_LOCATION 的变化

跳过当前层


```
PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;

// 调用下层驱动
IoSkipCurrentIrpStackLocation(pIrp);

ntStatus = IoCallDriver(pdx->TargetDevice, pIrp);
```

当前层参与操作

```
PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;

// 调用下层驱动
IoCopyCurrentIrpStackLocationToNext(pIrp);

ntStatus = IoCallDriver(pdx->TargetDevice, pIrp);
```

##### 实验一

实验1 演示了如何将 DriverA 的设备对象挂载到 DriverB 上，同时转发对应的 IRP 。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/9EBC81019420434DA1C685868AB1F1E4/14961)

从日志中可以看出，DriverB hook 了 DriverA 的 CreateFile, ReadFile and CloseFile 三个 I/O 接口。此外，需要注意 DriverA 是异步完成，而 DriverB 也继承了这种异步特性，但实际应用层测试函数采用的是同步读。 

可以通过 DeviceTree.exe 查看它们之间的挂载关系。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/2645DFF60E1B40168F8AA32F6F0FD23D/14979)

##### 实验二 

实验2 剖析了DeviceTree.exe枚举设备对象的原理。


#### 完成例程

关于“完成例程”，可以参考 CH9 IRP的同步，其中“异步操作设备方式二”使用的就是“完成例程”。本节主要学习分层驱动程序中，“完成例程”是如何在各层中传递的。  

本节主要介绍 IRP 的控制权流转。

##### 完成例程概念

当驱动程序通过 IoCallDriver 调用自己的下层驱动或其他驱动时，会将 IRP 的控制权交给被调的驱动。  
有两种情况：一是被调用的设备是同步完成这个 IRP，那么，在 IoCallDriver 返回时，IRP 即完成。二是被调用的设备是异步完成这个 IRP，那么，IoCallDriver 会立即返回，但 IRP 并没有真正完成。  
对于第二种情况，可以在调用 IoCallDriver 前，向 IRP 注册一个“完成例程”。当 IRP 真正完成的时，这个“完成例程”即会被调用。其实注册 IRP 完成例程就是在当前堆栈（IO_STACK_LOCATION）中的 CompletionRoutine 子域。IRP 完成后，一层层堆栈向上弹出，它会同步检查这个子域，如果非空则会调用完成例程。另外，传进完成例程的就是 IO_STACK_LOCATION 的另一个子域 Context 。  

[IoSetCompletionRoutine ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iosetcompletionroutine)

[当前驱动层设置下层驱动的完成例程](https://blog.csdn.net/kemaWCZ/article/details/82690095)

> 完成例程可以作为通知 IRP 完成的一个标志。在完成例程中可以很清楚地知道 IRP 的完成状况。或者说，在完成例程中，提供了一个机会重新获得 IRP 的控制权。  

##### 传播 Pending 位

设置了完成例程会，传播 Pending 位的工作需要程序员在代码中指定。

实验3演示了完成例程和传播 Pending 位。

实验4演示了完成例程返回 STATUS_MORE_PROCESSING_REQUIRED，让本层驱动重新获得 IRP 控制权。


#### 将irp分解成多个irp

利用前面所说的完成例程返回 STATUS_MORE_PROCESSING_REQUIRED，重新获取 IRP 的控制权，继续向下转发 IRP。或者说，它改变了 IRP 沿着栈直下直上的流动方式。


IRP 分解可以想象一下少林寺挑水和尚去古井取水的情形：  
和尚挑水用的是大牌桶（外层 IRP），比井口大，不能放到井里去直接取水。于是，可以用一个小桶（中间层 IRP）去井里取水，夺取几次，一起存在大牌桶挑回寺庙。

实验5演示了 IRP 的分解和借助 MDL 实现直接读写。这个实验的应用模式测试程序、DriverA 和 DriverB 都需要重新编译。其中 DriverA 的 MDL 不是典型用法，典型用法可以参考 CH7 的 MDL_Test 实验。


[MDL实现内核模式下大缓存分片](https://blog.csdn.net/wdykanq/article/details/7752909)

[初步认识MDL](https://blog.csdn.net/cosmoslife/article/details/50395985)

The [IoBuildPartialMdl](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildpartialmdl) routine builds a new memory descriptor list (MDL) that represents part of a buffer that is described by an existing MDL.

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/56C1480F51A04320A886888D5B5284AF/15142)

上面这份日志的执行流不再是直下直上。


#### wdm驱动程序架构

WDM 驱动与 NT 驱动最大的不同是引入了 PNP 机制。

IRP_MJ_PNP 与其他的 IRP 不同的是，它不是来自于应用程序，而是当设备被插入、拔出或被系统加载时，由 I/O 管理器向驱动程序发送 IRP_MJ_PNP。随后，它将被转发给底层设备对象，由底层总线驱动去处理。这样的设计，使得底层的修改不影响上层的逻辑驱动。  

##### PDO

PDO - Physical Device Object，是由微软提供的总线驱动程序所创建，它完成了 PnP 和电源管理等功能。在 Windows 中有多个总线驱动程序，分别是 PCI 总线驱动程序，USB 总线驱动程序，ISA 总线驱动程序和虚拟总线驱动程序等。其中，PCI 总线是 ROOT 总线。

> 当系统启动时，根总线驱动被加载，然后寻找挂载于根总线上的驱动设备。如果发现有 PCI 设备，就会加载 PCI 设备的 PDO，然后寻找合适的 FDO 加载。PCI-ISA 桥、USB 适配器会当作是 PCI 设备，被加载 PDO 和 FDO 等。

###### PDO and PnP

在 PnP 之前的的驱动模型中，某个外设的系统资源都是固定的，包括：I/O 地址空间、物理地址空间、中断号等资源。而 PnP 实现了这些资源的动态分配。


### 即插即用

[Plug and Play](https://en.wikipedia.org/wiki/Plug_and_play)功能指的是通过操作系统协调自动分配设备上的资源，例如：中断号、I/O 地址、DMA通道、设备物理内存等。

#### PnP相关组件

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/9DE1D84EF43F4941A19C7FABAF83B87A/15266)

注意：注册表维护已安装的硬件和即插即用设备软件的数据库。注册表的内容帮助驱动程序和其他组件识别和定位设备使用的资源。

#### 即插即用IRP

转发给底层驱动，处理各种 PnP IRP 子功能请求。表13-1 列出了各个子功能代码。

WDM 驱动与 NT 驱动最大的不同是引入了 PNP 机制。

IRP_MJ_PNP 与其他的 IRP 不同的是，它不是来自于应用程序，而是当设备被插入、拔出或被系统加载时，由 I/O 管理器向驱动程序发送 IRP_MJ_PNP。随后，它将被转发给底层设备对象，由底层总线驱动去处理。这样的设计，使得底层的修改不影响上层的逻辑驱动。  


#### 通过设备接口寻找设备

在 WDM 驱动程序中，一般都是通过设备接口来定位一个驱动程序。同时，为了兼容 NT 驱动程序，也可以使用设备名和符号链接来定位设备。

##### 设备接口

设备接口是一组全局标识（GUID），由 128 位的数字组成，并能保证在全球范围内不冲突。

引入设备接口主要是避免设备名冲突。

[IoRegisterDeviceInterface](https://blog.csdn.net/chenyujing1234/article/details/7843709) 内核函数负责注册设备接口。

##### 应用程序寻找设备接口

在应用程序寻找设备，是通过设备接口和设备号决定的。这里的设备号是指具有相同驱动程序的设备的编号。


```
HANDLE GetDeviceViaInterface( GUID* pGuid, DWORD instance)
{
	// Get handle to relevant device information set
	HDEVINFO info = SetupDiGetClassDevs(pGuid, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);
	if(info==INVALID_HANDLE_VALUE)
	{
		printf("No HDEVINFO available for this GUID\n");
		return NULL;
	}

	// Get interface data for the requested instance
	SP_INTERFACE_DEVICE_DATA ifdata;
	ifdata.cbSize = sizeof(ifdata);
	if(!SetupDiEnumDeviceInterfaces(info, NULL, pGuid, instance, &ifdata))
	{
		printf("No SP_INTERFACE_DEVICE_DATA available for this GUID instance\n");
		SetupDiDestroyDeviceInfoList(info);
		return NULL;
	}

	// Get size of symbolic link name
	DWORD ReqLen;
	SetupDiGetDeviceInterfaceDetail(info, &ifdata, NULL, 0, &ReqLen, NULL);
	PSP_INTERFACE_DEVICE_DETAIL_DATA ifDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA)(new char[ReqLen]);
	if( ifDetail==NULL)
	{
		SetupDiDestroyDeviceInfoList(info);
		return NULL;
	}

	// Get symbolic link name
	ifDetail->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);
	if( !SetupDiGetDeviceInterfaceDetail(info, &ifdata, ifDetail, ReqLen, NULL, NULL))
	{
		SetupDiDestroyDeviceInfoList(info);
		delete ifDetail;
		return NULL;
	}

	printf("Symbolic link is %s\n",ifDetail->DevicePath);
	// Open file
	HANDLE rv = CreateFile( ifDetail->DevicePath, 
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if( rv==INVALID_HANDLE_VALUE) rv = NULL;

	delete ifDetail;
	SetupDiDestroyDeviceInfoList(info);
	return rv;
}
```

##### 查看设备接口

通过 WinObj 或 DeviceTree 可以查看设备接口。


#### 实验一

本章的实验一演示了 WDM 驱动程序的 PnP 功能，其中包含了一个测试程序和一个驱动程序。

#### 测试程序

可以新建 WIN32 CONSOLE 工程，将这个测试程序嵌入，需要注意的是，guid.h 和 Ioctls.h 两个文件都位于驱动程序中，也就是说，为了统一维护，复用了驱动程序的声明文件。前者定义的是设备接口 GUID，后者是 I/O 控制码。

这个新建的 WIN32 CONSOLE 工程一开始编译的时候会报链接错误：LINK2001 和 [LINK1120](https://blog.csdn.net/albertsh/article/details/72818113)：无法解析的外部符号。

参考网上博客可知，LINK1120 表示：
> 首先说这是一个链接错误而不是编译错误，造成这种问题的根本原因就是找得到函数的声明，但是找不到函数的实现，这是最根本的，具体的表现形式有很多.

在看具体报错的几个导出 API ，都是驱动相关的函数。很明显，这些函数的头文件可以找到，但是没有包含他们的库文件。

[setupdigetclassdevs link error](https://stackoverflow.com/questions/33640791/setupapi-setupdi-functions-dont-link) 这个帖子告诉我们，需要将 setupapi.lib 这个库文件添加到附加依赖项中。


##### 驱动程序

驱动程序可以复用 CH1 或 CH3 中的 HelloWDM 工程的 makefile 和 Sources 文件。

比较本章的驱动程序和 CH1 中的驱动程序可以发现：  
1. 它们的 INF 文件相同，都包含 GUID
2. 头文件中的设备扩展不同，本章没有符号链接和设备名，而代替为设备接口（interfaceName）
3. cpp 中主要是增加了 GUID 和 PnP 子 IRP 号。

可以观察 GUID 到 interfaceName 的注册过程。

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/366F5384384F4613B8B8197B8C227CB8/15392)

日志中高亮的部分就是 interfaceName 。它的各个部分以井号分割，含义大概是：

header 1 | header 2
---|---
\\?\ROOT | 设备挂载路径，直接挂载 ROOT 总线上
UNKNOWN | DeviceName，未设（NULL）
0000 | 设备号
｛...｝| GUID

另外，在应用程序中打印显示“符号链接”为“\”.



### 再论IRP

> 本章将相关irp的操作做了进一步的总结。首先是转发irp，归纳了几种不同的方式。其次总结了创建irp的几种不同方法。创建irp总的来说分为创建同步irp和创建异步irp。对于创建同步irp，操作比较简单，i/o管理器会负责回收irp的相关内存，但是使用不够灵活。对于创建异步irp，操作比较复杂，程序员需要自己负责对irp及相关内存回收，但使用十分灵活。

本章是对 CH11 “驱动程序调用驱动程序” 和 CH12 "分层驱动程序" 两章的 IRP 相关内容的总结。其中，创建 IRP 部分可以结合 CH11 来看，而转发 IRP 部分需要结合 CH12 来看。


#### 转发IRP

转发 IRP 分为几种情况：直接转发、转发并等待、转发并设置“完成例程”。此外，还可以挂起 IRP ，并设置 StartIo 例程和直接完成 IRP。

这些在前面的章节中都已讲解过了，这一章把它们归集到一起来回顾。其中，转发和完成例程，可以参考 CH12 的几个实验，而 StartIo 可以参考 CH9 。


#### 创建IRP

> 创建 IRP 分为创建同步 IRP 和创建异步 IRP。  

同步 IRP 在调用 IoCallDriver 后，会一直阻塞直到 IRP 完成。异步 IRP 可以设置完成例程，在完成例程中获取 IRP 的完成情况。

##### 创建同步IRP

[IoBuildDeviceIoControlRequest](https://blog.csdn.net/gxfan/article/details/2900095IoBuildDeviceIoControlRequest) 创建同步 IRP 。

参考 CH11 实验5


##### 创建有超时的 IOCTL IRP

这个的设计机制比较巧妙，在前面的章节并没有相关的内容，主要用于同步IRP。因为同步IRP 需要等到 IoCallDriver 返回才继续执行后面的代码，设计超时机制，就非常重要了。


```
NTSTATUS MakeSynchronousIoctlWithTimeout(
    IN PDEVICE_OBJECT TopOfDeviceStack,
	IN ULONG IoctlControlCode,
	PVOID InputBuffer,
	ULONG InputBufferLength,
	PVOID OutputBuffer,
	ULONG OutputBufferLength,
	IN ULONG Milliseconds	
	) 
{
	NTSTATUS status;
	PIRP irp;
	KEVENT event;
	IO_STATUS_BLOCK ioStatus;
	LARGE_INTEGER dueTime;
	IRPLOCK lock;
	
	// 初始化同步事件
	KeInitializeEvent(&event,NotificationEvent,FALSE);
	
	//创建同步IRP
	irp = IoBuildDeviceIoControlRequest(
	    IoctlControlCode,
		TopOfDeviceStack,
		InputBuffer,
		InputBufferLength,
		OutputBuffer,
		OutputBufferLength,
		FALSE,    // External ioctl
	    &event,
		&ioStatus);
		
	// 判断 IRP 是否为空
	
	if ( irp == NULL) {
	    return STATUS_INSUFFICIENT_RESOURCES;
	}
	
	lock = IRPLOCK_CANCELABLE;
	
	// 设置完成例程
	IoSetCompletionRoutine(
	    irp,
		MakeSynchronousIoctlWithTimeoutCompletion,
		&lock,
		TRUE,
		TRUE,
		TRUE
		);
		
	// 调用底层驱动
	status = IoCallDriver(TopOfDeviceStack,irp);
	
	// 判断IRP是否被挂起
	if (status == STATUS_PENDING) {
	    // 定义延时 1 ms
		dueTime.QuadPart = -10000 * Milliseconds;

		//如果DriverA的派遣函数没有完成IRP，则等待IRP完成
       status = KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            &dueTime
							);
							
		// 如果是超时
		if (status == STATUS_TIMEOUT) {
		    if (InterlockedExchange((PVOID)&lock, IRPLOCK_CANCEL_STARTED)
			    == IRPLOCK_CANCELABLE) {
				// 取消 IRP
				IoCancelIrp(irp);
				
				if (InterlockedExchange((PVOID)&lock, IRPLOCK_CANCEL_COMPLETE)
			    == IRPLOCK_COMPLETED) {
				    // 结束 IRP
				    IoCompleteRequest(irp, IO_NO_INCREMENT);
				}
			}
			
			// 等待同步事件
			KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            NULL
							);
							
			// 设置IRP 完成状态
			ioStatus.Status = status;    // return STATUS_TIMEOUT
		} else {
		    status = ioStatus.Status;
		}
		
	}
	
	return status;
}

NTSTATUS MakeSynchronousIoctlWithTimeoutCompletion(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp,
	IN PVOID Context
	) 
{
    PLONG lock;
	lock = (PLONG)Context;
	if (InterlockedExchange((PVOID)&lock, IRPLOCK_CANCEL_COMPLETE)
	    == IRPLOCK_STARTED) {
		return STATUR_MORE_PROCESSING_REQUIRED;
	}
	
	return STATUS_CONTINUE_COMPLETION;
}
```






[IoBuildAsynchronousFsdRequest](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildasynchronousfsdrequest) 创建异步 IRP ，并在完成例程中释放内存资源。

IoAllocateIrp 也是创建异步 IRP 。


### 过滤驱动程序

> 本章主要介绍wdm和nt式过滤驱动程序开发。过滤驱动程序开发十分灵活，可以修改已有驱动程序的功能，也可以对数据进行过滤加密。另外，利用过滤驱动程序还能编写出很多具有相当功能强大的程序来。

过滤驱动程序分为两类：


header 1 | header 2
---|---
高层过滤驱动程序 | High FiDo，挂载在 FDO 之上
低层过滤驱动程序 | Low FiDO，挂载在 PDO 之上，介于 FDO 与 PDO 之间



#### 文件过滤驱动程序

文件过滤驱动程序将自己挂载在磁盘驱动之上，拦截全部发往磁盘驱动的IRP，并有选择地过滤这些IRP。

##### 过滤驱动程序的模型

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/EAC168D2950242E5A68A8CA1773F21B4/15529)

为了让编写的过滤驱动能让 U 盘变为只读状态，可以在 DISK.sys 和 USBSTOR.sys 之间建立一个过滤驱动。




##### 过滤驱动程序的入口函数

需要在入口函数中指定需要过滤的IRP 的派遣函数。


##### U盘过滤驱动程序

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/08FAD34A1A344AF6B8B987382C7F2637/15543)


##### FileFilter实验

复用 CH1 HelloWDM 的 makefile 和 sources 文件，修改 TargetName，如下，参考 CH3 ，Sources 文件新行前用的是 tab，不是空格


```
TARGETNAME=MyFilter
TARGETTYPE=DRIVER
DRIVERTYPE=WDM
TARGETPATH=OBJ

INCLUDES=$(BASEDIR)\inc;\
         $(BASEDIR)\inc\ddk;\

SOURCES=DriverEntry.cpp	\
	stddcls.cpp
```

一开始会报编译错误，C4335，参考[compiling error c4335](https://stackoverflow.com/questions/16345477/error-c4335-when-compile-c-project-vs2012) 修改对应的文件格式，即可。

然后会报一个编译宏的错误，主要是文件格式转换导致宏定义换行时，增加了空行，使得换行符失效，删除空行即可。

后续还有一些相关的编译错误，于是重新编辑 stddcls.h 文件如下：


```
// stddcls.h -- Precompiled headers for WDM drivers
// Copyright (C) 1999 by Walter Oney
// All rights reserved

#ifdef __cplusplus
extern "C"
{
#endif

#pragma warning(disable:4201)	// nameless struct/union
#define DEPRECATE_DDK_FUNCTIONS 1

#include <wdm.h>
#include <stdio.h>
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
```

##### 磁盘命令过滤

磁盘命令过滤的关键是拦截 IRP_MJ_SCSI，它是 IRP_INTERNAL_DEVICE_CONTROL 的一个别名。在 DISK.sys 和 USBSTOR.sys 之间传递的是标准的 SCSI 指令。  

在 IRP_MJ_SCSI 的派遣函数中，在将该 IRP 发给底层前，先设置完成例程，在完成例程中修改底层驱动的所做的处理。


#### nt式过滤驱动程序

上一节介绍的是 WDM 过滤驱动，安装它时需要修改注册表。本机介绍的 NT 式过滤驱动，无须修改注册表。它通过驱动名直接寻找到需要过滤的驱动设备的指针，然后将自己挂载在上面。

##### 键盘驱动设备对象

通过 WinObj.exe 可以查看键盘驱动的设备对象为 Device\KeyboardClass0

##### ctrl2cap

实验 ctrl2cap 是资深 Windows 内核专家 Mark Russionovich 编写的一个键盘过滤驱动程序。它也是在完成例程中记录 IRP_MJ_READ 获取的值，也可以修改这个值。  

需要注意的是，在进行这个实验的时候，我又踩了一次坑，大致过程如下：  
>我一开始是通过“远程桌面”连接到测试机，可以观察到 ctrl2cap 驱动已挂载成功，但是，在 txt 中测试打字，debugview 未捕获到任何键盘记录。  
然后，我在每个“派遣函数”中增加入口打印信息，debugview 还是没有捕获任何派遣函数调用的记录。  
通过 winobj.exe 观察发现，键盘设备对象除了 KeyboardClass0 ，还有一个类似的 KeyboardClass1，于是切换了 device name，再次实验，依然没有记录。  
这个问题卡了一个多星期，某天突然想到了，是不是 Remote Desktop 并没有真正通过键盘与 OS 交互？  
于是，重新实验，不使用 Remote Desktop，而是使用 VMWare 客户端直接登录。这次，能够看到键盘的敲击记录啦。

![](https://img-blog.csdnimg.cn/20190221095525400.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NhZ2l0dGFyaXVzX1dhcnJpb3I=,size_16,color_FFFFFF,t_70)

### 高级调试技巧

本章将介绍一些windows开发驱动的高级调试技巧。主要是使用 WinDbg.exe 进行 dump 文件调试和双机内核调试。这方面的资料网上比较多，建议遇到问题直接 google 。

