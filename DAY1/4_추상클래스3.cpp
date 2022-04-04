//1_�߻�Ŭ����2.cpp
#include <iostream>
using namespace std;



// ���� ����(loosely coupling)
// �ϳ��� Ŭ������ �ٸ� Ŭ���� ����
// ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� ����ؼ� �����ϴ°�

// �������ϰ�, Ȯ�强 �ִ� ������..

// �������̽� : ���Ѿ��ϴ� ��Ģ�� ����
// �߻�Ŭ���� : ���Ѿ��ϴ� ��Ģ + �ٸ� ����� ����

// C#, java, swift : �������̽��� ���� ������ Ű���� ����(interface, protocol��)
// C++             : �������̽��� �߻� Ŭ������������ ���� 

// ī�޶� ���� ������ ����
// ����� ī�޶� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �Ѵ�.

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�" ��� ���� ����
//			==> "��� ī�޶�� take() �� ������ ����Ҽ� �ִ�.

//          "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�."
//							"�Ʒ� ���������� �ؼ��ؾ� �Ѵ�.(swift)"

#define  interface struct

//struct ICamera
interface ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}    // �������̽��� �ᱹ ��� Ŭ���� �Դϴ�.
							// ���� �Ҹ��� �ʿ�
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





