// 1. VC++ �� �� �������ؼ� "server" ������Ʈ ���� ������

// 2. sdk ���� ���߰�, "X86", "Debug" �� �����Ͻø� �˴ϴ�.

// 3. server ������ ��������.








#define USING_GUI
#include "cppmaster.h"

// ���� ������ ���ϰ� �ϱ����� "������(Proxy)" �� ������.

// Proxy : �Լ� ȣ���� ��� �ڵ�� �����ؼ� ������ ����
// Stub  : ������ ��� �ڵ带 �ٽ� �Լ� ȣ��� ����.(������ handler�Լ�)
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





