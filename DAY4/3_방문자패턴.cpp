#include <iostream>
#include <list>
#include <vector>
using namespace std;

// �ݺ��� : ���հ�ü�� ��� ��Ҹ� ������ ������� ����
// �湮�� : ���հ�ü�� ��� ��Ҹ� ������ ������� �������
// visitor ����

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s�� ��� ��Ҹ� 2��� �ϰ� �ʹ�.

	// 1. ��� ��Ҹ� ���ʴ�� ������ 2��� �����ؼ� �ٽ� �ִ´�.
	for (auto& e : s)
	{
		e *= 2;
	}

	// 2. list �ȿ� ��Ҹ� 2��� �ϴ� ��� �Լ� ����
	s.twiceAll(); 

	// 3. �湮�� ������ ����Ѵ�.
	TwiceVisitor tv;
	s.Accept(&tv); // tv��� �湮�ڰ� s�� ��� ��ҿ� ���� ����

	ZeroVisitor zv;
	s.Accept(&zv);

}





