// Decorator - 65 page
#include <iostream>

class SpaceShip
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능추가
class NewSpaceShip : public SpaceShip
{
public:
	void Fire() 
	{	
		SpaceShip::Fire(); // 기존 기능 사용
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	NewSpaceShip nss;
	nss.Fire();
}