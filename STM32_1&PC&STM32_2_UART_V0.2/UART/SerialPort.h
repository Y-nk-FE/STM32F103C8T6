#pragma once
#ifndef _SERIALPORT_H_  //If_Not_Defined 预处理命令
#define _SERIALPORT_H_
#include<windows.h>
#include<map>
using namespace std;
// 通用的串口类，通过List存储串口
class SerialPort {
public:
    SerialPort();
    ~SerialPort();
private:

    // 使用CreatFile打开串口,HANDLE句柄作为返回值
    static HANDLE OpenPort(UINT PortNo = 1);

public:


public:
    // 串口端口号，一经连接，不再修改
    // 使用static，对串口端口号进行数据保护
    static map<int, HANDLE> ComMap;
};
#endif 