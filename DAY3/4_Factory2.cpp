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

class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	// 자신을 만드는 static 멤버 함수는 아주 널리 사용됩니다.
	static Shape* Create()
	{
		return new Rect;
	}
};
// Rect를 만드는 2가지 방법
// 1. 직접 생성        : Rect* p = new Rect
// 2. static 함수 사용 : Rect* p = Rect::Create()
/*
// 함수 인자에 따라 다른 도형을 만들고 싶다. 그런데.. 미래에 태어날 도형도..
void Create( Shape*(*f)() )
{
	// 인자에 따라 다른 도형을 만들어야 한다.
	Shape* p = f();
}
//-----------
Create(&Triange::Create );
*/








class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}
};




class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	typedef Shape*(*CREATOR)(); // 함수포인터 타입

	std::map<int, CREATOR> create_map;
public:

	// 도형을 공장에 등록하는 함수
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


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품(도형)을 등록
	factory.RegisterShape(1, &Rect::Create);
	factory.RegisterShape(2, &Circle::Create);


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




