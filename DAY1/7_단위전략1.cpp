// list �տ� �ִ� �ڵ�� ������ �ʴ´�..
// �׷���, ����ȭ ���θ� �����Ҽ� �ְ� �ϴ� ���� ����
// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ���
// 2. ���ϴ� ���� �ٸ� Ŭ������
template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
};

List<int> st; // ���������� ��Ƽ�����忡 �������� �ʽ��ϴ�.

int main()
{
	st.push_front(10);
}




