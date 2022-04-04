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

//void NewYear(Dog* pDog)  // Dog만 처리하는 함수
void NewYear(Animal* p)    // 모든 동물을 처리하는 함수!
{
	++(p->age);
	
	// 유지보수를 하다가.. 요구조건이 추가되었다
	// p가 Dog를 가리킨다면 color도 변경하고 싶다.
//	p->color = 10; // error

	// p를 Dog*로 캐스팅
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}













