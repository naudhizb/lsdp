// 1_추상클래스1.cpp - 10page
// 추상클래스 : 순수 가상함수가 한개 이상있는 클래스.
// 의도 : 파생 클래스가 특정 함수를 반드시 만들라고 지시하는 것
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)	
							// 구현이 없다.
};

class Rect : public Shape
{
	// Draw() 의 구현을 제공하지 않으면 "추상 클래스"
	//                  제공하면 추상클래스 아님.
};

int main()
{
	Shape s; // error. 객체를 만들수 없다.
	Shape* p; // ok. 포인터 생성은 가능.
	Rect  r;
}
