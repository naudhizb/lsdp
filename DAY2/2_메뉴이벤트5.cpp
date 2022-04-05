#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

void foo() { std::cout << "foo" << std::endl; }

class Camera
{
public:
	void take() {}
};

int main()
{
	// 1. 일반함수 포인터에 멤버 함수 주소를 담을수 없습니다.
	void(*f1)() = &foo; //  ok
//	void(*f2)() = &Camera::take; //  error

	// 2. 멤버 함수의 주소는 멤버 함수 포인터에 담아야 합니다.
	void(Camera::*f3)() = &Camera::take; //

	f1(); // 함수포인터로 함수 호출

	f3(); //?error. 객체가없다.   멤버함수는 "cam.take()"

	Camera cam;
//	cam.f3(); // error

	(cam.*f3)(); // ok
}




