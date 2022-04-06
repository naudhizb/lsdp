#include <iostream>
using namespace std;

// ��� 2. ���ϴ� ���� �����Լ���..

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

	p = new FastItemCharacter; // ���� ��ü�� ���ۺ����� �ƴ�
							   // ������ ����� ���ο� ��ü�� �����Ѱ�!!
	p->run();
}



