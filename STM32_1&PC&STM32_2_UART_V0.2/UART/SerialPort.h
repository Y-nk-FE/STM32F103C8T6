#pragma once
#ifndef _SERIALPORT_H_  //If_Not_Defined Ԥ��������
#define _SERIALPORT_H_
#include<windows.h>
#include<map>
using namespace std;
// ͨ�õĴ����࣬ͨ��List�洢����
class SerialPort {
public:
    SerialPort();
    ~SerialPort();
private:

    // ʹ��CreatFile�򿪴���,HANDLE�����Ϊ����ֵ
    static HANDLE OpenPort(UINT PortNo = 1);

public:


public:
    // ���ڶ˿ںţ�һ�����ӣ������޸�
    // ʹ��static���Դ��ڶ˿ںŽ������ݱ���
    static map<int, HANDLE> ComMap;
};
#endif 