// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// Style �ɼǰ� ������� �׻� Windows ����� Dialog

// ���ؾ� �ϴ� ���� �����Լ�ȭ �ؼ� �Ļ� Ŭ������ ���氡���ϰ�
// ������ �ڵ�� ��� Ŭ������!!

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit*   edit = CreateEdit();
		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
	// ��ü�� �������� ���� �������̽��� ����� ���������
	// � ��ü�� �������� �Ļ� Ŭ�������� �����Ѵ�.
	// "���丮 �޼ҵ�" ����. �⺻ ����� ���ø� �޼ҵ�� ����
	// ������ ��ü�� ������ ���� �������� �����ϴ� ����.

	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() {return new WinButton;}
	virtual IEdit*   CreateEdit() { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() { return new OSXButton; }
	virtual IEdit*   CreateEdit() { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}


// GoF ��  23�� ������ 3������ �з� �˴ϴ�.

// ���� ���� 5�� : �̱���, �߻����丮, ���丮 �޼ҵ�, ������Ÿ��, ����

// ���� ���� 7�� : Composite, Decorator, Flyweight,  
//				    Adapter, Proxy, 
//					Bridge, Facade

// ���� ���� 11�� : template, strategy, command
//					





