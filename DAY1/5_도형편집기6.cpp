// github.com/codenuri/lsdp

#include <iostream>
#include <vector>


class NotImplemented {};

class Shape
{
public:
	virtual ~Shape() {}  // 기반 클래스의 소멸자는 가상함수 이어야 한다.

	// 가상함수     : 재정의 하지 않으면 디폴트 구현을 제공하겠다는것
	// 순수가상함수 : 반드시 만들어야 한다고 지시하는것
	
	virtual void draw() = 0; // { std::cout << "draw shape" << std::endl; }

	// 만약 clone 이 자주사용되지 않으면
	// 1. 순수 가상함수 : 파생 클래스가 반드시 만들어라!
	// 2. 기본 구현에서 예외 발생 : 재정의 하지않았다면 사용하지도 말라는것
	virtual Shape* clone()
	{
		throw NotImplemented();
	}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	// 가상함수 재정의시 반환타입을 변경할수 있습니다.
	// 단, 상속관계타입으로만 가능
	Rect* clone() override
	{
		Rect* p = new Rect;
		return p;
	}
};
// Rect* p1 = new Rect;
// Rect* p2 = p1->clone();

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }

	Circle* clone() override
	{
		Circle* p = new Circle;
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);

		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); 
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성..
									 // k 번째 도형이 뭔지 알필요가 없다.
		}
	}
}


