#include <iostream>


int main()
{
	slist<int> s = { 1,2,3,4,5 }; // ��� ��Ұ� ������ �޸�
	vector<int> v = { 1,2,3,4,5 }; // ��� ��Ұ� ���ӵ� �޸�

	// �����̳��� ���� ������ ������� ������ ������� ���� �ϰ� �ʹ�.
	�ݺ��� a = s.get�ݺ���();
	�ݺ��� b = v.get�ݺ���();

	std::cout << a.GetObject() << std::endl; // 1

	a.MoveNext(); // �������� �̵�.

	std::cout << a.GetObject() << std::endl; // 2

}