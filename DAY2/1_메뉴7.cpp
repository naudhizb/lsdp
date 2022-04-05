#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


#include <memory>

int main()
{
	int* p1 = new int;
	delete p1; // 만드시 delete 해야 합니다.

	std::shared_ptr<int> p2(new int); // p2가 파괴 될때 자동으로 삭제됩니다
	*p2 = 10; // 사용법은 raw pointer와 동일합니다

	// 주의
	std::shared_ptr<int> p3 = new int; // error

	// 권장
	std::shared_ptr<int> p4(new int); // 이코드 보다
	std::shared_ptr<int> p5 = std::make_shared<int>(4); // 이게 좋습니다.
															//4는 초기값
}




