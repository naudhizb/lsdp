// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*> v1; // Dog �� �����ϰڴٴ� �ǹ�
	std::vector<Animal*> v2; // ����(���� ��� Ŭ������ ���� �Ļ��� Ÿ��)�� �����ϰڴٴ� �ǹ�
							 // ��� ������ ����..		
}

// A �� B�� ���� �ʹٸ�
// ��� Ŭ������ ���� �ض�...

// ����� 
// 1. "�⺻ Ÿ���� Ȯ��" �� �ƴ϶�
// 2. ������ ���� ���ؼ��� ���.. 
 
// 9:50 �п� ���� �մϴ�.