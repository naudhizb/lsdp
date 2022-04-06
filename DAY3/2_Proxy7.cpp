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

// AddRef/Release 를 자동으로 관리하는 스마트 포인터를 만들어 봅시다.
template<typename T> class AutoPtr
{
	T* ptr;
public:
	AutoPtr(T* p = 0) : ptr(p) { if (ptr) ptr->AddRef();  }
	AutoPtr(const AutoPtr& ap) : ptr(ap.ptr) { if (ptr) ptr->AddRef();  }
	~AutoPtr() { if (ptr) ptr->Release(); }

	// 스마트 포인터의 핵심 : -> 와 * 연산자 재정의
	T* operator->() { return ptr; }
	T& operator*() { return *ptr; }
};

int main()
{
	AutoPtr<ICalc> p1 = ReloadProxy();
				// p1( ReloadProxy()) 

	AutoPtr<ICalc> p2 = p1;

	int n = p1->Add(10, 20);

	std::cout << n << std::endl;

}





