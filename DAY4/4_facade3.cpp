#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// 단일 책임의 원칙 (Single Reponsibility Principle)
// 하나의 클래스는 하나의 책임만
// SRP


class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};
// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// 하위 계층의 복잡함을 단순화 하는 상위 레벨의 계층을 제공해라.
class TCPServer
{
	NetworkInit init;

//	Socket sock{ SOCK_STREAM }
	Socket sock;
public:
	TCPServer() : sock(SOCK_STREAM) {}

	void Start(const char* ip, short port )
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	TCPServer server;
	server.Start("127.0.0.1", 4000);

}

//-------------------
/*
int n(0); // ok

struct Point
{
//	int x = 0; // C++11
/	int z(0); // error 구조체 멤버 초기화시 
	int y{ 0 }; // 
};
*/
