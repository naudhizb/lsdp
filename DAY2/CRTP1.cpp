// CRTP1
#include <iostream>

// 이벤트 처리를 위해서 변하는 것을 가상함수로
// MenuItem 의 경우 : 메뉴의 종류는 너무 많다. 파생 클래스 갯수가 많아진다.
// MainWindow의경우 : MainWindow 는 갯수가 많지 않다. 나쁘지 않은 디자인
class Window
{
public:
	void msgLoop()
	{
		// 발생한 이벤트 조사후 함수 호출
		OnClick();
//		OnKeyDown();
	}
	virtual void OnClick() {}
	virtual void OnKeyDown() {}
};
class MainWindow : public Window
{
public:
	void OnClick() override { std::cout << "MainWindow onClick" << std::endl;  }
};
int main()
{
	MainWindow mw;
	mw.msgLoop();
}