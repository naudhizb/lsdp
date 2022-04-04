#include <iostream>
#include <set>   // tree 입니다.
#include <string>

struct People
{
	std::string name;
	int age;
};

// 2개의 People의 크기를 비교하는 타입
// 조건 : 반드시 () 연산자를 재정의 해서 함수 처럼 사용할수 있어야 한다.
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







// STL set의 원리
/*
template<typename T, 
		 typename Pred = std::less<T>, 
		 typename Alloc = std::allocator<T> >
class set
{
	T* root;
	Pred f;  // 2개의 크기 비교를 위한 객체
	Allox ax;// 메모리 할당을 위한 개체
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





