// upcasting3.cpp
class Animal 
{
public: 
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
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}













