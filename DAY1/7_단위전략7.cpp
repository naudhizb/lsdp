#include <iostream>
#include <vector>

// STL �� ���������� ���ָ��� ����ϰ� �ֽ��ϴ�.

// vector�� ������ �޸� �Ҵ��
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

int main()
{
	std::vector<int, MyAlloc<int> > v;

	std::cout << "------------" << std::endl;

	v.resize(10);

	std::cout << "------------" << std::endl;
}