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
//	Derived d;
	
	// �Ʒ� �ڵ��� ����� ������ ������
	Base* p = new Derived; // 1. Derived ũ���� �޸��Ҵ�
						   // 2. Derived ������ ȣ��
						
	delete p; // 1. �Ҹ��� ȣ��
			  // 2. �޸� ����

	// delete p�Ҷ�
	// 1. �����Ϸ��� p�� Base*�̹Ƿ� BaseŬ�������� �Ҹ��ڰ� �������� ����
	// A. �Ҹ��ڰ� ������ �ƴϸ� "p�� Base Ÿ�� �̹Ƿ� ������ Base �Ҹ��ڸ� ȣ��"
	// B. �Ҹ��ڰ� �����̸� "p�� ����Ű�� ���� �����ϴ� ���� �ڵ� ������
	//		����ð��� p�� ����Ű�� �޸������� �Ҹ��� ȣ��

	// ��� : ����� ��� Ŭ������ ���Ǵ� ��� Ŭ������ �Ҹ��ڴ�
	//	    �����Լ� �̾�� �Ѵ�
}