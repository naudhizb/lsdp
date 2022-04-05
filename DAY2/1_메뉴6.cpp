#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// Composite 패턴
// 복합객체(PopupMenu)는 개별객체(MenuItem)를 포함하지만
// 복합객체(PopupMenu) 자신도 포함할수 있다.
// => 복합객체와 개별객체는 같은 기반 클래스가 필요하다.
// => 복합객체는 공통의 기반 클래스(BaseMenu)를 포함해야 한다.

// 복합객체와 개별객체는 사용법이 동일하다.
// => 모든 메뉴는 선택시 command()가 호출된다.
// => command()의 선언은 기반 클래스에 있어야 한다.

// 객체의 관계가 tree 구조를 가지게 된다.

// 모든 메뉴의 공통의 기반 클래스 설계
class BaseMenu
{
	std::string title;
public:
	virtual ~BaseMenu() {}

	BaseMenu(const std::string& s) : title(s) {}
	std::string get_title() const { return title; }

	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << get_title() << " 선택" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	~PopupMenu()
	{
		for (int i = 0; i < v.size(); i++)
			delete v[i];   // 이 경우가
							// delete "기반클래스포인터"
	}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	// popup 메뉴 선택시 해야 할일을 생각해 보세요
	void command()
	{
		while (1)
		{
			system("cls");
			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1) // 종료
				break;

			// 선택된 메뉴 실행
			v[cmd - 1]->command();

		}


	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("해상도변경");
	PopupMenu* p2 = new PopupMenu("색상변경");

	root->add_menu(p1);
	//	root->add_menu(p2);
	p1->add_menu(p2);

	p1->add_menu(new MenuItem("HD", 11));
	p1->add_menu(new MenuItem("FHD", 12));
	p1->add_menu(new MenuItem("UHD", 13));

	p2->add_menu(new MenuItem("RED", 21));
	p2->add_menu(new MenuItem("GREEN", 22));
	p2->add_menu(new MenuItem("BLUE", 23));

	// 이제 시작하려면 ?
	root->command();

	delete root;
}




