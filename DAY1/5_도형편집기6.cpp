// github.com/codenuri/lsdp

#include <iostream>
#include <vector>


class NotImplemented {};

class Shape
{
public:
	virtual ~Shape() {}  // ��� Ŭ������ �Ҹ��ڴ� �����Լ� �̾�� �Ѵ�.

	// �����Լ�     : ������ ���� ������ ����Ʈ ������ �����ϰڴٴ°�
	// ���������Լ� : �ݵ�� ������ �Ѵٰ� �����ϴ°�
	
	virtual void draw() = 0; // { std::cout << "draw shape" << std::endl; }

	// ���� clone �� ���ֻ����� ������
	// 1. ���� �����Լ� : �Ļ� Ŭ������ �ݵ�� ������!
	// 2. �⺻ �������� ���� �߻� : ������ �����ʾҴٸ� ��������� ����°�
	virtual Shape* clone()
	{
		throw NotImplemented();
	}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	// �����Լ� �����ǽ� ��ȯŸ���� �����Ҽ� �ֽ��ϴ�.
	// ��, ��Ӱ���Ÿ�����θ� ����
	Rect* clone() override
	{
		Rect* p = new Rect;
		return p;
	}
};
// Rect* p1 = new Rect;
// Rect* p2 = p1->clone();

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }

	Circle* clone() override
	{
		Circle* p = new Circle;
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

		if (cmd == 1) v.push_back(new Rect);

		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); 
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // ������..
									 // k ��° ������ ���� ���ʿ䰡 ����.
		}
	}
}


