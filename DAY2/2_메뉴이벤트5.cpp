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
	// 1. �Ϲ��Լ� �����Ϳ� ��� �Լ� �ּҸ� ������ �����ϴ�.
	void(*f1)() = &foo; //  ok
//	void(*f2)() = &Camera::take; //  error

	// 2. ��� �Լ��� �ּҴ� ��� �Լ� �����Ϳ� ��ƾ� �մϴ�.
	void(Camera::*f3)() = &Camera::take; //

	f1(); // �Լ������ͷ� �Լ� ȣ��

	f3(); //?error. ��ü������.   ����Լ��� "cam.take()"

	Camera cam;
//	cam.f3(); // error

	(cam.*f3)(); // ok
}




