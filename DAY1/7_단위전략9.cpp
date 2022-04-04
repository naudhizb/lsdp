#include <iostream>
#include <set>   // tree �Դϴ�.
#include <string>

struct People
{
	std::string name;
	int age;
};

// 2���� People�� ũ�⸦ ���ϴ� Ÿ��
// ���� : �ݵ�� () �����ڸ� ������ �ؼ� �Լ� ó�� ����Ҽ� �־�� �Ѵ�.
struct PeopleCompare
{
	bool operator()(const People& p1, const People& p2) const
	{
		return p1.age < p2.age;
	}
};


int main()
{
	std::set<People, PeopleCompare> s2;

	s2.insert({ "kim", 20 });
	s2.insert({ "lee", 30 });
}







// STL set�� ����
/*
template<typename T, 
		 typename Pred = std::less<T>, 
		 typename Alloc = std::allocator<T> >
class set
{
	T* root;
	Pred f;  // 2���� ũ�� �񱳸� ���� ��ü
	Allox ax;// �޸� �Ҵ��� ���� ��ü
public:
	void insert(const T& newElem)
	{

		if ( f(*root , newElem) )
			add right;
		else if (f(newElem, *root) )
			add left;
		else
			fail;
	}
};
*/





