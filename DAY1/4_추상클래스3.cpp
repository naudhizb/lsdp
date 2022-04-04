//1_�߻�Ŭ����2.cpp
#include <iostream>
using namespace std;



// ī�޶� ���� ������ ����
// ����� ī�޶� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �Ѵ�.

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�"
//			==> "��� ī�޶�� take() �� ������ ����Ҽ� �ִ�.

class ICamera
{
public:
	virtual void take() = 0;
};

// ��¥ī�޶�� ������ ��Ģ��� ����ϸ� �ȴ�.
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





