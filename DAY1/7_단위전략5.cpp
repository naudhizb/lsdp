
// STL 의 원리
// allocator : 메모리 할당 해지 정책을 담은 정책 클래스
template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	Allocator ax;
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 
		// 메모리 할당/해지 는 "메모리할당기"에 의존합니다.

		T* buff = ax.allocate(n); // 할당

		ax.deallocate(buff, n); // 해지
	}
};

