#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


#include <memory>

int main()
{
	int* p1 = new int;
	delete p1; // ����� delete �ؾ� �մϴ�.

	std::shared_ptr<int> p2(new int); // p2�� �ı� �ɶ� �ڵ����� �����˴ϴ�
	*p2 = 10; // ������ raw pointer�� �����մϴ�

	// ����
	std::shared_ptr<int> p3 = new int; // error

	// ����
	std::shared_ptr<int> p4(new int); // ���ڵ� ����
	std::shared_ptr<int> p5 = std::make_shared<int>(4); // �̰� �����ϴ�.
															//4�� �ʱⰪ
}




