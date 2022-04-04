#include <iostream>
template<typename T, typename T2> class List
{
	T2 tm;
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
	inline void lock() { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
struct NoLock
{
	inline void lock() {  }
	inline void unlock() { }
};
//----------------------------
List<int, NoLock> st; 

int main()
{
	st.push_front(10);
}




