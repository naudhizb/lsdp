#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// STL 에 list가 있는데, 사용자들이 "stack"을 요구한다.
// 1. stack 을 만들어 주자.
// 2. list의 함수 이름을 변경해서 "stack"처럼 보이게 하자. - adapter

/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } // 기반 클래스 함수 다시 사용
	void pop()            { std::list<T>::pop_back(); }
	T& top()              { return std::list<T>::back(); }
};
*/

// push_front() 를 사용할수 없게 하자.
// 방법 1. private 상속
/*
template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } 
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};
*/
// 방법 2. list 기능을 나만 사용하다면
// "상속" 보다는 "포함"이 좋다.
template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};
int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	
//	s.push_front(20); // private 상속인 경우 기반 클래스인 list의 모든
						// 멤버 함수는 private이다.
}