#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// STL 에 list가 있는데, 사용자들이 "stack"을 요구한다.
// 1. stack 을 만들어 주자.
// 2. list의 함수 이름을 변경해서 "stack"처럼 보이게 하자. - adapter

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } // 기반 클래스 함수 다시 사용
	void pop()            { std::list<T>::pop_back(); }
	T& top()              { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}