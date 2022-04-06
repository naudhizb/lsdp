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
	AutoRegister(int type, Shape*(*f)())
	{
		ShapeFactory::getInstance().RegisterShape(type, f);
	}
};

#define DECLARE_SHAPE(classname)							\
	static Shape* Create() { return new classname; }		\
	static AutoRegister ar;

#define REGISTER_SHAPE(no, classname)		\
	AutoRegister classname::ar(no, &classname::Create);
	
class Rect : public Shape
{
public:
	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)








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




