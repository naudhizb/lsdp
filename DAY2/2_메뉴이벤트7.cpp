#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // 
using namespace std::placeholders; //  _1, _2, _3 ....


void f0() { std::cout << "f0" << std::endl; }
void f1(int a) {}
void f2(int a, int b) {}
void f3(int a, int b, int c) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	// C언어의 함수 포인터는 너무 불편합니다
	void(*f)() = &f0; // ok
//	void(*f)() = &f1; // error. 함수 모양이 다릅니다.

	// C++ function 이 아주 좋습니다.
	std::function<void()> fp;

	fp = &f0;
	fp(); // ok.. f0()

	fp = std::bind(&f1, 5);
	fp(); // f1(5)

	fp = std::bind(&f2, ? );
	fp(); // f2(5,30)

	std::function<void(int)> fp2;

	fp2 = std::bind(&f4, ? );
	fp2(5); // f4(3, 7, 5, 9);
}




