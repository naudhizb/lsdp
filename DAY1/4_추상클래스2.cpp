//1_추상클래스2.cpp
#include <iostream>
using namespace std;


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





