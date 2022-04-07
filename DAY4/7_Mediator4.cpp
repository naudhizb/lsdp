#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>
using namespace std::placeholders;

class NotificationCenter
{
	typedef std::function<void(void*)> HANDLER;

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	void RegisterObserver(const std::string& key, HANDLER f)
	{
		notif_map[key].push_back(f);
	}
	void PostNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key])
			f(hint);
	}

	// global �뺸���Ͷ�� ���䵵 ����� ���ô�.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter instance;
		return instance;
	}
};
//-----------------------
void foo(void* p) { std::cout << "foo" << std::endl; }
void goo(void* p) { std::cout << "goo" << std::endl; }

class Machine
{
public:
	void work1(void* p)
	{

	}
	void work2(void* p, int a)
	{

	}


};
int main()
{
	// IOS ������ �ٽ��� "�뺸����" �Դϴ�.
//	NotificationCenter nc;

	// ������ �۾��� �Ʒ�ó�� ������� ��� ���
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	
	Machine m;
	nc.RegisterObserver("LOWBATTERY", std::bind(&Machine::work1, &m, _1) );
	nc.RegisterObserver("LOWBATTERY", std::bind(&Machine::work2, &m, _1, 5));

	nc.RegisterObserver("LOWBATTERY", foo);
	nc.RegisterObserver("LOWBATTERY", goo);

	// ���͸� ����� å������ �����
	nc.PostNotificationWithName("LOWBATTERY", (void*)30);
}