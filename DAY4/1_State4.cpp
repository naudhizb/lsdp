
#include <iostream>
using namespace std;

// 변하는 동작을 다른 클래스로
// 인터페이스 설계
struct IState
{
	virtual void doRun() = 0;
	virtual void doAttack() = 0;
	virtual ~IState() {}
};
class Charater
{
	int gold;
	int item;
	IState* pState = 0;
public:
	void setState(IState* p) { pState = p; }
	void run()    { pState->doRun(); }
	void attack() { pState->doAttack(); }
};

struct NoItem : public IState
{
	void doRun() override { std::cout << "Run" << std::endl; }
	void doAttack() override { std::cout << "Attack" << std::endl; }
};
struct GoldItem : public IState
{
	void doRun() override { std::cout << "fast Run" << std::endl; }
	void doAttack() override { std::cout << "power Attack" << std::endl; }
};
int main()
{
	NoItem ni; GoldItem gi;
	Charater* p = new Charater;
	p->setState(&ni);
	p->run();
	p->attack();
	p->setState(&gi);
	p->run();
}



