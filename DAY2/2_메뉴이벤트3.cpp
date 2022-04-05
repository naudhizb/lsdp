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
// �̺�Ʈ ó�� 2. ���ϴ� ���� �ٸ� Ŭ������ - ���� ����

// �޴��̺�Ʈ�� ó���ϰ� ���� ��� Ŭ������ �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
	virtual void Command() = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;
	IMenuListener* pListener = 0;
public:
	void setListener(IMenuListener* p) { pListener = p; }

	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		pListener->Command();
	}
};

// �޴��� ó���Ϸ��� �ݵ�� IMenuListener �� �����ؾ� �մϴ�.
class Camera : public IMenuListener
{
public:
	void Command() override
	{
		std::cout << "Camera Command" << std::endl;
	}
};

int main()
{
	Camera cam;
	MenuItem m1("HD", 11);
	MenuItem m2("FHD", 12);

	m1.setListener(&cam);
	m2.setListener(&cam);

	m2.command(); // �޴� ����
}




