// 3_가상소멸자
#include <iostream>

class Base
{
public:
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
//	Derived d;
	
	// 아래 코드의 결과를 생각해 보세요
	Base* p = new Derived; // 1. Derived 크기의 메모리할당
						   // 2. Derived 생성자 호출
						
	delete p; // 1. 소멸자 호출
			  // 2. 메모리 해지

	// delete p할때
	// 1. 컴파일러는 p가 Base*이므로 Base클래스에서 소멸자가 가상인지 조사
	// A. 소멸자가 가상이 아니면 "p가 Base 타입 이므로 무조건 Base 소멸자만 호출"
	// B. 소멸자가 가상이면 "p가 가리키는 곳을 조사하는 기계어 코드 생성후
	//		실행시간에 p가 가리키는 메모리조사후 소멸자 호출

	// 결론 : 상속의 기반 클래스로 사용되는 모든 클래스의 소멸자는
	//	    가상함수 이어야 한다
}