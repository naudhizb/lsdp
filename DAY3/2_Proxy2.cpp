// 1. VC++ 한 개 더실행해서 "server" 프로젝트 열어 보세요

// 2. sdk 버전 맞추고, "X86", "Debug" 로 빌드하시면 됩니다.

// 3. server 실행해 놓으세요.








#define USING_GUI
#include "cppmaster.h"

// 서버 접속을 편리하게 하기위한 "대행자(Proxy)" 를 만들자.

// Proxy : 함수 호출을 명령 코드로 변경해서 서버에 전달
// Stub  : 도착한 명령 코드를 다시 함수 호출로 변경.(서버의 handler함수)
class CalcProxy
{
	int server;
public:
	CalcProxy() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	CalcProxy* pCalc = new CalcProxy;

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;

}





