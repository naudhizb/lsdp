#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // _getch() �������..
using namespace std;


// list �湮�� : ����� Ÿ���� ���� �� ���հ�ü
// menu �湮�� : ����� Ÿ���� �ٸ� ���հ�ü�� �湮

class MenuItem;
class PopupMenu; // class ���漱��

struct IMenuVisitor
{
	virtual void Visit(MenuItem* p) = 0;
	virtual void Visit(PopupMenu* p) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void Accept(IMenuVisitor* v) = 0;
	virtual ~IAcceptor() {}
};

class BaseMenu : public IAcceptor 
{
	string title;
public:

	void setTitle(string s) { title = s; }
	string getTitle() const { return title; }

	BaseMenu(string s) : title(s) {}


	// ��� �޴��� ���õɼ� �ִ�.. ������ �Ļ�Ŭ��������!!
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	void Accept(IMenuVisitor* v) override
	{
		v->Visit(this); // �湮�ڿ��� �ڽ��� ����
	}
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " ���õ�" << endl;
		_getch();
	}
};



class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:

	void Accept(IMenuVisitor* visit) override
	{
		visit->Visit(this); // �湮�ڿ��� �ڽ��� ����

		// �ڽ��� ���� ��� �����޴��� �湮�ڸ�
		// �湮 ��Ų��.
		for (auto e : v)
			e->Accept(visit);
	}





	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size(); // ���� �޴� ����

			for (int i = 0; i < sz; i++)
			{
				printf("%d. %s\n", i + 1, v[i]->getTitle().c_str());
			}

			printf("%d. �����޴��� �̵�\n", sz + 1);

			printf("�޴��� �����ϼ��� >>");
			int cmd;
			cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			if (cmd == sz + 1) // ���� �޴��� ����
				break;

			v[cmd - 1]->command(); // ������

		}
	}
};

// popupmenu �� Ÿ��Ʋ�� �����ϴ� �湮��
struct PopupMenuTitleChangeVisitor : public IMenuVisitor
{
	void Visit(MenuItem* p) override {}
	void Visit(PopupMenu* p) override 
	{
		std::string s = p->getTitle();
		s = "[ " + s + " ]";
		p->setTitle(s);
	}
};

int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("���� ����");
	PopupMenu* p2 = new PopupMenu("�ػ� ����");

	menubar->addMenu(p1);
//	menubar->addMenu(p2);
	p1->addMenu(p2);

	p1->addMenu(new MenuItem("RED", 11));
	p1->addMenu(new MenuItem("GREEN", 12));
	p1->addMenu(new MenuItem("BLUE", 13));
	p1->addMenu(new MenuItem("BLACK", 14));

	p2->addMenu(new MenuItem("HD", 21));
	p2->addMenu(new MenuItem("FHD", 22));
	p2->addMenu(new MenuItem("UHD", 23));

	PopupMenuTitleChangeVisitor tc;
	menubar->Accept(&tc);


	// �����Ϸ����� �ұ�� ?
	menubar->command();
}







