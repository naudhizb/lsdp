#include <iostream>
#include <vector>
#include <allocators> // C++ 표준 메모리 할당기

int main()
{
	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	int* p1 = new int[10];

	delete[] p1;

	// 2. allocator 사용
	std::allocator<int> ax; // 표준 할당기 (내부적으로 new, delete 사용)

	int* p = ax.allocate(10); // new int[10] 처럼 메모리 할당

	ax.deallocate(p, 10);  // delete[] p

}