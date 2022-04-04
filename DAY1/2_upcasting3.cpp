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
	
	// ���������� �ϴٰ�.. �䱸������ �߰��Ǿ���
	// p�� Dog�� ����Ų�ٸ� color�� �����ϰ� �ʹ�.
//	p->color = 10; // error

	// p�� Dog*�� ĳ����
//	Dog* pDog = static_cast<Dog*>(p);

	// p�� ���� Dog�� ����Ű���� �����ϰ� ĳ����
	// �ݵ�� �����Լ��� �ִ� Ÿ�Կ� ���ؼ��� dynamic_cast�� �Ҽ� �ֽ��ϴ�.
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	//pDog->color = 100;
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}













