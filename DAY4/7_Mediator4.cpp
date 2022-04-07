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

	// global 통보센터라는 개념도 만들어 봅시다.
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
	// IOS 개발의 핵심의 "통보센터" 입니다.
//	NotificationCenter nc;

	// 공동의 작업은 아래처럼 사용하자 라고 약속
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	
	Machine m;
	nc.RegisterObserver("LOWBATTERY", std::bind(&Machine::work1, &m, _1) );
	nc.RegisterObserver("LOWBATTERY", std::bind(&Machine::work2, &m, _1, 5));

	nc.RegisterObserver("LOWBATTERY", foo);
	nc.RegisterObserver("LOWBATTERY", goo);

	// 배터리 모듈을 책임지는 사람은
	nc.PostNotificationWithName("LOWBATTERY", (void*)30);
}