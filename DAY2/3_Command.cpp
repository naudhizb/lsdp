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
// 프로그램에서 사용하는 모든 명령을 캡슐화 한다.
struct ICommand
{
	virtual void Execute() = 0;
	virtual void Undo() {}
	virtual bool CanUndo() { return false; }
	virtual ~ICommand() {}
};
// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;   // 반드시 reference 로
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(new Rect); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;   // 반드시 reference 로
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override { v.push_back(new Circle); }
	bool CanUndo() override { return true; }
	void Undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;   
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void Execute() override 
	{
		for (auto p : v) p->Draw();
	}

	bool CanUndo() override { return true; }
	void Undo() override
	{
		system("cls");
	}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;

	ICommand* pCmd = 0;
	
	while (1)
	{
		int cmd;
		std::cin >> cmd;
		if (cmd == 1) 
		{
			pCmd = new AddRectCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 2) 
		{
			pCmd = new AddCircleCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 9)
		{
			pCmd = new DrawCommand(v);
			pCmd->Execute();
			cmd_stack.push(pCmd);
		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				pCmd = cmd_stack.top();
				cmd_stack.pop();

				if (pCmd->CanUndo())
					pCmd->Undo();
			}
		}
	}
}


