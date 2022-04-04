// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>

// 핵심 3. 모든 파생 클래스(도형)의 공통의 특징은 반드시 기반 클래스(Shape)에도
//         있어야 한다.
//         그래야, Shape* 로 모든 도형을 묶을때 해당 특징을 사용할수 있다.

class Shape
{
public:
	void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
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
				v[i]->draw();
		}
	}
}


