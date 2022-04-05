#include <iostream>

// �Ʒ� �ڵ尡  "WTL" �̶�� ���̺귯���� ���� �Դϴ�.
// Windows Template Library

// ���ø��� ���鶧 T�� ������� ���� ��� ��� �Լ���
// ���ø��� �ƴ� ��� Ŭ������ ���� �����ض�
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