//1_추상클래스2.cpp
#include <iostream>
using namespace std;


// 강한 결합( tightly coupling )
// 하나의 클래스가 다른 클래스 사용시
// 클래스이름을 직접 사용하는 것

// 교체 불가능한, 경직된 디자인, 확장성이 없다.

// OCP 만족 못함

class Camera
{
public:	
	void Take() { cout << "Take Picture" << endl; }
};

class HDCamera
{
public:
	void Take() { cout << "Take HD Picture" << endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);
}





