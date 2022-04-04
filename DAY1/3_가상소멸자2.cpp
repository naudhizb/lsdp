// 3_����Ҹ���
#include <iostream>

class Base
{
	// ���� �Ҹ��ڸ� ������� �ʱ� ���ؼ� ����ϴ� ���
	// protected �Ҹ���.
protected:
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
	Base* p = new Derived; 
//	delete p;  // error. ~Base()�� protected �̹Ƿ�..�ܺο��� ����ȣ��ȵ�
	delete static_cast<Derived*>(p); // ok

	// void* => int*
//	int* p = static_cast<int*>(malloc(100));
}