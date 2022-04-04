#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 : "필요한 타입을 먼저 설계한다"

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " 선택" << std::endl;
		_getch();
	}
};
int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	m1.command();
}




