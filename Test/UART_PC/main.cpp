#include "StdAfx.h"  
#include "SerialPort.h"  
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	CSerialPort mySerialPort;//���Ƚ�֮ǰ�������ʵ����
	int length = 8;//���崫��ĳ���


	unsigned char* temp = new unsigned char[8];//��̬����һ������




	if (!mySerialPort.InitPort(3, CBR_19200, 'N', 8, 1, EV_RXCHAR))//�Ƿ�򿪴��ڣ�3�������������ӵ��Ե�com�ڣ��������豸�������鿴��Ȼ������������
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}
	if (!mySerialPort.OpenListenThread())//�Ƿ�򿪼����̣߳������߳��������䷵��ֵ
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}


	temp[0] = 03;
	temp[1] = 85;
	temp[2] = 04;
	temp[3] = 00;
	temp[4] = 00;
	temp[5] = 00;
	temp[6] = 11;
	temp[7] = 03;
	cout << mySerialPort.WriteData(temp, 8) << endl;//����������Ǹ����ڷ������ݵĺ�����temp����Ҫ���͵����顣
	cout << mySerialPort.GetBytesInCOM() << endl;//�������������ʾ����ֵ����
	delete temp;
	system("pause");
	return 0;
}