// 3_가상소멸자
#include <iostream>

class Base
{
	// 가상 소멸자를 사용하지 않기 위해서 사용하는 기법
	// protected 소멸자.
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "자원할당" << std::endl; }
	~Derived() { std::cout << "자원해지" << std::endl; }
};

int main()
{
	Base* p = new Derived; 
//	delete p;  // error. ~Base()가 protected 이므로..외부에서 직접호출안됨
	delete static_cast<Derived*>(p); // ok

	// void* => int*
//	int* p = static_cast<int*>(malloc(100));
}