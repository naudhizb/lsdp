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
//void NewYear(Dog* pDog)  // Dog만 처리하는 함수
void NewYear(Animal* p)    // 모든 동물을 처리하는 함수!
{
	++(p->age);
	
	// 유지보수를 하다가.. 요구조건이 추가되었다
	// p가 Dog를 가리킨다면 color도 변경하고 싶다.
//	p->color = 10; // error

	// p를 Dog*로 캐스팅
//	Dog* pDog = static_cast<Dog*>(p);

	// p가 정말 Dog를 가리키는지 조사하고 캐스팅
	// 반드시 가상함수가 있는 타입에 대해서만 dynamic_cast를 할수 있습니다.
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













