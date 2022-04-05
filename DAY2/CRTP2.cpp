#include <iostream>

template<typename T>
class Window
{
public:
	void msgLoop() // void msgLoop(Window* this)
	{
//		OnClick();	// this->OnClick()

		static_cast<T*>(this)->OnClick();
	}
	void OnClick() { std::cout << "Window onClick" << std::endl; }
	void OnKeyDown() {}
};
class MainWindow : public Window<MainWindow>
{
public:
	void OnClick(){ std::cout << "MainWindow onClick" << std::endl; }
};
int main()
{
	MainWindow mw;
	mw.msgLoop(); // msgLoop(&mw)
}