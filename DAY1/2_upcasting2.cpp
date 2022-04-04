// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*> v1; // Dog 만 보관하겠다는 의미
	std::vector<Animal*> v2; // 동종(동일 기반 클래스로 부터 파생된 타입)을 보관하겠다는 의미
							 // 모든 동물을 보관..		
}

// A 와 B를 묶고 싶다면
// 기반 클래스를 설계 해라...

// 상속을 
// 1. "기본 타입의 확장" 뿐 아니라
// 2. 동종을 묶기 위해서도 사용.. 
 
// 9:50 분에 시작 합니다.