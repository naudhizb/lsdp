#include <iostream>
#include <mutex>

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
		mtx.lock();

		if (pinstance == 0)
			pinstance = new Cursor;

		mtx.unlock();

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








