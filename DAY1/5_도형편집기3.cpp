// 3_���������� - 15 page
#include <iostream>
#include <vector>

// �ٽ� 3. ��� �Ļ� Ŭ����(����)�� ������ Ư¡�� �ݵ�� ��� Ŭ����(Shape)����
//         �־�� �Ѵ�.
//         �׷���, Shape* �� ��� ������ ������ �ش� Ư¡�� ����Ҽ� �ִ�.

// �ٽ� 4. ��� Ŭ���� �Լ��� �Ļ� Ŭ������  ������ �ϴ� �Լ���
//			�ݵ�� �����Լ��� �Ǿ�� �Ѵ�.

class Shape
{
public:
	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
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


