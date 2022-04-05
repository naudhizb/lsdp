#include <iostream>

// 아래 코드가  "WTL" 이라는 라이브러리의 원리 입니다.
// Windows Template Library

// 템플릿을 만들때 T를 사용하지 않은 모든 멤버 함수는
// 템플릿이 아닌 기반 클래스를 만들어서 제공해라
class BaseWindow
{
public:
	void OnClick() { std::cout << "Window onClick" << std::endl; }
	void OnKeyDown() {}
};

template<typename T>
class Window : public BaseWindow
{
public:
	void msgLoop() 
	{
		static_cast<T*>(this)->OnClick();
	}
};

class MainWindow : public Window<MainWindow>
{
public:
	void OnClick() { std::cout << "MainWindow onClick" << std::endl; }
};
class MainWindow2 : public Window<MainWindow2>
{
public:
	void OnClick() { std::cout << "MainWindow onClick" << std::endl; }
};
int main()
{
	MainWindow mw;
	mw.msgLoop(); 
}