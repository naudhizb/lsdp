#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>

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
};
//-----------------------
void foo(void* p) { std::cout << "foo" << std::endl; }
void goo(void* p) { std::cout << "goo" << std::endl; }

int main()
{
	// IOS ������ �ٽ��� "�뺸����" �Դϴ�.
	NotificationCenter nc;
	
	nc.RegisterObserver("LOWBATTERY", foo);
	nc.RegisterObserver("LOWBATTERY", goo);

	// ���͸� ����� å������ �����
	nc.PostNotificationWithName("LOWBATTERY", (void*)30);
}