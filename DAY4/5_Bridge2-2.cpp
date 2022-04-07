// PIMPL �̶�� �̸��� ��� ( Pointer to IMPLementation )
// ������ �ð� Bridge ���� Ȱ��
// 1. ������ �ӵ��� ������ �ϰ�
// 2. ������ ��� ������ ������ ����� �ִ�.

// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } // ���� ����

// Bridge
// Point.h
class PointImpl; // ���漱��������
				// ������ ������ ��밡��
class Point
{
	PointImpl* pimpl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { pimpl = new PointImpl; }
void Point::print() { pimpl->print(); }




// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


