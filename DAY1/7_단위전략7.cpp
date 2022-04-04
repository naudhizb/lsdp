#include <iostream>
#include <vector>

// STL 은 단위전략을 아주많이 사용하고 있습니다.

// vector에 전달할 메모리 할당기
template<typename T> struct MyAlloc
{
	inline T* allocate(std::size_t sz)
	{
		std::cout << sz << "개 할당" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)*sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "개 해지" << std::endl;
		free(p);
	}

	// 위 2개 함수외에 아래 3개가 더있어야하니다.
	MyAlloc() {}

	typedef T value_type;

	template<typename U> MyAlloc(const U&) {} // 템플릿 생성자라는 개념입니다.
};

int main()
{
	std::vector<int, MyAlloc<int> > v;

	std::cout << "------------" << std::endl;

	v.resize(10);

	std::cout << "------------" << std::endl;
}