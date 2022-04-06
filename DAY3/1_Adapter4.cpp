#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T> class stack
{
	std::list<T> c;
public:
	void push(const T& a)	{ c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};
// 아래가 객체 어답터 입니다.
template<typename T> class stack2
{
	std::list<T>& c;
public:
	stack2(std::list<T>& c) : c(c) {}

	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	std::list<int> st; // list객체를 만들고
	st.push_back(10);
	st.push_back(20); // 사용하다가.. 
					  // stack처럼 사용할수 있게 할수 있으면 객체 어답터

	stack2<int> stk(st);
	std::cout << stk.top() << std::endl; // 20


	stack<int> s;
	s.push(10);
	s.push(20);

}