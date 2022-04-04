// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>

// 리팩토링 용어
// "replace conditional with polymorphism" 이라는 기법이 있습니다.
// => if, switch 문이 있다면 "가상함수"로 바꿀수 없는지 생각해 보자.. 

// 디자인 패턴 : 1994년 4명의 개발자가 기존에 존재 하던 디자인 기법이 이름을 붙인것

//  23개의 이름을 발표.. "GoF's Design Pattern" 책
//						 "Gangs Of Four"

// prototype pattern : 객체를 만들고, 복사본으로 새로운 객체를 만드는 기술
//					clone() 가상함수

class Shape
{
public:
	virtual void draw() { std::cout << "draw shape" << std::endl; }

	
	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		Shape* p = new Shape;
		// 자신과 완전히동일해 지도록 모든 멤버를 복사합니다.
		// p->color = color;
		return p;
	}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override 
	{
		Rect* p = new Rect;
		// 자신과 완전히동일해 지도록 모든 멤버를 복사합니다.
		// p->color = color;
		return p;
	}
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }

	Shape* clone() override
	{
		Circle* p = new Circle;
		// 자신과 완전히동일해 지도록 모든 멤버를 복사합니다.
		// p->color = color;
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

		// 도전과제 1. 객체의 생성을 OCP를 만족하게 할수없을까 ?
		// ==> 추상 팩토리 패턴을 알면 됩니다.

		// 도전과제 2. Undo/Redo 를 하려면 어떻게 해야 할까 ?
		// ==> Command 패턴 이라는 디자인 패턴을 사용하면 됩니다.

		if (cmd == 1) v.push_back(new Rect);

		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); // 다형성(polymorphism)				
							// 동일한 표현식이 상황(실제객체)에 따라 다르게 동작(다른함수호출)
			}
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() ); // 다형성..
									 // k 번째 도형이 뭔지 알필요가 없다.
		}
	}
}


