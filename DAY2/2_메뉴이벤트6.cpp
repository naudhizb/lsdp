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
	// std::bind : ���ڸ� ������ �Ǵٸ� �Լ��� ����� �Լ�
	f4(1, 2, 3, 4);

	std::bind(f4, 1, 2, 3, 4)(); // 1,2,3,4
								// 4�� �Լ� => �����Լ�

	std::bind(f4, 3, _1, 6, _2)(10, 20); // 4�� �Լ� => 2�� �Լ���
										// 3, 10, 6, 20


	std::bind(f4, ? )(5, 8, 3); // 8, 3, 9, 5 ������ �غ�����
}




