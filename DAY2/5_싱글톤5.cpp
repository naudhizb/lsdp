#include <iostream>
#include <mutex>

// lock/unlock �� ���� �����ϸ�
// deadlock �� ���ɼ��� �ֽ��ϴ�.
// ������, �Ҹ��ڷ� ����ȭ �ڿ��� �����ؾ� �մϴ�

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:
	static Cursor& getInstance()
	{
//		lock_guard<std::mutex> lg(mtx); // mtx.lock()
		std::lock_guard<std::mutex> lg(mtx);

		//		mtx.lock();
		if (pinstance == 0)
			pinstance = new Cursor;
		//		mtx.unlock();
		return *pinstance;
	}
};
Cursor* Cursor::pinstance = 0;
std::mutex Cursor::mtx;



int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}



/*
if (m.try_lock())
{
	// lock..
}
else
{

}
*/



