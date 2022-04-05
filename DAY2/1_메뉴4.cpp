
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��� �޴��� ������ ��� Ŭ���� ����
class BaseMenu
{
	std::string title;
public:
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
	MenuItem m1("��ġ���", 11);
	MenuItem m2("�Ұ����", 12);

	PopupMenu kimbam("����");
	kimbam.add_menu(&m1);
	kimbam.add_menu(&m2);


	MenuItem m3("����", 21);
	MenuItem m4("���", 22);

	PopupMenu pm("������ �޴�");
	pm.add_menu(&kimbam); // ???
	pm.add_menu(&m1);
	pm.add_menu(&m2);
	pm.command();
}




