// 3_���������� - 15 page
#include <iostream>
#include <vector>

// �����丵 ���
// "replace conditional with polymorphism" �̶�� ����� �ֽ��ϴ�.
// => if, switch ���� �ִٸ� "�����Լ�"�� �ٲܼ� ������ ������ ����.. 

// ������ ���� : 1994�� 4���� �����ڰ� ������ ���� �ϴ� ������ ����� �̸��� ���ΰ�

//  23���� �̸��� ��ǥ.. "GoF's Design Pattern" å
//						 "Gangs Of Four"

// prototype pattern : ��ü�� �����, ���纻���� ���ο� ��ü�� ����� ���
//					clone() �����Լ�

class Shape
{
public:
	virtual void draw() { std::cout << "draw shape" << std::endl; }

	
	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� ���˴ϴ�.
	virtual Shape* clone()
	{
		Shape* p = new Shape;
		// �ڽŰ� ������������ ������ ��� ����� �����մϴ�.
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
		// �ڽŰ� ������������ ������ ��� ����� �����մϴ�.
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
		// �ڽŰ� ������������ ������ ��� ����� �����մϴ�.
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

		// �������� 1. ��ü�� ������ OCP�� �����ϰ� �Ҽ������� ?
		// ==> �߻� ���丮 ������ �˸� �˴ϴ�.

		// �������� 2. Undo/Redo �� �Ϸ��� ��� �ؾ� �ұ� ?
		// ==> Command ���� �̶�� ������ ������ ����ϸ� �˴ϴ�.

		if (cmd == 1) v.push_back(new Rect);

		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); // ������(polymorphism)				
							// ������ ǥ������ ��Ȳ(������ü)�� ���� �ٸ��� ����(�ٸ��Լ�ȣ��)
			}
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() ); // ������..
									 // k ��° ������ ���� ���ʿ䰡 ����.
		}
	}
}


