#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// STL 반복자 카테고리
// 입력  : ++					멀티패스 보장 안됨
// 출력  : ++, *p = 0
//								아래3개는 멀티 패스 보장
// 전진형 : ++					싱글리스트 반복자
// 양방향 : ++, --				더블리스트 반복자
// 임의접근 : ++, --, +, -, []    연속된 메모리 vector

// p가 반복자일때
// *p = 10  출력
// int n = *p; 입력

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	// find알고리즘이 요구하는 반복자의 최소 요구 조건은 ? 입력
	auto ret = std::find( v.begin(), v.end(), 3);

	std::reverse( v.begin(), v.end() ); // 최소 요구 조건? 양방향.

	std::list<int> s = { 1,2,3,4,5 , 3,2,1};
	 
//	s.sort();
//	std::sort( s.begin(), s.end() ); // 퀵소트 알고리즘입니다.
}

// cppreference.com