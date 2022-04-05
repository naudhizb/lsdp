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



class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	~PopupMenu()
	{
		for (int i = 0; i < v.size(); i++)
			delete v[i];  
	}

	void add_menu(BaseMenu* p) { v.push_back(p); }

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

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		// 메뉴 선택시 해당 기능을 수행해야 합니다.
		// 여기서 직접 코드를 작성하면 모든 메뉴가 동일한 일을 하게 됩니다.
		// 어떻게 할까요 ?
	}
};

int main()
{
	MenuItem m1("HD", 11);
	MenuItem m2("FHD", 12);

	m2.command(); // 메뉴 선택
}




