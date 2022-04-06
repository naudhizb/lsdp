#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		typedef Shape*(*CREATOR)();

	std::map<int, CREATOR> create_map;
public:

	void RegisterShape(int type, CREATOR f)
	{
		create_map[type] = f;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if (create_map[type] != 0)
			p = create_map[type]();
		return p;
	}
};

struct AutoRegister
{
	AutoRegister( int type, Shape*(*f)() )
	{
		ShapeFactory::getInstance().RegisterShape(type, f);
	}
};

//AutoRegister ar(1, &Rect::Create); 





class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	static Shape* Create()
	{
		return new Rect;
	}
	// static 멤버 데이타의 특징을 잘생각해 보세요.
	// => 객체를 생성하지 않아도 메모리에 놓이게 됩니다
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);







class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != 0)
				v.push_back(p);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->Draw();
			}
		}
	}
}




