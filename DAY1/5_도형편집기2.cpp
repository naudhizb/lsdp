// 3_도형편집기 - 15 page
#include <iostream>
#include <vector>


class Shape
{
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
// 왜 위 코드가 에러일까요 ? 해결책은 뭘까요 ?

