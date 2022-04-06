#define USING_GUI
#include "cppmaster.h"

// RPC ( Remote Procedure Call ) : 다른 프로세스의 함수를 호출하는 개념
// 자바의 "RMI(Remote Method Invocation)"

// 서버와 클라이언트가 동일한 기능을 제공하는 것을 보장하기 위해
// 인터페이스 도입
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class CalcProxy : public ICalc 
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





