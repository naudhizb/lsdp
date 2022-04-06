#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int> s = { 1,2,3,4,5 };

	std::vector<int>::iterator p1 = v.begin();
	std::list<int>::iterator   p2 = s.begin();

	// 이제 p1, p2를 포인터 처럼 생각하고 사용하면 됩니다.
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;

	++p1;
	++p2;

	// ??
	p1 = p1 + 3; // ok 
	p2 = p2 + 3; // error. ++p 를 3번하는 것과 결국 동일하다.
}
// STL 반복자 카테고리
// 입력  : ++					멀티패스 보장 안됨
// 출력  : ++
//								아래3개는 멀티 패스 보장
// 전진형 : ++					싱글리스트 반복자
// 양방향 : ++, --				더블리스트 반복자
// 임의접근 : ++, --, +, -, []    연속된 메모리 vector