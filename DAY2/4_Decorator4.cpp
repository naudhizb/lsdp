#include <iostream>

// �������� �繰�� ���������� ����� �繰�� �ٽ� �����Ѵ�.
// �������� �繰�� ������ ��� Ŭ���� ���

// ������ ���Ͽ��� ����� ������ ����ϴ� ������ 2���� �Դϴ�.
// ��ü�� �ڽ��� �ٽ� �����ϴ� ��.
// Composite : ����� ������ ����� ���� ��ü �����
// Decorator : ����� ������ ����� ��ü�� ��� �߰�

// �� 2�� ������ ������ Ŭ���� Diagram �� �˴ϴ�.
// �׷���, "��" �̷��� ����°� ? �� ���� �̸��� �ٸ��ϴ�.
// ���հ�ü : composite
// ����߰� : decorator

struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};
class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public Item
{
	Item* ship;
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); 
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);
	lm.Fire();

	RightMissile rm(&lm);
	rm.Fire();
}