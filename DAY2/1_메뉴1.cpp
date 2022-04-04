// github.com/codenuri/lsdp 에서 "DAY2_사전소스"
// 받으시면됩니다.






// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C언어 : 프로그램이란 ?
// main 함수의 1번째 줄부터 순차적으로 실행되는 실행흐름이다.
// => 실행흐름을 변경하려면 제어문 사용
// => 기능별로 분리하려면 함수 사용

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}
	// 단점
	// 1. 메뉴가 추가되면 코드가 여러곳이 변경된다.
	// 2. 메뉴 선택시, 하위 메뉴가 필요하면 복잡해 진다.
}


