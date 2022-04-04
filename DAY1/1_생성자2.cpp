// protected 생성자 : 자신은 객체를 만들수 없지만(추상적 개념)
//					  파생 클래스는 객체를 만들수 있게 하는 디자인 기술

class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public: 
	Dog() {}   // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// 1 error
	Dog    d;	// 2 ok
}



