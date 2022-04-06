#include <iostream>

// flyweight : 속성이 동일한 객체의 공유에 관한 패턴
// 1. static 멤버함수를 객체를 생성하게 하는 기술
// 2. factory 클래스를 사용해서 객체를 생성하게 하는 기술

int main()
{

	char s1[] = "ABCD";
	char s2[] = "ABCD";

	const char* s3 = "ABCD";
	const char* s4 = "ABCD";

	printf("%p, %p\n", s1, s2);
}