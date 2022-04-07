// PIMPL 이라는 이름의 기술 ( Pointer to IMPLementation )
// 컴파일 시간 Bridge 패턴 활용
// 1. 컴파일 속도를 빠르게 하고
// 2. 배포시 헤더 파일의 내용을 감출수 있다.

// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } // 구현 생략

// Bridge
// Point.h
class PointImpl; // 전방선언만있으면
				// 포인터 변수는 사용가능
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


