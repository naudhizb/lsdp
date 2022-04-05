// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

// 1. ���� �Ѱ��� ��ü�� �����Ҽ��ִ�.
// 2. ���α׷��� ��𼭵��� ������ ������� �����ϴ�.

// ���Ƿ��� : �ᱹ ���������̴�... ���������� ���� �ʴ�.

/*
#define MAKE_SINGLETON(classname )					\
private:											\
	classname() {}									\
	classname(const classname&) = delete;			\
	void operator=(const classname&) = delete;		\
public:												\
	static classname& getInstance()					\
	{												\
		static classname instance;					\
		return instance;							\
	}												\
private:										
*/
#include "helper.h"

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








