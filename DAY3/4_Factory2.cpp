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

	// �ڽ��� ����� static ��� �Լ��� ���� �θ� ���˴ϴ�.
	static Shape* Create()
	{
		return new Rect;
	}
};
// Rect�� ����� 2���� ���
// 1. ���� ����        : Rect* p = new Rect
// 2. static �Լ� ��� : Rect* p = Rect::Create()
/*
// �Լ� ���ڿ� ���� �ٸ� ������ ����� �ʹ�. �׷���.. �̷��� �¾ ������..
void Create( Shape*(*f)() )
{
	// ���ڿ� ���� �ٸ� ������ ������ �Ѵ�.
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

	typedef Shape*(*CREATOR)(); // �Լ������� Ÿ��

	std::map<int, CREATOR> create_map;
public:

	// ������ ���忡 ����ϴ� �Լ�
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

	// ���忡 ��ǰ(����)�� ���
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




