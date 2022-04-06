
#include <iostream>
using namespace std;

// 인터페이스 기반으로 변하는 것을 분리하는 패턴은 3가지 입니다.

// 프로그램에서 사용하는 알고리즘의 교체 : strategy
// 객체에 상태에 따른 동작의 교체 : state
// 복잡한 객체를 만들때 공정과 세부 구현의 분리 : builder

// state 패턴
// 객체의 데이타는 변하는 않은데, 동작이 교체 된다.
// 마치 새로운 클래스를 사용하는 것과 같다.


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



