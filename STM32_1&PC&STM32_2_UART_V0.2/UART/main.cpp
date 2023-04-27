#include<iostream>
#include<tchar.h>
#include<Windows.h>
using namespace std;
int main() {
	int num = 32;
	static HANDLE a = clock;
	cout << a << endl;
	return 0;
}