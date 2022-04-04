#include <iostream>

// upcasting3.cpp
class Animal
{
public:
	virtual ~Animal() {}
	int age;
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};
//void NewYear(Dog* pDog)  // Dog�� ó���ϴ� �Լ�
void NewYear(Animal* p)    // ��� ������ ó���ϴ� �Լ�!
{
	++(p->age);
}
// 3���� �߸��� ������..
// �� Animal* p�� Dog�� ����Ű�� �� �����ϴ°� ??
// �Ʒ� ó�� Dog ���� ������ �߰��� ���� �ϴ°� ����.!
void NewYear(Dog* p) 
{
	NewYear( static_cast<Animal*>(p) );
	p->color = 10;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}













