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
}
// 3번은 잘못된 디자인..
// 왜 Animal* p가 Dog를 가리키는 지 조사하는가 ??
// 아래 처럼 Dog 전용 버전을 추가로 설계 하는게 낫다.!
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













