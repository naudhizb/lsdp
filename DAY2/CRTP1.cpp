#include <iostream>

class Window
{
public:
	void msgLoop()
	{
		// 발생한 이벤트 조사후 함수 호출
		OnClick();
		OnKeyDown();
	}
	void OnClick() {}
	void OnKeyDown() {}
};

int main()
{

}