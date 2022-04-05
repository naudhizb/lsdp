#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>  // std::function<>, std::bind
using namespace std::placeholders; // _1, _2... 

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

class MenuItem : public BaseMenu
{
	int id;

	typedef std::function<void()> HANDLER;
	std::vector< HANDLER > v;

public:
	void addHandler(HANDLER handler) { v.push_back(handler); }

	MenuItem(const std::string& s, int n, HANDLER handler = 0) 
		: BaseMenu(s), id(n) 
	{
		if (handler != 0)
			v.push_back( handler );
	}

	void command()
	{
		for (auto f : v)
			f();
	}
};

void f()       { std::cout << "f" << std::endl; }
void f1(int n) { std::cout << "f1 : " << n << std::endl; }

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
class Camera
{
public:
	void take(int a, int b) {}
};

int main()
{
	MenuItem m1("HD", 11, &f);
	MenuItem m2("FHD", 12, std::bind(&f1, 12) );
	MenuItem m3("UHD", 13, std::bind(&f1, 13));

	// m1�� �ڵ鷯 f4 �߰� �غ�����..���ڴ� �ƹ� ���ڳ� ����
	m1.addHandler(std::bind(&f4, 1, 2, 3, 4));

	// m2 �� Camera::take �߰� �غ�����.
	Camera cam;
	m2.addHandler(std::bind(&Camera::take, &cam, 1, 2));

	m3.addHandler([]() { std::cout << "lambda event handler" << std::endl; });

	m1.command();
	m2.command(); // �޴� ����
	m3.command();
}

// �޴�        : Composite ���� - ���հ�ü�� �ٽ� ���հ�ü ����
// �޴� �̺�Ʈ : Observer ���� - �̺�Ʈ �߻��� �������� ����


// C++23  : ��Ʈ��Ʈ ���̺귯��(asio)

// C/C++ : �Լ� ������ ���� ����..
//			function ���� "��� �Լ��� ������ �ְ�.."

// java : ������ �������, �Լ��� �����ϴ� ���� ����
//			jdk1.8 ���� �Լ� Ÿ�� ����.

// C# : ������ ����
//	    �׷���,�Լ�(�ּ�)�� �����ߴٰ� �ٽ� ȣ�� �ϴ� ������ �ʿ��ߴ�.
//		"delegate" ��� ���� ����

// Swift : ������ ������, "�Լ� Ÿ��"�̶�� ���� �����ؼ�
//	     callback �� �뵵�� ���