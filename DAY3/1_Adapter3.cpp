#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// STL �� list�� �ִµ�, ����ڵ��� "stack"�� �䱸�Ѵ�.
// 1. stack �� ����� ����.
// 2. list�� �Լ� �̸��� �����ؼ� "stack"ó�� ���̰� ����. - adapter

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); } // ��� Ŭ���� �Լ� �ٽ� ���
	void pop()            { std::list<T>::pop_back(); }
	T& top()              { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}