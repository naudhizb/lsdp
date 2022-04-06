#include <iostream>


int main()
{
	slist<int> s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리
	vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리

	// 컨테이너의 내부 구조에 상관없이 동일한 방법으로 열거 하고 싶다.
	반복자 a = s.get반복자();
	반복자 b = v.get반복자();

	std::cout << a.GetObject() << std::endl; // 1

	a.MoveNext(); // 다음으로 이동.

	std::cout << a.GetObject() << std::endl; // 2

}