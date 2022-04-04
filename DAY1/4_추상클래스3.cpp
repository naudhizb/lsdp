//1_추상클래스2.cpp
#include <iostream>
using namespace std;



// 카메라를 먼저 만들지 말고
// 사람과 카메라 사이에 지켜야 하는 규칙을 먼저 설계 한다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다"
//			==> "모든 카메라는 take() 를 만들어야 사용할수 있다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 진짜카메라는 없지만 규칙대로 사용하면 된다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};



class Camera : public ICamera
{
public:
	void take() { cout << "Take Picture" << endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { cout << "Take HD Picture" << endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);
}





