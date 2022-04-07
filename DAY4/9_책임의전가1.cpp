#include <iostream>

struct Handler
{
	Handler* next = 0;

	virtual bool HandleRequest() = 0;

	void Handle(int problem)
	{

	}
};


int main()
{

}