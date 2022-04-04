// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>


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


