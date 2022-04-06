#define USING_GUI
#include "cppmaster.h"

// ���� Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// 1. ICalc.h 
// 2. CalcProxy.dll 

#include "ICalc.h" // �������̽��� ��� ����� �ҽ��� �����ϰ�
int main()
{
	// DLL�� Load�ؼ� ��ӵ� �Լ��� ȣ���ϸ� Proxy�� �����˴ϴ�.
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");

	ICalc* pCalc = f();

	std::cout << pCalc->Add(10, 20) << std::endl;

}





