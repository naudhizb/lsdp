// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

// 1. 오직 한개의 객체만 생성할수있다.
// 2. 프로그램의 어디서든지 동일한 방법으로 접근하다.

// 비판론자 : 결국 전역변수이다... 전역변수는 좋지 않다.

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








