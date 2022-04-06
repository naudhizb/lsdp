#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void Draw() = 0;
	virtual Shape* Clone() = 0;

	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	virtual Shape* Clone() { return new Rect(*this); }

	void Draw() override { std::cout << "Draw Rect" << std::endl; }

	static Shape* Create()
	{
		return new Rect;
	}
};

class Circle : public Shape
{
public:
	virtual Shape* Clone() { return new Circle(*this); }

	void Draw() override { std::cout << "Draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;
public:

	void RegisterSample(int type, Shape* p)
	{
		prototype_map[type] = p;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if (prototype_map[type] != 0)
			p = prototype_map[type]->Clone();
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	// ���忡 ��ǰ(����)�� ���
	// 1. �Ʒ� �ڵ�� ���忡 Ŭ������ ����ϴ� �ǹ��� �ڵ�
//	factory.RegisterShape(1, &Rect::Create);
//	factory.RegisterShape(2, &Circle::Create);

	Rect* redRect = new Rect; // ������ ũ��5��� ����
	Rect* blueRect = new Rect; 
	Circle* circle = new Circle;

	// ���忡 �ߺ� ��ü ��ǰ ���
	factory.RegisterSample(1, redRect);
	factory.RegisterSample(2, blueRect);
	factory.RegisterSample(3, circle);


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




