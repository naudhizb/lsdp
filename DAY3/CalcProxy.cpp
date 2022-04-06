// CalcProxy.cpp

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class CalcProxy : public ICalc
{
	int server;
public:
	CalcProxy() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// ����ڴ� �� DLL�� load�ϰ� CalcProxy ��ü�� ������ �մϴ�
// �׷���, ����ڴ� CalcProxy ��� Ŭ���� �̸��� �˼��� ����,
// �˾Ƶ� �ȵ˴ϴ�.

// ��ü�� �����ϴ� �Լ��� ����մϴ�.
extern "C" __declspec(dllexport)
ICalc* CreateProxy()
{
	return new CalcProxy;
}

// DLL �� �����ϴ� ���
// cl CalcProxy.cpp  /LD  /link user32.lib  gdi32.lib   kernel32.lib





