#define USING_GUI
#include "cppmaster.h"

// 이제 클라이언트 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// 1. ICalc.h 
// 2. CalcProxy.dll 

#include "ICalc.h" // 인터페이스가 담긴 헤더는 소스에 포함하고
int main()
{
	// DLL를 Load해서 약속된 함수를 호출하면 Proxy가 생성됩니다.
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");

	ICalc* pCalc = f();

	std::cout << pCalc->Add(10, 20) << std::endl;

}





