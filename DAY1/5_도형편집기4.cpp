// 3_���������� - 15 page
#include <iostream>
#include <vector>

// �ٽ� 5. OCP
// ���Ȯ�忡 �����ְ�(Open, Ŭ������ ���߿� �߰��Ǿ)
// �ڵ� �������� ���� �־��(Close, ���� �ڵ�� �������� �ʵ���)
// �ؾ� �Ѵٴ� ��Ģ(Principle )

// Open Close Principle(��������� ��Ģ)

// ��ü���� ������ 5���� ��Ģ : SOLID ( SRP, OCP, LSP, ISP, DIP)

// �������� OCP�� �����ϴ� �����̴�.


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
				v[i]->draw(); // ������(polymorphism)				
							// ������ ǥ������ ��Ȳ(������ü)�� ���� �ٸ��� ����(�ٸ��Լ�ȣ��)
			}
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";
			
			int k;
			std::cin >> k;

			// k��° ������ �������� ���� v ���� �߰��մϴ�.
			// �׷���, k��° ������ ����� ?

			// �Ʒ� ó�� ����� OCP�� ���� �Ҽ� �����ϴ�.
			// ��ü���� ���迡���� �������� �ʴ� �ڵ�
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect(*v[k])); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
		}
	}
}


