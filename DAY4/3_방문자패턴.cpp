#include <iostream>
#include <list>
#include <vector>
using namespace std;

// 반복자 : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자 : 복합객체의 모든 요소를 동일한 방식으로 연산수행
// visitor 패턴

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 1. 모든 요소를 차례대로 꺼낸후 2배로 변경해서 다시 넣는다.
	for (auto& e : s)
	{
		e *= 2;
	}

	// 2. list 안에 요소를 2배로 하는 멤버 함수 제공
	s.twiceAll(); 

	// 3. 방문자 패턴을 사용한다.
	TwiceVisitor tv;
	s.Accept(&tv); // tv라는 방문자가 s의 모든 요소에 연산 수행

	ZeroVisitor zv;
	s.Accept(&zv);

}





