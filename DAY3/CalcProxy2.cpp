// CalcProxy.cpp

#define USING_GUI
#include "cppmaster.h"
#include "ICalc2.h"
#include <atomic>

class CalcProxy : public ICalc
{
	int server;
	std::atomic<int> refCount = 0;
public:
	~CalcProxy() { std::cout << "~CalcProxy" << std::endl; }

	void AddRef() { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	CalcProxy() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};


extern "C" __declspec(dllexport)
ICalc* CreateProxy()
{
	return new CalcProxy;
}




