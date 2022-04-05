// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

// 1. ���� �Ѱ��� ��ü�� �����Ҽ��ִ�.
// 2. ���α׷��� ��𼭵��� ������ ������� �����ϴ�.

// ���Ƿ��� : �ᱹ ���������̴�... ���������� ���� �ʴ�.

// meyer's singleton
// => effecitive -C++�� ������ scott mayer �� ���� �ڵ�
//    ���� �Ǹ��ϰ�, ��Ƽ�����忡�� �����մϴ�.

class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. ���� �����ڿ� ���Կ����ڸ� �����Ϸ��� ������ ���ϰ� �Ѵ�.
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// ��Ģ 3. ���� �Ѱ��� ��ü�� ��ȯ�ϴ� static ����Լ�
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};


int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1;
}








