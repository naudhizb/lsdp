
// STL �� ����
// allocator : �޸� �Ҵ� ���� ��å�� ���� ��å Ŭ����
template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	Allocator ax;
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 
		// �޸� �Ҵ�/���� �� "�޸��Ҵ��"�� �����մϴ�.

		T* buff = ax.allocate(n); // �Ҵ�

		ax.deallocate(buff, n); // ����
	}
};

