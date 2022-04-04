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
	Derived;
}