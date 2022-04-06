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

int main()
{
//	stack<int, std::vector<int> > s; // vector를 stack 처럼 사용하게
								// 해달라!
	stack<int>  s;
	s.push(10);
}