#include <iostream>
#include <vector>

// STL 은 단위전략을 아주많이 사용하고 있습니다.

// vector에 전달할 메모리 할당기
template<typename T> struct MyAlloc
{
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "개 할당" << std::endl;

		return static_cast<T*>(malloc(sizeof(T)*sz));
	}

	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "개 해지" << std::endl;

		free(p);
	}
};



int main()
{
	std::vector<int, MyAlloc<int> > v;

	std::cout << "------------" << std::endl;

	v.resize(10);

	std::cout << "------------" << std::endl;
}