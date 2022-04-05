#include <iostream>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* pinstance;
public:
	
	static Cursor& getInstance()
	{
		if (pinstance == 0)
			pinstance = new Cursor;

		return *pinstance;
	}
};
Cursor* Cursor::pinstance = 0;



int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;
}








