#include"SerialPort.h"
#include<iostream>
#include<tchar.h>

map<int,HANDLE> SerialPort::ComMap;

// 构造函数&析构函数使用默认函数

// 打开端口
HANDLE SerialPort::OpenPort(UINT PortNo){
    // 串口句柄
    HANDLE H_Com; 

    // 将串口号打印到字符数组里，该方式可以打开10以上的串口
    TCHAR PortName[20]; 
    _stprintf_s(PortName,_T("\\\\.\\COM%d"),PortNo); 

    H_Com = CreateFile(PortName,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,0);

}
int main(){
    cout<<1;
    return 0;
}