#include <iostream>
#include <set>   // tree 입니다.
#include <string>

struct People
{
	std::string name;
	int age;
};

int main()
{
	std::set<int> s1 = { 50,30, 60 };



	std::set<People> s2;

	s2.insert({ "kim", 20 });
	s2.insert({ "lee", 30 });
}

// STL set의 원리
template<typename T>
class set
{
	T* root;
public:
	void insert(const T& newElem)
	{
		if (*root < newElem)
			add right;
		else if (newElem < *root)
			add left;
		else
			fail;

	}
};






