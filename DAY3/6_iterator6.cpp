#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int> s = { 1,2,3,4,5 };

	std::vector<int>::iterator p1 = v.begin();
	std::list<int>::iterator   p2 = s.begin();

	// ���� p1, p2�� ������ ó�� �����ϰ� ����ϸ� �˴ϴ�.
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}