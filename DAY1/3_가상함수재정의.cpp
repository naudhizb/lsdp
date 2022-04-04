// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};

class Derived : public Base
{
public:
	// 가상함수 재정의시 오타발생.. 
	// => 에러가 아니라, 다른 함수로 처리
	// => 그래서 C++11 부터는 "override" 를 붙이라고 권장
	virtual void fooo()  override {}
	virtual void goo(double) override {}
};
int main()
{
}




