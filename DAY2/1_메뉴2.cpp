#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� : "�ʿ��� Ÿ���� ���� �����Ѵ�"

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
int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);
	m1.command();
}




