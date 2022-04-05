// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

// 1. 오직 한개의 객체만 생성할수있다.
// 2. 프로그램의 어디서든지 동일한 방법으로 접근하다.

class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자를 컴파일러가 만들지 못하게 한다.
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// 규칙 3. 오직 한개의 객체를 반환하는 static 멤버함수
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








