#include <iostream>
#include <vector>
#include <allocators> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	int* p1 = new int[10];

	delete[] p1;

	// 2. allocator ���
	std::allocator<int> ax; // ǥ�� �Ҵ�� (���������� new, delete ���)

	int* p = ax.allocate(10); // new int[10] ó�� �޸� �Ҵ�

	ax.deallocate(p, 10);  // delete[] p

}