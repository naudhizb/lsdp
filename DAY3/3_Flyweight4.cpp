#include <iostream>

// flyweight : �Ӽ��� ������ ��ü�� ������ ���� ����
// 1. static ����Լ��� ��ü�� �����ϰ� �ϴ� ���
// 2. factory Ŭ������ ����ؼ� ��ü�� �����ϰ� �ϴ� ���

int main()
{

	char s1[] = "ABCD";
	char s2[] = "ABCD";

	const char* s3 = "ABCD";
	const char* s4 = "ABCD";

	printf("%p, %p\n", s1, s2);
}