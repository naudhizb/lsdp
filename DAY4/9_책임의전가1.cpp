#include <iostream>
// git �� å���� ����1  2 �ֽ��ϴ�. �޾Ƶμ���.

// chain of responsibility : å���� ��(����)
// ��û�� ó���� ��ü�� ���鶧 ���� ���� ���� ��û�� ����.
// ��û�� ó���� ���� ��ü�� �Ҽ� �ְ� �Ѵ�.

struct Handler
{
	Handler* next = 0;

	virtual bool HandleRequest(int problem) = 0;

	void Handle(int problem)
	{
		// 1. �ڽ��� ��û�� ó��
		if (HandleRequest(problem) == true)
			return;

		// 2. ó������ ���� ��� ���� ��ü�� �ִٸ� ����
		if (next != 0)
			next->Handle(problem);  // HandleRequest�� �ƴ� Handle�� �ٽ�
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