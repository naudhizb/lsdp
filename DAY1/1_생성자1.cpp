// 강석민 강사 ( smkang @ codenuri.co.kr )
// github.com/codenuri/lsdp   에  "DAY1_사전소스.zip" 파일 있습니다.
// 받아 두세요..

// 1. VC 에서 열어 보세요

// 2. x86, Debug 로 설정

// 3. 프로젝트메뉴 - 속성 메뉴에서
//    Windows SDK 버전과 플랫폼 도구 집합 맞춰 주세요.

// C++11 까지 기술 사용합니다.









//생성자1.cpp - 3page

class Base
{
public:
//	Base()     {} 
	Base(int a){} 
	~Base()    {} 
};
class Derived : public Base
{
public:
	// 사용자 코드     // 컴파일러가 변경한 코드					
//	Derived() {}       // Derived()      : Base() {} 
//	Derived(int a) {}  // Derived(int a) : Base() {}
	~Derived() {}      // ~Derived() {   .....;  ~Base(); }

	// 기반 클래스에 디폴트 생성자가 없는경우
	// 반드시 파생클래스에서 명시적으로 기반 클래스 생성자를 호출해야 합니다.
	Derived() : Base(0) {}      
	Derived(int a) : Base(a) {}  


};
int main()
{
	Derived d(1); // call Derived::Derived(int)
}