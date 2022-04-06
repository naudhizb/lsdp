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

// AddRef/Release �� �ڵ����� �����ϴ� ����Ʈ �����͸� ����� ���ô�.
template<typename T> class AutoPtr
{
	T* ptr;
public:
	AutoPtr(T* p = 0) : ptr(p) { if (ptr) ptr->AddRef();  }
	AutoPtr(const AutoPtr& ap) : ptr(ap.ptr) { if (ptr) ptr->AddRef();  }
	~AutoPtr() { if (ptr) ptr->Release(); }

	// ����Ʈ �������� �ٽ� : -> �� * ������ ������
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





