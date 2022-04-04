// upcasting1.cpp
class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog*    p1 = &d; // ok
	int*    p2 = &d; // error
	Animal* p3 = &d; // ok. upcasting
					 // 기반 클래스 포인터로 파생클래스 객체를
					// 가리킬수 있다.

	// 핵심 1. 기반 클래스 포인터로 파생 클래스 가리킬수 있다.

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스로 부터 물려받은 멤버만 접근가능
	//			 파생 클래스(Dog)의 고유 멤버 접근 안됨..
	p3->age = 10;   // ok
	p3->color = 20; // error

	// 핵심 3. 파생클래스 고유 멤버에 접근하려면 파생 클래스 포인터로 캐스팅해야 한다.
	static_cast<Dog*>(p3)->color = 10; // 단, 이 경우 p3가 Dog 객체를 가리킨다는
										// 확신이 있어야 한다.
}











