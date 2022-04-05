// 3_Command 
#include <iostream>
#include <vector>
#include <stack>

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
};
class Circle : public Shape
{
public:
	void Draw() override { std::cout << "Draw Circle" << std::endl; }
};


//-----------------------
// ���α׷����� ����ϴ� ��� ����� ĸ��ȭ �Ѵ�.
struct ICommand
{
	virtual void Execute() = 0;
	virtual void Undo() {}
	virtual bool CanUndo() { return false; }
	virtual ~ICommand() {}
};
// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;   // �ݵ�� reference ��
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override {}
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;
		if (cmd == 1) 
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2) 
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
	}
}


