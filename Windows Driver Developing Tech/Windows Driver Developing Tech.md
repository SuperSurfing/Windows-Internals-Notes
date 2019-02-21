#### Abstract
&emsp;&emsp;����Ƽ� Windows ���������������飬��ǿ���Ƽ���Windows��������������⡷���������ڳ����ʱ����磬�������ᵽ�ĺܶ๤�ߺͻ������Ѳ����û��Ҳ������������Ѽ��˴󲿷ֵĹ��ߣ����� win10X64 �ϰ�װ������������ win7x86 �Ͻ���ʵ�飬�˹��˲���ʵ�ʱ���Ͳ����������Ŀӡ����⣬����Ҳ������½ڵ��ص�������ܽᣬȫ��Ŀ¼���£�

- [ȫ�鵼��](#ȫ�鵼��)
- [�����͵���](#�����͵���)
  - [������������](#������������)
  - [WinDbg](#windbg)
- [CH2 Windows���������Ļ�������](#������صĲ���ϵͳ֪ʶ)
- [CH3 �������뻷�����á���װ�͵���](#��������ı���͵���)
  - [HelloDDK](#helloddk)
  - [LoadNTDriver](#loadntdriver)
  - [HelloWDM](#hellowdm)
    - [SubKey](#subkey)
    - [INF](#inf)
    - [��װHelloWDM](#��װhellowdm)
- [CH4 ��������Ļ����ṹ](#��������Ļ����ṹ)
  - [������������ݽṹ](#������������ݽṹ)
    - [DRIVER_OBJECT](#��������)
    - [DEVICE_OBJECT](#�豸����)
    - [DEVICE_EXTENSION](#�豸��չ)
  - [��������ļ��ع���](#��������ļ��ع���)
    - [�豸�����������](#�豸�����������)
    - [WinObj�۲�����������豸����](#winobj�۲�����������豸����)
  - [WDM�����Ļ����ṹ](#wdm�����Ļ����ṹ)
    - [PDO and FDO](#pdo_and_fdo)
    - [Major IRP and Minor IRP](#major_irp_and_minor_irp)
  - [�����Ĳ�νṹ](#�����Ĳ�νṹ)
    - [�豸�����ջ](#�豸�����ջ)
    - [ˮƽ����](#ˮƽ����)
  - [ʵ��](#ʵ��)
- [CH5 Windows�ڴ����](#windows�ڴ����)
  - [�ڴ����Ļ�������](#�ڴ����Ļ�������)
  - [ͨ������](#ͨ������)
  - [Lookaside](#lookaside)
  - [�ں��ڴ��������](#�ں��ڴ��������)
- [CH6 Windows�ں˺���](#windows�ں˺���)
- [CH7 ��ǲ����](#��ǲ����)
  - [IRP����ǲ����](#irp����ǲ����)
  - [��������ʽ��д��ֱ�Ӷ�д](#��������ʽ��д��ֱ�Ӷ�д)
  - [DeviceIoControl](#deviceiocontrol)
- [CH8 ���������ͬ������](#���������ͬ������)
  - [ͬ�����첽](#ͬ�����첽)
  - [�ж����󼶱�](#�ж����󼶱�)
  - [������](#������)
  - [�ں�ģʽ�µ�ͬ������](#�ں�ģʽ�µ�ͬ������)
  - [����ͬ������](#����ͬ������)
- [CH9 IRP��ͬ��](#irp��ͬ��)
  - [ͬ���������첽������ԭ��](#ͬ���������첽������ԭ��)
  - [IRP��ͬ��������첽���](#irq��ͬ��������첽���)
  - [StartIO����](#startio����)
  - [�жϷ�������](#�жϷ�������)
  - [DPC����](#dpc����)
- [CH10 ��ʱ��](#��ʱ��)
  - [��ʱ����ʵ�ַ���һ](#��ʱ����ʵ�ַ���һ) 
  - [��ʱ����ʵ�ַ�����](#��ʱ����ʵ�ַ�����)
  - [���ֵȴ�](#���ֵȴ�)
  - [ʱ���ں˺���](#ʱ���ں˺���)
  - [IRP��ʱ����](#irp��ʱ����)
- [CH11 �����������������](#�����������������)
  - [���ļ������ʽ����](#���ļ������ʽ����)
  - [ͨ���豸ָ�����](#ͨ���豸ָ�����)
  - [��ȡ�豸ָ��ķ���](#��ȡ�豸ָ��ķ���)
- [CH12 �ֲ���������](#�ֲ���������)
  - [�ֲ������������](#�ֲ������������)
  - [�������](#�������)
  - [��irp�ֽ�ɶ��irp](#��irp�ֽ�ɶ��irp)
  - [wdm��������ܹ�](#wdm��������ܹ�)
- [CH13 ���弴��](#���弴��)
  - [���弴��IRP](#���弴��irp)
  - [ͨ���豸�ӿڣ�GUID��Ѱ���豸](#ͨ���豸�ӿ�Ѱ���豸)
  - [ʵ��һ](#ʵ��һ)
- [CH21 ����IRP](#����irp)
  - [ת��IRP](#ת��irp)
  - [����IRP](#����irp)
- [CH22 ������������](#������������)
  - [�ļ�������������](#�ļ�������������)
  - [ntʽ������������](#ntʽ������������)
- [CH23 �߼����Լ���](#�߼����Լ���)
  


### ȫ�鵼��

&emsp;&emsp;��Windows��������������⡷ȫ����ǳ�����Ϊ�ĸ����֣�����ƪ������ƪ��ʵ��ƪ�����ƪ�����Բο� [Ŀ¼�ṹ](https://www.jb51.net/books/256394.html)��

- ����ƪ
  - CH1 �����򵥵�����
  - CH2 Windows ���������Ļ�������
  - CH3 �������뻷�����á���װ�͵���
  - CH4 ��������Ļ����ṹ
  - CH5 Windows �ڴ����
  - CH6 Windows �ں˺���
  - CH7 ��ǲ����
- ����ƪ
  - CH8 ���������ͬ��
  - CH9 IRP��ͬ��
  - CH10 ��ʱ��
  - CH11 �������������������
  - CH12 �ֲ���������
  - CH13 ���弴�ã�PnP - [Plug and Play](https://en.wikipedia.org/wiki/Plug_and_play)��
- ʵ��ƪ
- ���ƪ
  - CH21 ����IRP
  - CH22 ������������
  - CH23 �߼����Լ���

  
### �����͵���

#### ������������

��Windows��������������⡷�͡�Windows�ں˰�ȫ��̡����׵� Driver Build ���߶��� WDK7600�������Դ� MSDN �����أ�Ҳ����ֱ�Ӵ������������أ�ѡ��Full Development Environment�� ��Ĭ��·����װ���ɣ��������û�����������

[WinDDK ���ذ�װ](https://infosys.beckhoff.com/english.php?content=../content/1033/tc3_c/54043195639122187.html&id=)

[DriverStudio ��װ����](https://blog.csdn.net/u012052268/article/details/53219441)


#### ������־����

����������־������ [sysinternals - DbgView.exe](https://docs.microsoft.com/en-us/sysinternals/downloads/debugview)��ͨ�� C ���� [KdPrint()](https://blog.csdn.net/whatday/article/details/9530723) ���������־����Ҫע����ǣ�KdPrint() ����־ֻ�� **Checked Build** �汾�вſɼ����� Free Build �汾���ɼ���  

���⣬Microsoft Ҳ�ṩ��һ�� Driver ��־���ơ��� [WPP + TraceView.exe](https://blog.csdn.net/Sagittarius_Warrior/article/details/51205607)���ʺ��� PDB �ļ�����־������

#### ��������״̬�۲칤��

Procexp.exe ���Թ۲�����������״̬�����⣬���� livekd.exe �� kd.exe��

[DriverView.exe](https://www.nirsoft.net/utils/driverview.html) ���ڹ۲�ϵͳ�Ѱ�װ��ȫ����������Ҳ����ʹ�� CMD - systeminfo ����鿴������Ϣ��


#### ������װ����

[KmdManager.exe](https://bbs.pediy.com/thread-176945.htm) ���������غͲ��Թ��ߣ�[Link](http://www.website.masmforum.com/tutorials/kmdtute/index.html)������ͼ��ʾ�����ṩ��������ע�ᡢ��������net start ***���ͷ������ IOControl �Ĺ��ܡ�   

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/4283944C5E88492798B6D513B24B23FE/13082)  

[srvinstw.exe](http://xiazai.zol.com.cn/detail/45/442282.shtml) �ǡ�Windows�ں˰�ȫ��̡��Ƽ���һ���������ع��ߣ���������ϸ�Ĳ������衣

��Ҫע����ǣ�KmdManager.exe �� srvinstw.exe ����Ҫʹ�á�**����ԱȨ��**�����С�

���� Driver Studio��Windows ������װ��ѡ [devcon.exe](https://blog.csdn.net/Sagittarius_Warrior/article/details/51262671)�����Ǹ��� Windows WDK �е�һ�����ߡ�


#### WinDbg


### ������صĲ���ϵͳ֪ʶ

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/2EB720E4D9AD482A9A0CECEA2BEA14D9/14557)

���У�native api ��Ӧ�� PE �� ntdll.dll���� API һ�㶼�� Nt��ͷ������ϵͳ����������Ӧ�� PE �� ntosknrl.exe���� API һ�㶼�� Zw ��ͷ�����⣬����ͨ�� Dependency walker.exe �鿴�䵼��������

[������⿴SSDT](https://blog.csdn.net/vangoals/article/details/4359042)



### ��������ı���͵���

��һ����Ҫ���� Windows ��������Ŀ������������������װ������������ԣ���Ҫ�ο���Windows��������������⡷�ĵ����º͡�Windows�ں˰�ȫ��̡���һ�¡����У�examples �õ���ǰ�ߵģ������������͹��߶�ʹ�õ��Ǻ��ߵġ�

#### HelloDDK

HelloDDK ��һ�� NT������Ҳ����˵������һ���� PnP ����������ϵͳ�������ʽ���ڣ��������豸��ء�

1. ��װ�� WDK7600������ ��Windows Driver Kits - x86 Checked Build Environment�� ����ڣ�������Դ��Ŀ¼��
2. ���� ��build�� ָ����� sys �ļ���
3. ��Ŀ��������� srvinstw.exe ����װ�÷���������
4. cmd - net start/stop helloddk ������/ֹͣ�÷���

��Ҫע�⣺
1. ��װ�÷���󣬿���������ע����п���

```
HKLM\SYSTEM\CurrentControlSet\services\HelloDDK
```
�ӡ�Windows��������������⡷�����¿�֪������װ�Ĺ��̣�ʵ���Ͼ���дע���Ĺ��̡�
2. �� DbgView.exe �۲��ʱ����Ҫ������ԱȨ�����С��Ϳ�����Capture Kernel + Enable Verbose Kernel Output����
3. ��Ҫ���������� DeviceManager �п������°�װ�ġ��Ǽ��弴���豸����
4. 

#### LoadNTDriver

LoadNTDriver ������ʾ����ε��� SCM ����/ж�� NT �������򣬸ó���Դ��(main.cpp)���ɷŵ�һ�� VS2017 �� win32 console Ӧ�ó����� build�������޸����¼�����

1. Unicode ��Ϊ �����ֽ��ַ�����
2. LoadNTDriver �� UnloadNTDriver �γ����� const ����
3. getch -> _getch
4. ���Խ�**����ʱ**��Ϊ MT
5. 


#### HelloWDM

##### SubKey

HelloWDM ��һ�� PnP ��������ע���ʱ��ᴴ�������ӽ���

Hardware�ӽ�

```
HKLM\SYSTEM\CurrentControlSet\Enum
```

Class�ӽ�

```
HKLM\SYSTEM\CurrentControlSet\Control\Class
```

service�ӽ�

```
HKLM\SYSTEM\CurrentControlSet\services\
```

##### INF

�� NT ������ͬ��WDM ������ע�����Ϣ���豸��Ϣ������ INF �ļ��ж���ġ���Windows��������������⡷CH1&CH3 ���ж� INF �ļ�����ϸ�Ľ��ܡ�

[MSDN - INF](https://docs.microsoft.com/zh-cn/windows-hardware/drivers/install/overview-of-inf-files)

[INF �ļ��Ľ�](https://blog.csdn.net/whatday/article/details/9382031)


##### ��װHelloWDM

ͨ�� DeviceMgr - root ѡ�񡰰�װ��ʱӲ����  - �ֶ���װ - �Ӵ��̰�װ��

��װ���̵���־���¼�� C:\Windows\INF\Setupapi.dev.log �ļ��С�

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/3620E36E57C24DC0858703D7A48D0763/13162)


##### WDM��������Ľṹ

��Windows��������������⡷CH1���ؽ����� HelloWDM ��������ÿһ�е����壬������½ڸ�����չ������ļ���ϸ�ڡ�



### ��������Ļ����ṹ

#### ������������ݽṹ

Windows����������Ȼ�� C ����ʵ�ֵģ����������ǲ����� OOP �ı��ģʽ���������ݽṹ���� OOP ����Ҫ�Ļ�ʯ��ͨ�׵�˵�����ݽṹ��struct������Windows��������Ķ�������塣

##### ��������

OOP ���ģʽ�У�һ���������һ��ʵ���������ԣ�һ����������ʹ���һ����������

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/92305AAE956B4E72B4FF3625E0953EEB/13203)

##### �豸����

�豸���������������һ���Ӷ�������Ӧһ���豸��

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

��Ҫ�ر�ע����� **NextDevice** �� **AttachedDevice** ��NextDevice ��ˮƽ�������豸����������AttachedDevice���Ƿֲ������д�ֱ���ص��豸�������豸������������


##### �豸��չ

����������У�Ӧ�þ�������ʹ��ȫ�ֱ������豸�����¼��ͨ�á��豸����Ϣ�����������⡱����Ϣ������豸��չ���ṹ�壩�С������ԣ�����Ա�Զ����һЩ�������������豸��չ���ṹ�壩�С�


#### ��������ļ��ع���

��һ������������������ SYSTEM ���̼��صĹ��̣���������Ĵ������豸����Ĵ�����֪ʶ���ǳ���Ҫ��

##### �豸�����������

ǰ��ֻ���ں�ģʽ�¿����豸�������൱��ǰ�ߵı�������һ�ڶ�������֪ʶ���к���ϸ�Ľ��ܣ��ǳ�������


##### WinObj�۲�����������豸����

��һ����󻹽���������� sysinternals - winobj.exe �鿴�豸���������������Ҫ���������������豸����ͷ������ӡ�

���⣬Ҳ������ [DeviceTree.exe](https://www.osronline.com/article.cfm?article=97) �鿴��Щ��Ϣ��


#### WDM�����Ļ����ṹ

WDM �������һ���豸������Ҫ���������豸���󣨴�ֱ�ṹ������ PDO �� FDO��

##### PDO_and_FDO

����⵽�豸ʱ��PDO �������������򴴽���FDO ���Զ�����������򴴽������ӵ� PDO �ϡ�

ע�⣺�������Ĳ�νṹ�У�**Խ����Ӳ���Ĳ�**��Խ���¡���


##### major_irp_and_minor_irp

IRP �ı��������ź͸������һ��ָ����������� IRP �����á�

#### �����Ĳ�νṹ

��ν�������Ĳ�νṹ����ʵ������ָ�豸����Ĳ�νṹ������ PDO �� FDO������ [DeviceTree.exe](https://www.osronline.com/article.cfm?article=97) ���Ժ������ع۲��豸����Ĳ�νṹ��

##### �豸�����ջ

�ײ��豸�������� DEVICE_OBJECT �е� AttachedDevice �����ϲ��豸������� AttachedDevice Ϊ�գ��򵽴ﶥ�㡣���߲��豸���������� DEVICE_EXTENSION ��¼�²���豸����Ҳ���ǣ�˫���ѯ����·����ͨ���ġ�

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/BFA9C3DCB1A64D3FBC373BE474F7966F/13298)


##### ˮƽ����

ͬһ���������󴴽��������豸����֮��Ĺ�ϵ����Ϊˮƽ�ṹ��

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/6CB73670FA0D4B678052297DE10DE844/13338)


#### ʵ��

��һ��ʵ������ԭ�е� HelloDDK ��������Ļ����ϣ�����һ��ˮƽ���豸���󣬿��Ը���ԭ�е� HelloDDK �е� makefile��Sources�ļ���Ҳ����ʹ��ԭ�ȵ� LoadNTDriver.exe ������в��ԡ�

�ڶ���ʵ������ԭ�е� HelloWDM ��������Ļ����ϣ����Ӵ�ֱ�豸�����ˮƽ�豸����Ĵ�ӡ��Ϣ�����Ը���ԭ�е� HelloWDM �е� makefile��Sources �� INF �ļ���


### Windows�ڴ����

��һ����Ҫ�����ڴ������Ļ���֪ʶ�����ں˱������Ҫע����ڴ����������

#### �ڴ����Ļ�������

�ڴ����Ļ�����������������ڴ�����ֶκͷ�ҳ���������ڴ������ַ�ռ�ӳ�䣩���ں�̬��ַ�ռ���û�̬��ַ�ռ䡢������������̵Ĺ�ϵ����ҳ�ڴ�ͷǷ�ҳ�ڴ档  
��Щ֪ʶ�ڡ�����ϵͳ���γ��н���ĸ�����ϸ����Windows��������������⡷�����˼򵥽��ܡ������ر���Ҫע����ǣ�  
1. Windows��������Ĳ�ͬ���̣�routines�������ڲ�ͬ�Ľ��̡�DriverEntry��AddDevice������SYSTEM�����С��������� IRP_MJ_READ �� IPR_MJ_WRITE ����ǲ����������Ӧ�ó��������ġ��У�ֻ�ܷ��ʶ�Ӧ�Ľ��̵������ڴ��ַ��
2. ͨ����ӡ log�����Բ鿴��ǰ�������ڵĽ��̣�PsGetCurrentProcess����
3. ��������ж����󼶱��� DISPATCH_LEVEL ֮��ʱ������DISPATCH_LEVEL��������ֻ��ʹ�÷Ƿ�ҳ�ڴ棬���� BSOD��


#### ͨ������

������ϵͳ���γ��е� ucore Ҳ����ʹ���ˡ�ͨ������������һ��˫������һ����Ϊ�ӽṹ��Ƕ�뵽�������󣨽ṹ�壩�У��Ӷ�ʵ�ֿ粻ͬ����Ĵ�����

Windows �ں��е�����ṹ���£�Blinkָ��ǰһ������Before����Flinkָ���һ������Follow����

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/0FF42E71603E4EA4AE3E20BC40CB2162/13466)

��Windows��������������⡷�� Windows �����е���������ϸ�Ĳ�������ɾ�Ĳ飩���ܺ���ص�ʵ�飬�ʺϱ��ʱ�ο���

#### Lookaside

Lookaside �ṹ��Ҫ��Ϊ�˱����ں��ڴ���Ƭ������Ƶģ����Խ�������Ϊ�ں��ڴ�أ���������


```
#pragma INITCODE
VOID LookasideTest() 
{
	//��ʼ��Lookaside����
	PAGED_LOOKASIDE_LIST pageList;
	ExInitializePagedLookasideList(&pageList,NULL,NULL,0,sizeof(MYDATASTRUCT),'1234',0);

#define ARRAY_NUMBER 50
	PMYDATASTRUCT MyObjectArray[ARRAY_NUMBER];
	//ģ��Ƶ�������ڴ�
	for (int i=0;i<ARRAY_NUMBER;i++)
	{
		MyObjectArray[i] = (PMYDATASTRUCT)ExAllocateFromPagedLookasideList(&pageList);
	}

	//ģ��Ƶ�������ڴ�
	for (i=0;i<ARRAY_NUMBER;i++)
	{
		ExFreeToPagedLookasideList(&pageList,MyObjectArray[i]);
		MyObjectArray[i] = NULL;
	}

	ExDeletePagedLookasideList(&pageList);
	//ɾ��Lookaside����
}
```

#### �ں��ڴ��������

��Windows��������������⡷������ RtlCopyMemory ���ں��ڴ�����������÷����ⷽ����Բο� MSDN ���ĵ���

���У�P136 ��ʾ������� Dependency Walker.exe �鿴����������PE - ntosknrl.exe �ĵ��������������õ��ĵ���������ȫ���ĵ���������


### Windows�ں˺���

��һ����Ҫ�����ں��г��õĺ�����������
- �ַ���������
- �ļ���д����
- ע����д����
- 

��Ȼ����Щ�����Բ� DDK �ĵ��� MSDN �ĵ�����Щ�����󲿷ֶ��� ntosknrl.exe �У�����ͨ�� Dependency Walker.exe ���в鿴��


### ��ǲ����

CH2.3 ����Ӧ�ó�����������һ���Ѿ���������һ�������̣�


```
graph LR
App --> win32��ϵͳ 
win32��ϵͳ --> NativeAPI
NativeAPI --> ϵͳ������
ϵͳ������ --> IO������
IO������ --> ����������ǲ����
```

1. �� NativeAPI �� ��ϵͳ�������� ͨ�������жϡ�ʵ����**���û�ģʽ**��**�ں�ģʽ**���л���
2. IRP ���� IO ���������������͸���������ġ�
3. �����������Ҫְ����Ǵ��� IO ����
4. ��ǲ����ʵ���Ͼ��ǡ�����-��Ӧ��ģʽ�е�**��Ӧ����**��


#### IRP����ǲ����

##### IRP

IRP - I/O Request Package��ʵ������ Windows �ں��е�һ�����ݽṹ�����󣩡��ϲ�Ӧ�ó��������ϵͳ���� I/O ���󣬲���ϵͳ����Ҫ�� I/O ���������� I/O ����ת��Ϊ IRP ���͸���Ӧ��������������������� IRP �����ͷ������ͬ����ǲ�������д���

IRP ��һ���ܸ��ӵ����ݽṹ������ MajorFunction �� MinoreFunction ��������������������ԡ�

�ο� HelloWDM �� DriverEntry ��Դ�룬���Է��� DriverObject ��һ������ָ������ MajorFunction��ͨ������������飬���Խ� IRP ����������ǲ��������������ע�⣬MajorFunction ��**����ָ������**��

��ͬ�� I/O �����Ӧ��ͬ�� IRP ���ͣ�����ͨ��һ������г���ȫ���� IRP ���͡�  
[IRP ����](https://msdn.microsoft.com/zh-cn/us_en/data/ff550694)  

##### ��ǲ����

P189 ͨ�� ReadFile �����ĵ��ù��̣��������ǲ��������δ���ͷ���Ӧ�ó������ I/O ����ġ�

##### IRP��ֱת��

IRP�ȷ��͵����� DeviceObject�������û�н��� IRP �����������²��豸����ת�������� IO_STACK_LOCATION �ṹ����¼��Ӧ�豸�����㣩�еĲ�������Ȼ��IRP ά����һ�� IO_STACK_LOCATION �ṹ�����顣

����ͨ��һ��ʵ����ʾ����δ�ӡ IRP ����Ϣ����Դ�� DispatchTest - NTDriver��

���⣬Ҳ����ͨ�� IRPTrace.exe ���� IRP ��


#### ��������ʽ��д��ֱ�Ӷ�д

�������򴴽����豸һ�������ֶ�д��ʽ����������ʽ��д��ֱ�Ӷ�д�����������У����õ��ǡ���������ʽ��д���͡�ֱ�Ӷ�д���������ڴ����豸��IoCreateDevice�������豸����� Flags ����ָ����

��������ʽ��дʱ���ں˻Ḵ���û�̬�� buffer ���ݵ� IRP ������ AssociatedIrp.SystemBuffer �У���ֱ�Ӷ�д�򲻸������ݣ�����ֱ�������û�̬�� buffer����ֹ�����л���Ȼ��ͨ�� MDL ��¼��� buffer�������������ַ��ӳ�䡣ע�⣺��� buffer ָ���� output buffer ��

##### MDL

ֱ�ӷ�ʽ��д�豸ʱ������ϵͳ������ӳ�佫�û�ģʽ�µĻ�������ס������ MDL ��¼����ڴ棬Ȼ���ں�ģʽ���ٽ��������ַ��ӳ�䡣  

MDL ��Ҫ��¼����ֵ����� buffer �Ĵ�С��mdl->ByteCount����buffer ����ҳ��ַ��mdl->StartVa������� buffer ����ҳ��ƫ������mdl->ByteOffset�������ǿ���ͨ�����¼������ã�  

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
		//MDL�ĳ���Ӧ�úͶ�������ȣ�����ò���Ӧ����Ϊ���ɹ�
		pIrp->IoStatus.Information = 0;
		status = STATUS_UNSUCCESSFUL;
	}else
	{
		//��MmGetSystemAddressForMdlSafe�õ�MDL���ں�ģʽ�µ�ӳ��
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

ʵ�� MDL_Test �ֱ��ӡ��Ӧ��ģʽ�µ� buffer ��ַ���ں�ģʽ����ӳ���� buffer ��ַ��Ҫ�����˽� MDL �������Ķ� CH12.3 IRP �ֽ⡣


#### DeviceIoControl

DeviceIoControl ��һ������� I/O ������������һ�� I/O ������ͬʱ����豸�Ķ�д������ͬ���أ���Ҳ�����ֿ��Ʒ�ʽ��



### ���������ͬ������

���½��������������г��õ�ͬ������취�����ҽ��ں�ģʽ�µ�ͬ�����������û�ģʽ�µ�ͬ�����������˱Ƚϡ����⣬���»��������ж����󼶡���������ͬ��������ơ�

#### ͬ�����첽

##### �������벻������

������ִ�н���Ƿ���ִ��˳����ء�

���ڡ�ͬ�����첽������òο���Windows���ı�̡�CH10 �첽�豸I/O��������ĸ�����ϸ��

#### �ж����󼶱�

##### IRQL

Windows ���жϷ�Ϊ������жϡ��͡�Ӳ���жϡ�����ͳһӳ���ˡ��ж����󼶱𡱣�IRQL����ͬ�����ƺܴ�̶��������� IRQL ��

����ж��� ��int n�� ���ָ���������Ӳ���жϣ��ֳ�Ϊ���ⲿ�жϡ������ⲿ�豸���𣬾����жϿ���������PIC�������͸� CPU ��

ͨ����DeviceMgr�� - �鿴 - ������������Դ�����Բ鿴ϵͳ�еĸ����жϡ�

> �ԡ����Ǹ��֡�������ս�Ŀ����ȡ��жϡ��͡��ж����󼶱𡱣�  
���˵��̨��CPU�������˾��ǵ��Ƚ��̡�����������������̨���ԣ�Ȼ���Ÿ�λ���֣����̣���̨�ݳ���  
ͻȻ������̨����Ļ���岥һ����棬������岥��ʵ���Ͼ��ǡ�����жϡ�����ʵ����Ҳ��д�ھ�Ŀ�еģ����仰˵��������жϡ���int n��Ҳ��д�ڳ����еġ�  
����Ŀ�����У�ͻȻ��̨����Ļ�����ˣ����ʱ�򣬾���Ҫ��ͣ��Ŀ���빤����Ա����̨��ά�޴���Ļ��������Ļ���ˡ�ʵ���Ͼ��ǡ�Ӳ���жϡ���  
�����ά�޴���Ļ��ʱ�򣬲�С�ĵ�·��·����̨����ˣ����ʱ�򣬾͵���ͣά�ޣ�Ȼ����ͬ־������𡣺���Ȼ������̨����ˡ��ȡ�����Ļ���ˡ����ж����󼶱�ߡ�


![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/FA99BF72C55B4A57B365F6BD2F0A4BF2/13762)

�û�ģʽ�Ĵ�����������͵� PASSIVE_LEVEL ���𣬶���������� DriverEntry, DispatchFunction, AddDevice ��һ��Ҳ������ PASSIVE_LEVEL ���𣬱�Ҫʱ���ǿ��������� DISPATCH_LEVEL ��

Windwos �����̵߳��ȵ������������ DISPATCH_LEVEL ��

���ں�ģʽ�£�����ͨ�� KeGetCurrentIrql ������ȡ��ǰ�� IRQL ��


##### IRQL���߳����ȼ�

�߳����ȼ������Ӧ�ó�����ԣ���Ӧ�ó��������� PASSIVE_LEVEL ����

##### IRQL���ڴ��ҳ

���ڵ��ڻ���� DISPATCH_LEVEL ����ĳ�����ʹ�÷�ҳ�ڴ档��������� StartIO ���̡�DPC ���̡��жϷ������̶������� DISPATCH_LEVEL ���߸��ߵ� IRQL �������Ƕ�����ʹ�÷�ҳ�ڴ档

##### IRQL�������뽵��


header 1 | header 2
---|---
KeGetCurrentIrql | ��ȡ��ǰ IRQL
KeRaiseIrql | ������ǰ IRQL
KeLowerIrql | ���͵�ǰ IRQL


#### ������

Spin Lock �����ں�ͬ������Ҫ�Ǹ���ǲ����֮���ͬ����


#### �ں�ģʽ�µ�ͬ������

��һ�ڽ�����������ں�ģʽ�¿��̺߳ͽ����߳�ͬ���ġ�

##### �û�ģʽͬ������

�û�ģʽ�µ�ͬ�����������Event���¼���, Mutex�������壩�� Semaphone���źŵƣ��ȣ�����ʵ�������ں�ģʽ�µ�ͬ������ķ�װ��

�����û�ģʽ�µ�ͬ������Windows���ı�̡�һ�齲��ĸ���ϸ�����л��������ؼ�������Critical Section���ȷ��ں˶����ͬ��������

##### �ں�ģʽ�µ�ͬ������

�û�ģʽ�£��������������Ծ����handle��һ�� 32 λ����������ͬ������ģ����ں�ģʽ�£�����Ա���Ի����ʵ��ͬ������ָ�롣ÿ��ͬ���������ں��ж����Ӧһ�ֽṹ�塣

�ں�ģʽ�µĵȴ�������

- KeWaitForSingleObject
- KeWaitForMultipleObjects

##### ϵͳ�̺߳��û��߳�

�ں�ģʽ���� PsCreateSystemThread �������̣߳����ȿ��Դ����û��̣߳�Ҳ���Դ���ϵͳ�̡߳�

##### ʵ��

���ʵ�鲢û�и���Դ�룬���ǿ���ֱ�Ӱ������д��룬���ã������� HelloDDK ���̣�CH5����


```
#pragma PAGEDCODE
VOID SystemThread(IN PVOID pContext)
{
	KdPrint(("Enter SystemThread\n"));
	PEPROCESS pEProcess = IoGetCurrentProcess();
	PTSTR ProcessName = (PTSTR)((ULONG)pEProcess + 0x174);
	KdPrint(("This thread run in %s process !\n", ProcessName));
	
	// �����߳�
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
	
	// �����߳�
	KdPrint(("Leave MyProcessThread\n"));
	PsTerminateSystemThread(STATUS_SUCCESS);
}

#pragma PAGEDCODE
VOID CreateThread_Test()
{
	HANDLE hSystemThread, hMyThread;
	
	// ���������߳�
	NTSTATUS status = PsCreateSystemThread(&hSystemThread, 0, NULL, NULL, NULL, SystemThread, NULL);
	
	// ����ϵͳ�߳�
	status = PsCreateSystemThread(&hMyThread, 0, NULL, NtCurrentProcess(), NULL, MyProcessThread, NULL);
}
```

��Ҫע����ǣ��� win7 32bit ϵͳ�У���û�д�ӡ����ȷ�Ľ�������


##### Ӧ�ó��򴫵��¼�����������

- DeviceIoControl  
- ObReferenceObjectByHandle
- ObDereferenceObjcet

��ʵ����ͨ�� DeviceIoControl ���û�ģʽ�ľ���������������ںˣ�Ȼ��ͨ�� ObReferenceObjectByHandle �����ת��Ϊ�ں˶��󣨽ṹ�壩��ָ�롣  
> ��Ҫָ�����ǣ�������������صģ�Ҳ����ζ��һ�������еľ��ֻ���������������Ч��





##### ��������֮�䴫��ͬ������

����**����ͬ������**


#### ����ͬ������

��Ҫ�ǡ���������������֡�


### IRP��ͬ��

#### ͬ���������첽������ԭ��

��һ������ݣ���Windows���ı�̡�CH10 ����ĸ���ϸ��

CreateFile �ĵ��������������ԣ�����ָ���á�ͬ�������첽���ķ�ʽ�����豸��

ͬ����ʽ����ʱ��ReadFile, WriteFile and DeviceIoControl �е� **OVERLAP** ���ݽṹ��Ϊ NULL�����첽��ʽ���ʣ���Ҫ��������ṹ�壬������Ƕ�� Event ��

[OVERLAP](https://docs.microsoft.com/en-us/windows/desktop/api/minwinbase/ns-minwinbase-_overlapped) �ֳ�Ϊ���ص��ṹ��������ṹ���а���һ�� event �������� Event ���û����������ȴ��ں˷��ء�

���⣬ʹ�� ReadFileEx �� WriteFileEx �����첽��дʱ������Ҫ���� OVERLAP �� Event ���򣬵���Ҫ���á�������̡���Ҳ�ơ��ص����̡�Callback Function����

##### APC

APC - Asynchronous Procedure Call ���첽���̵��ã�������Ҫ���� OVERLAP �� Event ��ʵ���첽����������ͨ���ص�������ʵ�첽������������жϡ�

- ReadFileEx
- WriteFileEx
- 


AsyncOperate2 ��Դ�����ֱ���� VS2017 win32 console ���������С�


#### IRP��ͬ��������첽���

�û�ģʽ���豸��ͬ�����첽������Ҫ�õ���������ĵ�֧�֡�һ��ͬ��ģʽ������ IRP ����ǲ������ֱ�Ӵ����������Ȼ�󷵻ء����첽ģʽ����������ǲ������ֱ�ӷ��أ������ٴ���

ͬ��ģʽ��


```
graph LR
ReadFile-->NtReadFile
NtReadFile-->ntoskrnl.exe
ntoskrnl.exe-->IRP
IRP-->DispatchFunction
DispatchFunction-->IoCompleteRequest
```

��һ�ڷǳ���ϸ���г��ˡ�ͬ����ɡ������ַ�ʽ�ġ��첽��ɡ��ľ��岽�裬������Ҫ��

��Ҫע����ǣ�APC �첽��ʽ��IoCompleteRequest �Ὣ��ɺ������ص����̣����� APC ���С�Ӧ�ó������ Alert ģʽ��APC ���л��Զ����ӣ���ִ����ɺ�����

> IRP ��ͬ����ɾ�������ǲ�����У����� IoCompleteRequest �� IRP ������ϡ�


> IRP �����첽��ɡ�ָ�ľ��ǲ�����ǲ�����е��� IoCompleteRequest �ں˺��������� IoCompleteRequest ������ζ�� IRP ����Ľ�����Ҳ��־�ű��ζ��豸�����Ľ�����

��һ�ڵ�ʵ�顰PendingIrpTest���ǳ���Ҫ������ʾ�ˡ��첽�������͡����С����Զ����豸��չ��ں������ʹ�õȶ����ں˱�̼�����  

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

����������ͷŵĴ��룬��������Ҫ�������������ȴ�������ȡ�� PLIST_ENTRY ָ�룬Ȼ��ͨ�� CONTAINING_RECORD ���������Ԫ MY_IRP_ENTRY ���׵�ַ��ָ�룩��

���⣬���ǿ�����չһ�£�����ǲ�����в����ǹ��� IRP�������Կ���һ�����̣߳�������̺߳����У�ִ����һϵ��������ٵ��� IoCompleteRequest ��� IO ��������л����û�ģʽִ�лص����̡�

��Ҫע����ǣ��ص����̻��Ǻ�Ӧ�ó���IO������һ���߳��С�

���ʵ�����������ͬǰ��� NTDriver������ makefile �� sources ��ʹ�� DDK build����Ӧ�ó������ʹ�� VS 2017 build ��

#### CancelIRP

���������������ǲ������Ϊ��ǰ IRP ���� CancelRoutine ����Ӧ�ó������ CancelIO ʱ�������� CancelRoutine������ϸ�Ĳ����ǣ�Ӧ�ó��� CancelIO �������ں˵� IoCancelIrp���� IoCancelIrp ������֮ǰע�ᣨ���ã��� CancelRoutine���� CancelRoutine ����Ҫ���� STATUS_CANCELLED ������ IoCompleteRequest�����Ҫ�ͷ�ȫ�� cancel ��������

�����ԣ�IoCancelIrp ���ȡһ�������������������� DISPATCH_LEVEL ����Ӧ�þ����ܽ� CancelRoutine ��Ƶļ򵥡�

���� cancel ���ܣ�һ���첽���еĹ��ܾ������ˡ�

ʵ�� CancelIRP ��ʾ�����ȡ�� IO ���󣬵��� CancelIO �����Ĳ������豸����������Ǿ���ĳ�� IO ����


#### StartIO����


> StartIO �����ܹ���֤���������� IRP ˳��ִ�У������л���

��ν�ġ����л��������ǿ�������һ�¡���������������������Ρ�����������ֻ������һ������ͨ�У�����������Ĺɳ�������ʱ����Ҫ���������Ĺɳ����ϳ�һ�ɣ�����ǡ����л�����

StartIO �� DDK �ṩ��һ���ڲ����У���֧�� IRP ȡ����������ʱ��ͬ��������еȲ�����


```
typedef struct _KDEVICE_QUEUE {
    CSHORT Type;
    CSHORT Size;
    LIST_ENTRY DeviceListHead;
    KSPIN_LOCK Lock;
    BOOLEAN Busy;
} KDIVECE_QUEUE, *PKDEVICE_QUEUE;
```

ʵ�� StartIOTest ��ʾ �� DriverObject ע�� StartIO ���̺���ǲ����ͨ�� IoStartPacket �� IRP ������С�

�ӡ������ߡ��͡������ߡ�ģ��������StartIO ���������ߣ���ǲ�����������ߡ����ǣ�����ġ���ӡ��͡����ӡ������ǲ���ϵͳ��ɵġ�

��Ҫע����ǣ��ѳ��ӵ� IRP ������ StartIO������ȡ����Ҳ����˵��ֻ��ȡ�������е� IRP ��

�ο����е� IoStartPacket �� IoStartNextPacket ��α����


```
// ��ȡ������
...

device->CurrentIrp = Irp;

// �ͷ�������
...

device->DriverObject->DriverStartIo(device, Irp);
```

Ҳ����˵��IoStartPacket �� IoStartNextPacket ������ָ�� device->CurrentIrp�������� StartIo ���̡�

��Ҫע����ǣ����α�����չʾ�����е�һ���߼���֧�������豸���С������Ե��� StartIo ���̣���û��չʾ��һ����֧���豸æ������Ҫ������С�

��Ϊ StartIo �� CancelIrp ���������� DISPATCH_LEVEL����ִ�о����߼�ǰ����Ҫ�ȼ�����ȫ�����������ж϶Է��Ƿ���ִ��ͬһ�� IRP��

ѧϰ����ġ��Զ���StartIO�������Ը���������˽��ں˶��е�ʹ��ϸ�ڡ����Զ���StartIO�������õ� StartIO ��ͬ���ǣ������ǻص�����������һ����ͨ������ֱ�ӱ���ǲ�������á�

KeInsertDeviceQueue �����ķ���ֵ������ǰ�豸�Ƿ񡰿��С���Ҳ����˵������������һ�˾ͻ��ж��Ƿ���Ҫ��ӡ�

���⣬�� StartIo �����У�������һ��ѭ��ִ�г��Ӳ�����һ��Ҫ�ڶ��̻߳�����ȥ��⡰�Զ���StartIO������ǲ�����͡��Զ���StartIO�����ڶ��̻߳����²���������ӡ��͡����ӡ����ں� API Ӧ��Ҳ�����˻�����ơ�


#### �жϷ�������

�жϷ������̣�ISR - Interupt Service Routine��


#### DPC����

> DPC����һ��� ISR ���ʹ�ã������������ ISR �ϵ͵� DISPATCH_LEVEL ������ˣ�һ�㽫����Ҫ��������Ĵ������DPC���̣�������Ҫ��������Ĵ������ISR�С�


### ��ʱ��

�����ܽ������ں�ģʽ�µ����ֵȴ����������߿���������Щ�������������Լ������������С�����»���������ζ�irp�ĳ�ʱ������д���

>������������������ʹ�ö�ʱ����Timer���ķ�����һ�ַ�����ʹ��IO��ʱ�����̣���һ�ַ�����ʹ��DPC���̡�

#### ��ʱ����ʵ�ַ���һ

���� DDK ���õ� IO Timer��ʵ�� ms ���Ķ�ʱ����



#### IRP��ʱ����

> ���ȳ�ʼһ����ʱ�������һ��DPC���󣬲���DPC�����붨ʱ��������й�������ÿ�ζ�IRP����ǰ��������ʱ���������ú�һ���ĳ�ʱ�������ָ����ʱ���ڶ�IRP�Ĵ���û�н�������ô����ϵͳ�ͻ����DPC���̡�  
��DPC������ȡ�����ڼ��������IRP��������������ڳ�ʱǰ����IRP�Ĳ�������Ӧ��ȡ����ʱ�����Ӷ���֤�����ٴ�ȡ��IRP��

ʵ�顰IRPTimeout��չʾ�� DPC���̺Ͷ�ʱ��������Ӧ�á����ʵ��Ƚϼ򵥣�������չ���������IRP��ȡ����ʱ�����Ĺ��ܡ�


### �����������������

> ������Ҫ�����˷ֲ������ĸ���ֲ��������Խ����ܸ��ӵ���������ֽ�Ϊ������ܼ򵥵��������򡣶���ֲ�����������γ�һ���豸��ջ��irp�������ȷ��͵��豸��ջ�Ķ��㣬Ȼ�����δ�Խÿ����豸��ջ���������irp����

���½�Ҫ���ܵ��Ǵ��ں�ģʽ�ı�̣������Ժ����ɵؿ�Խ���̵ı߽硣��Ҳ��ǰ�������½�֪ʶ�Ĵ���أ�������ͬ�����첽IRP ��ʵ��ԭ��������ں˶����ת��������IRP ��ʵ��ԭ��ȡ�

[IRP����](https://www.cnblogs.com/LittleHann/p/3450436.html)

#### ���ļ������ʽ����

���ں�ģʽ�����ļ������ʽ����������������ʵ���Ͼ��ǽ��û�ģʽ�·��� I/O ����� win32 API ��NTDLL.dll�� �滻Ϊ���Ӧ���ں� API ��ntoskrnl.exe�����ɣ�������  


win32 API | kernel api | IRP
---|---|---
CreateFile | [ZwCreateFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatefile) | IRP_MJ_CREATE
CloseHandle | ZwCloseFile | IRP_MJ_CLOSE
ReadFile | [ZwReadFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwreadfile) | IRP_MJ_READ
WriteFile | [ZwWriteFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwwritefile) | IRP_MJ_WRITE

��Ҫע����ǣ�CreateFile ��Ҫ�������豸�ġ��������ӡ����� ZwCreateFile �����ֱ��ͨ���豸���õ� ObjectAttributes �����ָ�롣���������������ǲ����豸�����  
���⣬�ں˺�����ֱ�ӷ�����ص� IRP �����û�ģʽ��ͨ�� I/O ���������ö�Ӧ���ں˺���������ص� IRP ��


##### ʵ��1

Դ������ VC ���̸����ģ��鿴��ص� *.dsp �ļ����Է��֣��������� link.exe ��ָ������������ļ���

```
/out:"MyDriver_Check/HelloDDKA.sys"
```

�����ڸ�Ϊ DDK build ʱ����Ҫ�޸� sources �ļ��е� TARGETNAME��

```
TARGETNAME=HelloDDKA
TARGETTYPE=DRIVER
TARGETPATH=OBJ

INCLUDES=$(BASEDIR)\inc;\
         $(BASEDIR)\inc\ddk;\

SOURCES=Driver.cpp\
```

##### �첽����

1. ���� ZwReadFile ǰ����Ϊ IRP ����һ��������̣�APC����
2. ����һ���¼�
3. ����������м����¼���

�ο�ʵ��2�Ĵ��룬���û�ģʽ���첽��ͬ���ǣ����Ｔ�����ˡ��ص����̡���Ҳ������ͬ���¼������û�ģʽAPC����Ҫ�����¼�������Ҫ���ǵ��� SleepEx���õ�ǰ�̴߳��� Alert ״̬���ɡ�

##### �첽���÷�����

������������ͬ���¼�������ֱ��ʹ���ļ�����������¼���Ϊͬ���¼���

> ÿ��һ���豸������������һ���������ļ�����FILE_OBJECT���������ں˺��� ObReferenceObjectByHandle ���Ի�ú��豸��ص��ļ�����ָ�롣�� IRP_MJ_READ ���󱻽������ļ���������� Event �ᱻ���ã�������ļ������ Event ������Ե���ͬ���㡣

##### ͨ���������Ӵ��豸

�ں���һ��ͨ���豸�������豸�����ǣ�Ҳ����ͨ���������������豸��

> ���� ZwOpenSymbolicLinkObject �ں˺����ȵõ����������ӣ��豸�ľ����Ȼ��ʹ�� ZwQuerySymbolicLinkObject �ں˺������ҵ��豸����

�ο� Test4 Դ��


```
	UNICODE_STRING DeviceSymbolicLinkName;
	RtlInitUnicodeString( &DeviceSymbolicLinkName, L"\\??\\HelloDDKA" );

	//��ʼ��objectAttributes
	OBJECT_ATTRIBUTES objectAttributes;
	InitializeObjectAttributes(&objectAttributes, 
							&DeviceSymbolicLinkName,
							OBJ_CASE_INSENSITIVE|OBJ_KERNEL_HANDLE, 
							NULL, 
							NULL );

	HANDLE hSymbolic;
	//�趨��FILE_SYNCHRONOUS_IO_NONALERT����FILE_SYNCHRONOUS_IO_ALERTΪͬ�����豸
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
	//�趨��FILE_SYNCHRONOUS_IO_NONALERT����FILE_SYNCHRONOUS_IO_ALERTΪͬ�����豸
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


#### ͨ���豸ָ�����

���ļ������ʽ������������ķ������û�ģʽ�µĲ������ƣ������ڽ������ں�ģʽ���е�ֱ��ͨ�����豸ָ�롱���õķ�����

> ������ ZwCreateFile �� ZwReadFile ���ں˺����������ֶ�������� IRP��Ȼ�� IRP ���ݵ���Ӧ������������ǲ�����

##### [IoGetDeviceObjectPointer ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iogetdeviceobjectpointer)

> ÿ���ں��еľ�������һ���ں˶����ָ����ϵ������


```
NTSTATUS IoGetDeviceObjectPointer(
  PUNICODE_STRING ObjectName,
  ACCESS_MASK     DesiredAccess,
  PFILE_OBJECT    *FileObject,
  PDEVICE_OBJECT  *DeviceObject
);
```

IoGetDeviceObjectPointer �ں˺�������ͨ���豸��ֱ�ӻ�á��ļ�����ָ��͡��豸����ָ�롣

> ������ IoGetDeviceObjectPointer �ں˺������豸��������ü������ 1�� ����������豸�����Ӧ�õ��� ObDereferenceObject �ں˺�����ʹ�����ü����� 1��

##### ����IRP

�ο� [����IRP�����ַ���](https://blog.csdn.net/vangoals/article/details/4381567)
  
- [IoBuildSynchronousFsdRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildsynchronousfsdrequest)  
- [IoBuildAsynchronousFsdRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildasynchronousfsdrequest)
- [IoBuildDeviceIoControlRequest ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuilddeviceiocontrolrequest)
- [IoAllocateIrp ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-ioallocateirp)
- IoCallDriver
- 

�ֶ�����IRP�ļ������裺  
1. �ȵõ��豸ָ�롣һ�ַ����ǵ��� IoGetDeviceObjectPointer����һ�ַ������ȵ� ZwCreateFile ����豸������ٵ� [ObReferenceObjectByHandle](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-obreferenceobjectbyhandle) �ں˺���ͨ���豸�������豸ָ�롣
2. ʹ�������ᵽ��4���ں˺�������IRP��
3. ����IRP��I/O��ջ
4. ���� IoCallDriver �ں˺��������ڲ�������豸�������ǲ������

ʵ��5


```
	UNICODE_STRING DeviceName;
	RtlInitUnicodeString( &DeviceName, L"\\Device\\MyDDKDeviceA" );

	PDEVICE_OBJECT DeviceObject = NULL;
	PFILE_OBJECT FileObject = NULL;
	//�õ��豸����������������1
	//����ǵ�һ�ε���IoGetDeviceObjectPointer������豸���൱�ڵ���ZwCreateFile
	ntStatus = IoGetDeviceObjectPointer(&DeviceName,FILE_ALL_ACCESS,&FileObject,&DeviceObject);

	KdPrint(("DriverB:FileObject:%x\n",FileObject));
	KdPrint(("DriverB:DeviceObject:%x\n",DeviceObject));

	if (!NT_SUCCESS(ntStatus))
	{
		KdPrint(("DriverB:IoGetDeviceObjectPointer() 0x%x\n", ntStatus ));

		ntStatus = STATUS_UNSUCCESSFUL;
		// ���IRP
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

	//����ͬ��IRP
	PIRP pNewIrp = IoBuildSynchronousFsdRequest(IRP_MJ_READ,
												DeviceObject,
												NULL,0,
												&offsert,&event,&status_block);
 	KdPrint(("DriverB:pNewIrp:%x\n",pNewIrp));

	PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(pNewIrp);
	stack->FileObject = FileObject;

	//����DriverA����һֱ���õ�DriverA����ǲ����
	NTSTATUS status = IoCallDriver(DeviceObject,pNewIrp);

    if (status == STATUS_PENDING) {

		//���DriverA����ǲ����û�����IRP����ȴ�IRP���
       status = KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            NULL);
        status = status_block.Status;
    }

	//�����ü�����1�������ʱ��������Ϊ0��
	//�򽫹ر��豸���൱�ڵ���ZwClose
 	ObDereferenceObject( FileObject );
```

ʵ������ʾ����ԭʼ�� IoAllocateIrp �ں˺�����ʹ�÷������ֶ����� IRP �ķ�����ԭ������BSOD�����Բο�[CSDN����](https://blog.csdn.net/qq125096885/article/details/47340291)��

> ���ж��豸�Ĳ�������ת��Ϊһ�� IRP �������е� IRP ���ն����� IoAllocateIrp �ں˺��������ġ�


```
PIRP IoAllocateIrp(
  CCHAR   StackSize,
  BOOLEAN ChargeQuota
);
```

ʹ�� IoAllocateIrp ������ IRP ����Ҫʹ�� IoFreeIrp �ͷ���ص����ݽṹ


```
	PDEVICE_OBJECT DeviceObject = NULL;
	PFILE_OBJECT FileObject = NULL;
	//ͨ���豸���õ��豸����ָ��
	ntStatus = IoGetDeviceObjectPointer(&DeviceName,FILE_ALL_ACCESS,&FileObject,&DeviceObject);

	KdPrint(("DriverB:FileObject:%x\n",FileObject));
	KdPrint(("DriverB:DeviceObject:%x\n",DeviceObject));

	if (!NT_SUCCESS(ntStatus))
	{
		KdPrint(("DriverB:IoGetDeviceObjectPointer() 0x%x\n", ntStatus ));
		ntStatus = STATUS_UNSUCCESSFUL;
		// ���IRP
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

	//��ΪDriverA��BUFFER IO�豸
	pNewIrp->AssociatedIrp.SystemBuffer = NULL;
	
 	KdPrint(("DriverB:pNewIrp:%x\n",pNewIrp));

    // ����I/O��ջ
	PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(pNewIrp);
	stack->MajorFunction = IRP_MJ_READ;
	stack->MinorFunction=IRP_MN_NORMAL;//0
	stack->FileObject = FileObject;

	//����DriverA����
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

����������ʵ���У����ֻᵼ�� BSOD��ע�� IoFreeIrp ��һ���Ž��������⡣��ѧϰ�ꡰ�ֲ�������֮������֪����һ�������� IoCallDriver ��IRP �Ŀ���Ȩ��ת�����˱����������򣬴˺�ֻ������������в����ûؿ���Ȩ�������ڵ��� IoCallDriver �������� IRP��������������ο� 12.1 ������̡�




#### ��ȡ�豸ָ��ķ���

��һ����������� Windows �ڲ���λ���豸����ָ�룬��ʵ�����Զ���� IoGetDeviceObjectPointer ������


```
//ģ��IoGetDeviceObjectPointerʵ��
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

	//����Ҫ�򿪵��豸���豸��
    InitializeObjectAttributes( &objectAttributes,
                                ObjectName,
                                OBJ_KERNEL_HANDLE,
                                (HANDLE) NULL,
                                (PSECURITY_DESCRIPTOR) NULL );

	//ZwOpenFile���豸������ļ�������
    status = ZwOpenFile( &fileHandle,
                        DesiredAccess,
                        &objectAttributes,
                        &ioStatus,
                        0,
                        FILE_NON_DIRECTORY_FILE );

    if (NT_SUCCESS( status )) 
	{
		//ͨ���ļ����������õ��ļ�����ָ��
        status = ObReferenceObjectByHandle( fileHandle,
                                            0,
                                            *IoFileObjectType,
                                            KernelMode,
                                            (PVOID *) &fileObject,
                                            NULL );
        if (NT_SUCCESS( status )) 
		{
            *FileObject = fileObject;
			//ͨ���ļ�����ָ�룬�õ��豸����ָ��
            *DeviceObject = IoGetBaseFileSystemDeviceObject( fileObject );
        }
        ZwClose( fileHandle );
    }
    return status;
}
```

[Troubleshooting: MULTIPLE_IRP_COMPLETE_REQUESTS ](https://troubleshooter.xyz/wiki/fix-multiple_irp_complete_requests-error/)


### �ֲ���������

������Ҫ�����˷ֲ������ĸ���ֲ��������Խ����ܸ��ӵ���������ֽ�Ϊ������ܼ򵥵��������򡣶���ֲ�����������γ�һ���豸��ջ��irp�������ȷ��͵��豸��ջ�Ķ��㣬Ȼ�����δ�Խÿ����豸��ջ���������irp����

#### �ֲ������������

�ֲ����������Ӧ�����������ÿ���������򴴽�һ���豸����Ȼ���豸�����һ��һ��ء����ء��������豸����֮�ϡ�

##### �豸����

[DEVICE_OBJECT](https://msdn.microsoft.com/en-us/library/windows/hardware/ff543147(v=vs.85).aspx)

���豸��������ݽṹ�������֧�ֲַ���������

[Introduction to device objects](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-device-objects)

##### �豸��ջ�����

```
PDEVICE_OBJECT IoAttachDeviceToDeviceStack(
  PDEVICE_OBJECT SourceDevice,
  PDEVICE_OBJECT TargetDevice
);
```

- [IoAttachDeviceToDeviceStack](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-ioattachdevicetodevicestack)
- [IoDetachDevice](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iodetachdevice)

ע�⣺IoDetachDevice ֻ��һ����������TargetDevice�����Ǳ�ɾ���豸���²��豸��

##### IO��ջ

> �� Windows ����ģ���У�����һ������С�I/O��ջ������ IO_STACK_LOCATION ���ݽṹ��ʾ�������豸��ջ���ܽ�ϡ�

> �� IRP �����ݽṹ�У��洢��һ�� IO_STACK_LOCATION �����ָ�롣���� IoAllocateIrp �ں˺������� IRP ʱ����һ�� StackSize �������ò������� IO_STACK_LOCATION ����Ĵ�С��

���� IO_STACK_LOCATION ���飬�����Բο� CH7.1 �ڡ�

IRP ÿ��Խһ���豸��ջ���ͻ��� IO_STACK_LOCATION ��¼�±��β�����ĳЩ���ԡ�

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/6B4457CC0CC5442FBD1C8E26F6180BF3/14881)


##### ����ת��IRP

�����������豸�����յ� IRP��������ǲ�����������ִ���ʽ��  
1. ���� IoCompleteRequest ֱ�ӽ��� IRP
2. ���� StartIo ���л� IRP������ǰ IRP �⣬�����Ľ��� IRP ����
3. ����ת�� IRP

����ת�� IRP ��ʱ����Ҫע�� IO_STACK_LOCATION �ı仯

������ǰ��


```
PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;

// �����²�����
IoSkipCurrentIrpStackLocation(pIrp);

ntStatus = IoCallDriver(pdx->TargetDevice, pIrp);
```

��ǰ��������

```
PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION)pDevObj->DeviceExtension;

// �����²�����
IoCopyCurrentIrpStackLocationToNext(pIrp);

ntStatus = IoCallDriver(pdx->TargetDevice, pIrp);
```

##### ʵ��һ

ʵ��1 ��ʾ����ν� DriverA ���豸������ص� DriverB �ϣ�ͬʱת����Ӧ�� IRP ��

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/9EBC81019420434DA1C685868AB1F1E4/14961)

����־�п��Կ�����DriverB hook �� DriverA �� CreateFile, ReadFile and CloseFile ���� I/O �ӿڡ����⣬��Ҫע�� DriverA ���첽��ɣ��� DriverB Ҳ�̳��������첽���ԣ���ʵ��Ӧ�ò���Ժ������õ���ͬ������ 

����ͨ�� DeviceTree.exe �鿴����֮��Ĺ��ع�ϵ��

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/2645DFF60E1B40168F8AA32F6F0FD23D/14979)

##### ʵ��� 

ʵ��2 ������DeviceTree.exeö���豸�����ԭ��


#### �������

���ڡ�������̡������Բο� CH9 IRP��ͬ�������С��첽�����豸��ʽ����ʹ�õľ��ǡ�������̡���������Ҫѧϰ�ֲ����������У���������̡�������ڸ����д��ݵġ�  

������Ҫ���� IRP �Ŀ���Ȩ��ת��

##### ������̸���

����������ͨ�� IoCallDriver �����Լ����²���������������ʱ���Ὣ IRP �Ŀ���Ȩ����������������  
�����������һ�Ǳ����õ��豸��ͬ�������� IRP����ô���� IoCallDriver ����ʱ��IRP ����ɡ����Ǳ����õ��豸���첽������ IRP����ô��IoCallDriver ���������أ��� IRP ��û��������ɡ�  
���ڵڶ�������������ڵ��� IoCallDriver ǰ���� IRP ע��һ����������̡����� IRP ������ɵ�ʱ�������������̡����ᱻ���á���ʵע�� IRP ������̾����ڵ�ǰ��ջ��IO_STACK_LOCATION���е� CompletionRoutine ����IRP ��ɺ�һ����ջ���ϵ���������ͬ����������������ǿ�������������̡����⣬����������̵ľ��� IO_STACK_LOCATION ����һ������ Context ��  

[IoSetCompletionRoutine ](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iosetcompletionroutine)

[��ǰ�����������²��������������](https://blog.csdn.net/kemaWCZ/article/details/82690095)

> ������̿�����Ϊ֪ͨ IRP ��ɵ�һ����־������������п��Ժ������֪�� IRP �����״��������˵������������У��ṩ��һ���������»�� IRP �Ŀ���Ȩ��  

##### ���� Pending λ

������������̻ᣬ���� Pending λ�Ĺ�����Ҫ����Ա�ڴ�����ָ����

ʵ��3��ʾ��������̺ʹ��� Pending λ��

ʵ��4��ʾ��������̷��� STATUS_MORE_PROCESSING_REQUIRED���ñ����������»�� IRP ����Ȩ��


#### ��irp�ֽ�ɶ��irp

����ǰ����˵��������̷��� STATUS_MORE_PROCESSING_REQUIRED�����»�ȡ IRP �Ŀ���Ȩ����������ת�� IRP������˵�����ı��� IRP ����ջֱ��ֱ�ϵ�������ʽ��


IRP �ֽ��������һ����������ˮ����ȥ�ž�ȡˮ�����Σ�  
������ˮ�õ��Ǵ���Ͱ����� IRP�����Ⱦ��ڴ󣬲��ܷŵ�����ȥֱ��ȡˮ�����ǣ�������һ��СͰ���м�� IRP��ȥ����ȡˮ����ȡ���Σ�һ����ڴ���Ͱ��������

ʵ��5��ʾ�� IRP �ķֽ�ͽ��� MDL ʵ��ֱ�Ӷ�д�����ʵ���Ӧ��ģʽ���Գ���DriverA �� DriverB ����Ҫ���±��롣���� DriverA �� MDL ���ǵ����÷��������÷����Բο� CH7 �� MDL_Test ʵ�顣


[MDLʵ���ں�ģʽ�´󻺴��Ƭ](https://blog.csdn.net/wdykanq/article/details/7752909)

[������ʶMDL](https://blog.csdn.net/cosmoslife/article/details/50395985)

The [IoBuildPartialMdl](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildpartialmdl) routine builds a new memory descriptor list (MDL) that represents part of a buffer that is described by an existing MDL.

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/56C1480F51A04320A886888D5B5284AF/15142)

���������־��ִ����������ֱ��ֱ�ϡ�


#### wdm��������ܹ�

WDM ������ NT �������Ĳ�ͬ�������� PNP ���ơ�

IRP_MJ_PNP �������� IRP ��ͬ���ǣ�������������Ӧ�ó��򣬶��ǵ��豸�����롢�γ���ϵͳ����ʱ���� I/O ������������������ IRP_MJ_PNP�����������ת�����ײ��豸�����ɵײ���������ȥ������������ƣ�ʹ�õײ���޸Ĳ�Ӱ���ϲ���߼�������  

##### PDO

PDO - Physical Device Object������΢���ṩ����������������������������� PnP �͵�Դ����ȹ��ܡ��� Windows ���ж�������������򣬷ֱ��� PCI ������������USB ������������ISA �����������������������������ȡ����У�PCI ������ ROOT ���ߡ�

> ��ϵͳ����ʱ�����������������أ�Ȼ��Ѱ�ҹ����ڸ������ϵ������豸����������� PCI �豸���ͻ���� PCI �豸�� PDO��Ȼ��Ѱ�Һ��ʵ� FDO ���ء�PCI-ISA �š�USB �������ᵱ���� PCI �豸�������� PDO �� FDO �ȡ�

###### PDO and PnP

�� PnP ֮ǰ�ĵ�����ģ���У�ĳ�������ϵͳ��Դ���ǹ̶��ģ�������I/O ��ַ�ռ䡢�����ַ�ռ䡢�жϺŵ���Դ���� PnP ʵ������Щ��Դ�Ķ�̬���䡣


### ���弴��

[Plug and Play](https://en.wikipedia.org/wiki/Plug_and_play)����ָ����ͨ������ϵͳЭ���Զ������豸�ϵ���Դ�����磺�жϺš�I/O ��ַ��DMAͨ�����豸�����ڴ�ȡ�

#### PnP������

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/9DE1D84EF43F4941A19C7FABAF83B87A/15266)

ע�⣺ע���ά���Ѱ�װ��Ӳ���ͼ��弴���豸��������ݿ⡣ע�������ݰ�������������������ʶ��Ͷ�λ�豸ʹ�õ���Դ��

#### ���弴��IRP

ת�����ײ�������������� PnP IRP �ӹ������󡣱�13-1 �г��˸����ӹ��ܴ��롣

WDM ������ NT �������Ĳ�ͬ�������� PNP ���ơ�

IRP_MJ_PNP �������� IRP ��ͬ���ǣ�������������Ӧ�ó��򣬶��ǵ��豸�����롢�γ���ϵͳ����ʱ���� I/O ������������������ IRP_MJ_PNP�����������ת�����ײ��豸�����ɵײ���������ȥ������������ƣ�ʹ�õײ���޸Ĳ�Ӱ���ϲ���߼�������  


#### ͨ���豸�ӿ�Ѱ���豸

�� WDM ���������У�һ�㶼��ͨ���豸�ӿ�����λһ����������ͬʱ��Ϊ�˼��� NT ��������Ҳ����ʹ���豸���ͷ�����������λ�豸��

##### �豸�ӿ�

�豸�ӿ���һ��ȫ�ֱ�ʶ��GUID������ 128 λ��������ɣ����ܱ�֤��ȫ��Χ�ڲ���ͻ��

�����豸�ӿ���Ҫ�Ǳ����豸����ͻ��

[IoRegisterDeviceInterface](https://blog.csdn.net/chenyujing1234/article/details/7843709) �ں˺�������ע���豸�ӿڡ�

##### Ӧ�ó���Ѱ���豸�ӿ�

��Ӧ�ó���Ѱ���豸����ͨ���豸�ӿں��豸�ž����ġ�������豸����ָ������ͬ����������豸�ı�š�


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

##### �鿴�豸�ӿ�

ͨ�� WinObj �� DeviceTree ���Բ鿴�豸�ӿڡ�


#### ʵ��һ

���µ�ʵ��һ��ʾ�� WDM ��������� PnP ���ܣ����а�����һ�����Գ����һ����������

#### ���Գ���

�����½� WIN32 CONSOLE ���̣���������Գ���Ƕ�룬��Ҫע����ǣ�guid.h �� Ioctls.h �����ļ���λ�����������У�Ҳ����˵��Ϊ��ͳһά������������������������ļ���ǰ�߶�������豸�ӿ� GUID�������� I/O �����롣

����½��� WIN32 CONSOLE ����һ��ʼ�����ʱ��ᱨ���Ӵ���LINK2001 �� [LINK1120](https://blog.csdn.net/albertsh/article/details/72818113)���޷��������ⲿ���š�

�ο����ϲ��Ϳ�֪��LINK1120 ��ʾ��
> ����˵����һ�����Ӵ�������Ǳ�����������������ĸ���ԭ������ҵõ������������������Ҳ���������ʵ�֣�����������ģ�����ı�����ʽ�кܶ�.

�ڿ����屨��ļ������� API ������������صĺ����������ԣ���Щ������ͷ�ļ������ҵ�������û�а������ǵĿ��ļ���

[setupdigetclassdevs link error](https://stackoverflow.com/questions/33640791/setupapi-setupdi-functions-dont-link) ������Ӹ������ǣ���Ҫ�� setupapi.lib ������ļ���ӵ������������С�


##### ��������

����������Ը��� CH1 �� CH3 �е� HelloWDM ���̵� makefile �� Sources �ļ���

�Ƚϱ��µ���������� CH1 �е�����������Է��֣�  
1. ���ǵ� INF �ļ���ͬ�������� GUID
2. ͷ�ļ��е��豸��չ��ͬ������û�з������Ӻ��豸����������Ϊ�豸�ӿڣ�interfaceName��
3. cpp ����Ҫ�������� GUID �� PnP �� IRP �š�

���Թ۲� GUID �� interfaceName ��ע����̡�

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/366F5384384F4613B8B8197B8C227CB8/15392)

��־�и����Ĳ��־��� interfaceName �����ĸ��������Ծ��ŷָ�������ǣ�

header 1 | header 2
---|---
\\?\ROOT | �豸����·����ֱ�ӹ��� ROOT ������
UNKNOWN | DeviceName��δ�裨NULL��
0000 | �豸��
��...��| GUID

���⣬��Ӧ�ó����д�ӡ��ʾ���������ӡ�Ϊ��\��.



### ����IRP

> ���½����irp�Ĳ������˽�һ�����ܽᡣ������ת��irp�������˼��ֲ�ͬ�ķ�ʽ������ܽ��˴���irp�ļ��ֲ�ͬ����������irp�ܵ���˵��Ϊ����ͬ��irp�ʹ����첽irp�����ڴ���ͬ��irp�������Ƚϼ򵥣�i/o�������Ḻ�����irp������ڴ棬����ʹ�ò��������ڴ����첽irp�������Ƚϸ��ӣ�����Ա��Ҫ�Լ������irp������ڴ���գ���ʹ��ʮ����

�����Ƕ� CH11 ��������������������� �� CH12 "�ֲ���������" ���µ� IRP ������ݵ��ܽᡣ���У����� IRP ���ֿ��Խ�� CH11 ��������ת�� IRP ������Ҫ��� CH12 ������


#### ת��IRP

ת�� IRP ��Ϊ���������ֱ��ת����ת�����ȴ���ת�������á�������̡������⣬�����Թ��� IRP �������� StartIo ���̺�ֱ����� IRP��

��Щ��ǰ����½��ж��ѽ�����ˣ���һ�°����ǹ鼯��һ�����عˡ����У�ת����������̣����Բο� CH12 �ļ���ʵ�飬�� StartIo ���Բο� CH9 ��


#### ����IRP

> ���� IRP ��Ϊ����ͬ�� IRP �ʹ����첽 IRP��  

ͬ�� IRP �ڵ��� IoCallDriver �󣬻�һֱ����ֱ�� IRP ��ɡ��첽 IRP ��������������̣�����������л�ȡ IRP ����������

##### ����ͬ��IRP

[IoBuildDeviceIoControlRequest](https://blog.csdn.net/gxfan/article/details/2900095IoBuildDeviceIoControlRequest) ����ͬ�� IRP ��

�ο� CH11 ʵ��5


##### �����г�ʱ�� IOCTL IRP

�������ƻ��ƱȽ������ǰ����½ڲ�û����ص����ݣ���Ҫ����ͬ��IRP����Ϊͬ��IRP ��Ҫ�ȵ� IoCallDriver ���زż���ִ�к���Ĵ��룬��Ƴ�ʱ���ƣ��ͷǳ���Ҫ�ˡ�


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
	
	// ��ʼ��ͬ���¼�
	KeInitializeEvent(&event,NotificationEvent,FALSE);
	
	//����ͬ��IRP
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
		
	// �ж� IRP �Ƿ�Ϊ��
	
	if ( irp == NULL) {
	    return STATUS_INSUFFICIENT_RESOURCES;
	}
	
	lock = IRPLOCK_CANCELABLE;
	
	// �����������
	IoSetCompletionRoutine(
	    irp,
		MakeSynchronousIoctlWithTimeoutCompletion,
		&lock,
		TRUE,
		TRUE,
		TRUE
		);
		
	// ���õײ�����
	status = IoCallDriver(TopOfDeviceStack,irp);
	
	// �ж�IRP�Ƿ񱻹���
	if (status == STATUS_PENDING) {
	    // ������ʱ 1 ms
		dueTime.QuadPart = -10000 * Milliseconds;

		//���DriverA����ǲ����û�����IRP����ȴ�IRP���
       status = KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            &dueTime
							);
							
		// ����ǳ�ʱ
		if (status == STATUS_TIMEOUT) {
		    if (InterlockedExchange((PVOID)&lock, IRPLOCK_CANCEL_STARTED)
			    == IRPLOCK_CANCELABLE) {
				// ȡ�� IRP
				IoCancelIrp(irp);
				
				if (InterlockedExchange((PVOID)&lock, IRPLOCK_CANCEL_COMPLETE)
			    == IRPLOCK_COMPLETED) {
				    // ���� IRP
				    IoCompleteRequest(irp, IO_NO_INCREMENT);
				}
			}
			
			// �ȴ�ͬ���¼�
			KeWaitForSingleObject(
                            &event,
                            Executive,
                            KernelMode,
                            FALSE, // Not alertable
                            NULL
							);
							
			// ����IRP ���״̬
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






[IoBuildAsynchronousFsdRequest](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iobuildasynchronousfsdrequest) �����첽 IRP ����������������ͷ��ڴ���Դ��

IoAllocateIrp Ҳ�Ǵ����첽 IRP ��


### ������������

> ������Ҫ����wdm��ntʽ�����������򿪷��������������򿪷�ʮ���������޸�������������Ĺ��ܣ�Ҳ���Զ����ݽ��й��˼��ܡ����⣬���ù������������ܱ�д���ܶ�����൱����ǿ��ĳ�������

�������������Ϊ���ࣺ


header 1 | header 2
---|---
�߲������������ | High FiDo�������� FDO ֮��
�Ͳ������������ | Low FiDO�������� PDO ֮�ϣ����� FDO �� PDO ֮��



#### �ļ�������������

�ļ��������������Լ������ڴ�������֮�ϣ�����ȫ����������������IRP������ѡ��ع�����ЩIRP��

##### �������������ģ��

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/EAC168D2950242E5A68A8CA1773F21B4/15529)

Ϊ���ñ�д�Ĺ����������� U �̱�Ϊֻ��״̬�������� DISK.sys �� USBSTOR.sys ֮�佨��һ������������




##### ���������������ں���

��Ҫ����ں�����ָ����Ҫ���˵�IRP ����ǲ������


##### U�̹�����������

![](https://note.youdao.com/yws/public/resource/d968916d4caea412213b0fc124cfdebc/xmlnote/08FAD34A1A344AF6B8B987382C7F2637/15543)


##### FileFilterʵ��

���� CH1 HelloWDM �� makefile �� sources �ļ����޸� TargetName�����£��ο� CH3 ��Sources �ļ�����ǰ�õ��� tab�����ǿո�


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

һ��ʼ�ᱨ�������C4335���ο�[compiling error c4335](https://stackoverflow.com/questions/16345477/error-c4335-when-compile-c-project-vs2012) �޸Ķ�Ӧ���ļ���ʽ�����ɡ�

Ȼ��ᱨһ�������Ĵ�����Ҫ���ļ���ʽת�����º궨�廻��ʱ�������˿��У�ʹ�û��з�ʧЧ��ɾ�����м��ɡ�

��������һЩ��صı�������������±༭ stddcls.h �ļ����£�


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

##### �����������

����������˵Ĺؼ������� IRP_MJ_SCSI������ IRP_INTERNAL_DEVICE_CONTROL ��һ���������� DISK.sys �� USBSTOR.sys ֮�䴫�ݵ��Ǳ�׼�� SCSI ָ�  

�� IRP_MJ_SCSI ����ǲ�����У��ڽ��� IRP �����ײ�ǰ��������������̣�������������޸ĵײ������������Ĵ���


#### ntʽ������������

��һ�ڽ��ܵ��� WDM ������������װ��ʱ��Ҫ�޸�ע����������ܵ� NT ʽ���������������޸�ע�����ͨ��������ֱ��Ѱ�ҵ���Ҫ���˵������豸��ָ�룬Ȼ���Լ����������档

##### ���������豸����

ͨ�� WinObj.exe ���Բ鿴�����������豸����Ϊ Device\KeyboardClass0

##### ctrl2cap

ʵ�� ctrl2cap ������ Windows �ں�ר�� Mark Russionovich ��д��һ�����̹�������������Ҳ������������м�¼ IRP_MJ_READ ��ȡ��ֵ��Ҳ�����޸����ֵ��  

��Ҫע����ǣ��ڽ������ʵ���ʱ�����ֲ���һ�οӣ����¹������£�  
>��һ��ʼ��ͨ����Զ�����桱���ӵ����Ի������Թ۲쵽 ctrl2cap �����ѹ��سɹ������ǣ��� txt �в��Դ��֣�debugview δ�����κμ��̼�¼��  
Ȼ������ÿ������ǲ��������������ڴ�ӡ��Ϣ��debugview ����û�в����κ���ǲ�������õļ�¼��  
ͨ�� winobj.exe �۲췢�֣������豸������� KeyboardClass0 ������һ�����Ƶ� KeyboardClass1�������л��� device name���ٴ�ʵ�飬��Ȼû�м�¼��  
������⿨��һ�������ڣ�ĳ��ͻȻ�뵽�ˣ��ǲ��� Remote Desktop ��û������ͨ�������� OS ������  
���ǣ�����ʵ�飬��ʹ�� Remote Desktop������ʹ�� VMWare �ͻ���ֱ�ӵ�¼����Σ��ܹ��������̵��û���¼����

![](https://img-blog.csdnimg.cn/20190221095525400.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NhZ2l0dGFyaXVzX1dhcnJpb3I=,size_16,color_FFFFFF,t_70)

### �߼����Լ���

���½�����һЩwindows���������ĸ߼����Լ��ɡ���Ҫ��ʹ�� WinDbg.exe ���� dump �ļ����Ժ�˫���ں˵��ԡ��ⷽ����������ϱȽ϶࣬������������ֱ�� google ��

