//1_추상클래스2.cpp
#include <iostream>
using namespace std;



// 약한 결합(loosely coupling)
// 하나의 클래스가 다른 클래스 사용시
// 규칙을 담은 인터페이스(추상클래스)를 사용해서 접근하는것

// 유연성하고, 확장성 있는 디자인..

// 인터페이스 : 지켜야하는 규칙만 제공
// 추상클래스 : 지켜야하는 규칙 + 다른 멤버도 제공

// C#, java, swift : 인터페이스를 위한 별도의 키워드 제공(interface, protocol등)
// C++             : 인터페이스도 추상 클래스문법으로 만듬 

// 카메라를 먼저 만들지 말고
// 사람과 카메라 사이에 지켜야 하는 규칙을 먼저 설계 한다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다" 라고 하지 말고
//			==> "모든 카메라는 take() 를 만들어야 사용할수 있다.

//          "모든 카메라는 아래 인터페이스를 구현해야 한다."
//							"아래 프로토콜을 준수해야 한다.(swift)"

#define  interface struct

//struct ICamera
interface ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}    // 인터페이스도 결국 기반 클래스 입니다.
							// 가상 소멸자 필요
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

class UHDCamera : public ICamera
{
public:
	void take() { cout << "Take UHD Picture" << endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);

	UHDCamera uhc;
	p.useCamera(&uhc);
}





