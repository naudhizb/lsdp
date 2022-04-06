// 3_�߻����丮 - 147
#include <iostream>
using namespace std;

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
	void Draw() { cout << "Draw WinButton" << endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { cout << "Draw WinEdit" << endl; }
};

struct OSXButton : public IButton
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};
//-----------------
// �߻� ���丮 : "��ǰ�� ��"�� ����� ���� �������̽��� �����Ѵ�.
//				 � ��ǰ���� �������� ��üȭ�� ���丮�� �����Ѵ�.

// GoF's ���Ͽ� "Factory" ��� �̸��� �����ϴ�.
//			   "Abstract Factory" �� �ֽ��ϴ�.
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};




//  style ���� �� ��Ʈ���� ����� ����
class WinFactory 
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory 
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};


int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[0], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// ��Ʈ���� �ʿ��ϸ� ������ ����ؼ� ����
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











