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

// 사용자는 이 DLL을 load하고 CalcProxy 객체를 만들어야 합니다
// 그런데, 사용자는 CalcProxy 라는 클래스 이름을 알수도 없고,
// 알아도 안됩니다.

// 객체를 생성하는 함수를 약속합니다.
extern "C" __declspec(dllexport)
ICalc* CreateProxy()
{
	return new CalcProxy;
}

// DLL 로 빌드하는 방법
// cl CalcProxy.cpp  /LD  /link user32.lib  gdi32.lib   kernel32.lib





