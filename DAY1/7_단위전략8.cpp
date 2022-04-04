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
		// 아래처럼 만들면 무조건 크기 비교는 < 연산만 사용하게 됩니다
		// 교체 불가능한 경직된 디자인
		if (*root < newElem)
			add right;
		else if (newElem < *root)
			add left;
		else
			fail;
	}
};






