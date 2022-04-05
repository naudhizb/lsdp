#include <iostream>

class SpaceShip 
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
// ��� : Ŭ������ ����߰�
// ���� : ��ü�� ����߰�
class LeftMissile
{
	SpaceShip* ship; // ������ �Ǵ� ������
public:
	LeftMissile( SpaceShip* s ) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // ���� ��� ���
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	// ss�� ����߰� ��ü�� ����(Decorator)
	LeftMissile lm(&ss);
	lm.Fire();
}