#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// STL �ݺ��� ī�װ�
// �Է�  : ++					��Ƽ�н� ���� �ȵ�
// ���  : ++, *p = 0
//								�Ʒ�3���� ��Ƽ �н� ����
// ������ : ++					�̱۸���Ʈ �ݺ���
// ����� : ++, --				������Ʈ �ݺ���
// �������� : ++, --, +, -, []    ���ӵ� �޸� vector

// p�� �ݺ����϶�
// *p = 10  ���
// int n = *p; �Է�

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	// find�˰����� �䱸�ϴ� �ݺ����� �ּ� �䱸 ������ ? �Է�
	auto ret = std::find( v.begin(), v.end(), 3);

	std::reverse( v.begin(), v.end() ); // �ּ� �䱸 ����? �����.

	std::list<int> s = { 1,2,3,4,5 , 3,2,1};
	 
//	s.sort();
//	std::sort( s.begin(), s.end() ); // ����Ʈ �˰����Դϴ�.
}

// cppreference.com