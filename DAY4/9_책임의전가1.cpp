#include <iostream>
// git 에 책임의 전가1  2 있습니다. 받아두세요.

// chain of responsibility : 책임의 고리(전가)
// 요청을 처리할 객체를 만들때 까지 고리를 따라서 요청을 전달.
// 요청의 처리는 여러 객체가 할수 있게 한다.

struct Handler
{
	Handler* next = 0;

	virtual bool HandleRequest(int problem) = 0;

	void Handle(int problem)
	{
		// 1. 자신이 요청을 처리
		if (HandleRequest(problem) == true)
			return;

		// 2. 처리되지 않은 경우 다음 객체가 있다면 전달
		if (next != 0)
			next->Handle(problem);  // HandleRequest가 아닌 Handle이 핵심
	}
};
//-----------------------
struct OddHandler : public Handler
{
	bool HandleRequest(int problem) override 
	{
		std::cout << "arrive at OddHAndler" << std::endl;
		return problem % 2 == 1;
	}
};
struct TenHandler : public Handler
{
	bool HandleRequest(int problem) override 
	{
		std::cout << "arrive at TenHandler" << std::endl;
		return problem == 10;
	}
};
struct EvenHandler : public Handler
{
	bool HandleRequest(int problem) override 
	{ 
		std::cout << "arrive at TenHandler" << std::endl;
		return problem % 2 == 0;
	}
};
int main()
{
	OddHandler oh;
	TenHandler th;
	EvenHandler eh;
	oh.next = &th;
	th.next = &eh;
	// oh => th => eh
	oh.Handle(5);
}