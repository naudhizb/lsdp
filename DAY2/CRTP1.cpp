// CRTP1
#include <iostream>

// �̺�Ʈ ó���� ���ؼ� ���ϴ� ���� �����Լ���
// MenuItem �� ��� : �޴��� ������ �ʹ� ����. �Ļ� Ŭ���� ������ ��������.
// MainWindow�ǰ�� : MainWindow �� ������ ���� �ʴ�. ������ ���� ������
class Window
{
public:
	void msgLoop()
	{
		// �߻��� �̺�Ʈ ������ �Լ� ȣ��
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