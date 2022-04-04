// ���ϴ� ���� �и�
// 1. �����Լ��� �и� - "template method"

// 2. �ٸ� Ŭ������ �и�
//    => ��å Ŭ������ ��� ��ü �����ϰ� �Ұ��ΰ� ?

//	  A. �������̽��� ���� �ؼ� ��ü - strategy ����

//	  B. ��åŬ������ ���ø� ���ڷ� ��ü - Policy Base Design(��������), 
//											C++���� ���ֳθ����

//					�������̽� ��ü			���ø� ��ü
//	�ӵ�			������					������(�ζ��� ġȯ)
//  ����ð� ��ü	����					���ø� �����̹Ƿ� �����Ҷ��� ��ü ����
//					edit.setValidator(&v)

// �Ʒ� �ڵ忡�� ����ȭ ��å�� ���� Ŭ������ ���Ѿ� �ϴ� ��Ģ�� �����.
// "lock/unlock" �� �־�� �Ѵ�.
// => "�������̽� ó�� �ڵ�� ǥ�� �ȵ�"
// => ����ȭ �ؾ� �Ѵ�. 
// => "cppreference.com"







#include <iostream>

template<typename T, typename ThreadModel  = NoLock > class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//......
		tm.unlock();
	}
};
// List�� ����ȭ ��å���� ���޵� Ŭ����
struct MutexLock
{
	// pthread_mutex_t handle
	inline void lock() { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
struct NoLock
{
	inline void lock() {  }
	inline void unlock() { }
};
//----------------------------
//List<int, NoLock> st; 
//List<int, MutexLock> st;
List<int> st;

int main()
{
	st.push_front(10);
}




