#include <iostream>

class SpaceShip 
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
// 상속 : 클래스에 기능추가
// 포함 : 객체에 기능추가
class LeftMissile
{
	SpaceShip* ship; // 포인터 또는 참조로
public:
	LeftMissile( SpaceShip* s ) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // 기존 기능 사용
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	// ss를 기능추가 객체로 포장(Decorator)
	LeftMissile lm(&ss);
	lm.Fire();
}