// 1. VC++ 한 개 더실행해서 "server" 프로젝트 열어 보세요

// 2. sdk 버전 맞추고, "X86", "Debug" 로 빌드하시면 됩니다.

// 3. server 실행해 놓으세요.








#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	cout << "서버 번호 : " << server << endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	cout << n1 << ", " << n2 << endl;

}





