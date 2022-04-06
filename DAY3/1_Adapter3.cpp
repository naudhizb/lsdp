#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// STL �� list�� �ִµ�, ����ڵ��� "stack"�� �䱸�Ѵ�.
// 1. stack �� ����� ����.
// 2. list�� �Լ� �̸��� �����ؼ� "stack"ó�� ���̰� ����. - adapter

/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } // ��� Ŭ���� �Լ� �ٽ� ���
	void pop()            { std::list<T>::pop_back(); }
	T& top()              { return std::list<T>::back(); }
};
*/

// push_front() �� ����Ҽ� ���� ����.
// ��� 1. private ���
/*
template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } 
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};
*/
// ��� 2. list ����� ���� ����ϴٸ�
// "���" ���ٴ� "����"�� ����.
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
	
//	s.push_front(20); // private ����� ��� ��� Ŭ������ list�� ���
						// ��� �Լ��� private�̴�.
}