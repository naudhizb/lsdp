#include <iostream>
using namespace std;

// 방법 2. 변하는 것을 가상함수로..

class Charater
{
	int gold;
	int item;
public:
	void run() { doRun(); }
	void attack() { doAttack(); }

	virtual void doRun()    { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};
class FastItemCharacter : public Charater
{
public:
	void doRun() override { std::cout << "fast run" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new FastItemCharacter; // 기존 객체의 동작변경이 아닌
							   // 동작이 변경된 새로운 객체를 생성한것!!
	p->run();
}



