#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <memory>  // ����Ʈ �����͸� ���� ��� (C++11����)

// Type* => std::shared_ptr<Type> ���� �����ϸ� �˴ϴ�.

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
		std::cout << get_title() << " ����" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector< std::shared_ptr<BaseMenu> > v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}


	void add_menu( std::shared_ptr<BaseMenu>  p) { v.push_back(p); }

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
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1) // ����
				break;

			// ���õ� �޴� ����
			v[cmd - 1]->command();

		}


	}
};

int main()
{
//	PopupMenu* root = new PopupMenu("ROOT");
//	std::shared_ptr<PopupMenu> root = new PopupMenu("ROOT"); // error
//	std::shared_ptr<PopupMenu> root(new PopupMenu("ROOT")); // ok

	std::shared_ptr<PopupMenu> root = std::make_shared<PopupMenu>("ROOT"); //ok


	// �Ʒ� 2�� ��� �����ѵ�, p2�� ���� �����ϴ�.
	std::shared_ptr<PopupMenu> p1 (new PopupMenu("�ػ󵵺���"));
	std::shared_ptr<PopupMenu> p2 = std::make_shared<PopupMenu>("���󺯰�");

	root->add_menu(p1);
	root->add_menu(p2);

	p1->add_menu(std::make_shared<MenuItem>("HD", 11));
	p1->add_menu(std::make_shared<MenuItem>("FHD", 12));
	p1->add_menu(std::make_shared<MenuItem>("UHD", 13));

	p2->add_menu(std::make_shared<MenuItem>("RED", 21));
	p2->add_menu(std::make_shared<MenuItem>("GREEN", 22));
	p2->add_menu(std::make_shared<MenuItem>("BLUE", 23));

	root->command();
}




