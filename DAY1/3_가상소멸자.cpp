// 3_����Ҹ���
#include <iostream>

class Base
{
public:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "�ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "�ڿ�����" << std::endl; }
};
int main()
{
	Derived;
}