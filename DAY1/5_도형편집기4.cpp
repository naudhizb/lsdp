// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>

// 핵심 5. OCP
// 기능확장에 열려있고(Open, 클래스가 나중에 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 해야 한다는 원칙(Principle )

// Open Close Principle(개방폐쇄의 법칙)

// 객체지향 설계의 5가지 원칙 : SOLID ( SRP, OCP, LSP, ISP, DIP)

// 다형성은 OCP를 만족하는 설계이다.


class Shape
{
public:
	int type;
	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	Rect() { type = 1; }
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw triangle" << std::endl; }
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

			// k번째 도형의 복제본을 만들어서 v 끝에 추가합니다.
			// 그런데, k번째 도형이 뭘까요 ?

			// 아래 처럼 만들면 OCP를 만족 할수 없습니다.
			// 객체지향 세계에서는 권장하지 않는 코드
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect(*v[k])); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
		}
	}
}


