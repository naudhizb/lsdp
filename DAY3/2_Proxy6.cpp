#define USING_GUI
#include "cppmaster.h"
#include "ICalc2.h" 

typedef ICalc*(*F)();

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy2.dll");

	F f = (F)ec_get_function_address(addr, "CreateProxy");
	return f();
}
int main()
{
	ICalc* pCalc = ReloadProxy();
	pCalc->AddRef();

	std::cout << pCalc->Add(10, 20) << std::endl;

	ICalc* pCalc2 = pCalc;
	pCalc2->AddRef();

	pCalc->Release(); // ÆÄ±« ¾ÈµÊ
	std::cout << "----" << std::endl;
	pCalc2->Release(); // ÆÄ±«.
}





