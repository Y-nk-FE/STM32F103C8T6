#include"SerialPort.h"
#include<iostream>
#include<tchar.h>

map<int, HANDLE> SerialPort::ComMap;

// 构造函数&析构函数使用默认函数

// 打开端口
HANDLE SerialPort::OpenPort(UINT PortNo) {
    // 串口句柄
    HANDLE H_Com;

    // 将串口号打印到字符数组里，该方式可以打开10以上的串口
    TCHAR PortName[20];
    _stprintf_s(PortName, _T("\\\\.\\COM%d"), PortNo);

    H_Com = CreateFile(PortName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);
    
    // 如果串口打开失败
    if (H_Com == INVALID_HANDLE_VALUE){
        return INVALID_HANDLE_VALUE;
    }

    // 串口打开成功
    SetupComm(H_Com, 1024, 1024); //设置读写缓冲区为1024;
    ComMap[PortNo] = H_Com;		// 打开成功则，存入map
 
    return H_Com;
}