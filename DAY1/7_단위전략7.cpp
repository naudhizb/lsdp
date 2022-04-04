#include <iostream>
#include <vector>

// STL �� ���������� ���ָ��� ����ϰ� �ֽ��ϴ�.

// vector�� ������ �޸� �Ҵ��
template<typename T> struct MyAlloc
{
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "�� �Ҵ�" << std::endl;

		return static_cast<T*>(malloc(sizeof(T)*sz));
	}

	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "�� ����" << std::endl;

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