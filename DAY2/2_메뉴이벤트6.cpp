#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // 


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
	// std::bind : 인자를 고정한 또다른 함수를 만드는 함수
	f4(1, 2, 3, 4);

	std::bind(f4, 1, 2, 3, 4)();
	std::bind(f4, 3, _1, 6, _2)(10, 20);

}




