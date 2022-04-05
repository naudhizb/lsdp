// Decorator - 65 page
#include <iostream>

class SpaceShip
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����߰�

// => Ŭ������ ����� �߰��ϴ� ��
// => ����ð��� ��� �߰��� �ƴ� �ڵ� �ۼ��� ����߰�
// SpaceShip ss �϶�
// ss�� ����� �߰��Ѱ��� �ƴ�.
class NewSpaceShip : public SpaceShip
{
public:
	void Fire() 
	{	
		SpaceShip::Fire(); // ���� ��� ���

		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	NewSpaceShip nss;
	nss.Fire();
}