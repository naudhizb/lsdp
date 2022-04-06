#define USING_GUI
#include "cppmaster.h"

// RPC ( Remote Procedure Call ) : �ٸ� ���μ����� �Լ��� ȣ���ϴ� ����
// �ڹ��� "RMI(Remote Method Invocation)"

// ������ Ŭ���̾�Ʈ�� ������ ����� �����ϴ� ���� �����ϱ� ����
// �������̽� ����
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





