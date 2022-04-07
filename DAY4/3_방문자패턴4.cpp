#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // _getch() 사용위해..
using namespace std;


// list 방문자 : 요소의 타입이 동일 한 복합객체
// menu 방문자 : 요소의 타입이 다른 복합객체를 방문

class MenuItem;
class PopupMenu; // class 전방선언

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


	// 모든 메뉴는 선택될수 있다.. 구현은 파생클래스에서!!
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	void Accept(IMenuVisitor* v) override
	{
		v->Visit(this); // 방문자에게 자신을 전달
	}
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " 선택됨" << endl;
		_getch();
	}
};



class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:

	void Accept(IMenuVisitor* visit) override
	{
		visit->Visit(this); // 방문자에게 자신을 전달

		// 자신이 가진 모든 하위메뉴에 방문자를
		// 방문 시킨다.
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

			int sz = v.size(); // 하위 메뉴 갯수

			for (int i = 0; i < sz; i++)
			{
				printf("%d. %s\n", i + 1, v[i]->getTitle().c_str());
			}

			printf("%d. 상위메뉴로 이동\n", sz + 1);

			printf("메뉴를 선택하세요 >>");
			int cmd;
			cin >> cmd;


			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			if (cmd == sz + 1) // 상위 메뉴로 선택
				break;

			v[cmd - 1]->command(); // 다형성

		}
	}
};

// popupmenu 의 타이틀만 변경하는 방문자
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
	PopupMenu* p1 = new PopupMenu("색상 변경");
	PopupMenu* p2 = new PopupMenu("해상도 변경");

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


	// 시작하려면어떻게 할까요 ?
	menubar->command();
}







