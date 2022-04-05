#include <iostream>

// 포장지는 사물을 포장하지만 포장된 사물을 다시 포장한다.
// 포장지와 사물은 공통의 기반 클래스 사용

// 디자인 패턴에서 재귀적 포함을 사용하는 패턴을 2가지 입니다.
// 객체가 자신을 다시 포함하는 것.
// Composite : 재귀적 포함을 사용한 복합 객체 만들기
// Decorator : 재귀적 포함을 사용한 객체에 기능 추가

// 위 2개 패턴은 동일한 클래스 Diagram 이 됩니다.
// 그런데, "왜" 이렇게 만드는가 ? 에 따라 이름이 다릅니다.
// 복합객체 : composite
// 기능추가 : decorator

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