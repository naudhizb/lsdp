// 1. VC++ �� �� �������ؼ� "server" ������Ʈ ���� ������

// 2. sdk ���� ���߰�, "X86", "Debug" �� �����Ͻø� �˴ϴ�.

// 3. server ������ ��������.








#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. ������ �ڵ��� ��� �ɴϴ�.
	int server = ec_find_server("Calc");

	cout << "���� ��ȣ : " << server << endl;

	// 2. ������ ����ڵ�� �Ķ���͸� �����մϴ�.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	cout << n1 << ", " << n2 << endl;

}





