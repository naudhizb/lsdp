#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " ����" << std::endl;
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void add_menu(MenuItem* p) { v.push_back(); }
	// popup �޴� ���ý� �ؾ� ������ ������ ������
	void command()
	{
	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);
	
	PopupMenu pm("������ �޴�");
	pm.add_menu(&m1);
	pm.add_menu(&m2);
	pm.command();
}




