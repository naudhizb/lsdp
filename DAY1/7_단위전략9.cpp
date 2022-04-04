#include <iostream>
#include <set>   // tree �Դϴ�.
#include <string>

template<typename T> struct MyAlloc
{
	inline T* allocate(std::size_t sz)
	{
		std::cout << sz << "�� �Ҵ�" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)*sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "�� ����" << std::endl;
		free(p);
	}

	// �� 2�� �Լ��ܿ� �Ʒ� 3���� ���־���ϴϴ�.
	MyAlloc() {}

	typedef T value_type;

	template<typename U> MyAlloc(const U&) {} // ���ø� �����ڶ�� �����Դϴ�.
};

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
	std::set<People, PeopleCompare, MyAlloc<People> > s2;

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
	Pred f;  // 2���� ũ�� �񱳸� ���� ��ü  PeopleCompare f
	Allox ax;// �޸� �Ҵ��� ���� ��ü
public:
	void insert(const T& newElem)
	{

		if ( f(*root , newElem) ) // f.operator()(*root, newElem)
			add right;
		else if (f(newElem, *root) )
			add left;
		else
			fail;
	}
};
*/





