#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// Composite ����
// ���հ�ü(PopupMenu)�� ������ü(MenuItem)�� ����������
// ���հ�ü(PopupMenu) �ڽŵ� �����Ҽ� �ִ�.
// => ���հ�ü�� ������ü�� ���� ��� Ŭ������ �ʿ��ϴ�.
// => ���հ�ü�� ������ ��� Ŭ����(BaseMenu)�� �����ؾ� �Ѵ�.

// ���հ�ü�� ������ü�� ������ �����ϴ�.
// => ��� �޴��� ���ý� command()�� ȣ��ȴ�.
// => command()�� ������ ��� Ŭ������ �־�� �Ѵ�.

// ��ü�� ���谡 tree ������ ������ �ȴ�.

// ��� �޴��� ������ ��� Ŭ���� ����
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
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	~PopupMenu()
	{
		for (int i = 0; i < v.size(); i++)
			delete v[i];   // �� ��찡
							// delete "���Ŭ����������"
	}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	// popup �޴� ���ý� �ؾ� ������ ������ ������
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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* p1 = new PopupMenu("�ػ󵵺���");
	PopupMenu* p2 = new PopupMenu("���󺯰�");

	root->add_menu(p1);
	//	root->add_menu(p2);
	p1->add_menu(p2);

	p1->add_menu(new MenuItem("HD", 11));
	p1->add_menu(new MenuItem("FHD", 12));
	p1->add_menu(new MenuItem("UHD", 13));

	p2->add_menu(new MenuItem("RED", 21));
	p2->add_menu(new MenuItem("GREEN", 22));
	p2->add_menu(new MenuItem("BLUE", 23));

	// ���� �����Ϸ��� ?
	root->command();

	delete root;
}




