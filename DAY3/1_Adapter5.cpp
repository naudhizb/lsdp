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
#include <stack> // C++ ǥ���� stack�� ��ó�� ������� �ֽ��ϴ�
				 // ����, stack adapter �Դϴ�.
				 // "Ŭ���� �����"�� ������� �ִµ�.
			     // �������� ����� "�����̳� ��ü�� ����"
int main()
{
//	stack<int, std::vector<int> > s; // vector�� stack ó�� ����ϰ�
								// �ش޶�!
	stack<int>  s;
	s.push(10);
}