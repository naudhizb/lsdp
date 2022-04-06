#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, typename C = std::deque<T> > 
class stack
{
//	std::list<T> c;
//	std::vector<T> c;
	C c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()			  { return c.back(); }
};
#include <stack> // C++ 표준의 stack이 위처럼 만들어져 있습니다
				 // 흔히, stack adapter 입니다.
				 // "클래스 어답터"로 만들어져 있는데.
			     // 단위전략 기술로 "컨테이너 교체도 가능"
int main()
{
//	stack<int, std::vector<int> > s; // vector를 stack 처럼 사용하게
								// 해달라!
	stack<int>  s;
	s.push(10);
}