// QT ���̺귯��
// aaa.exe -style:windows
// aaa.exe -style:gtk
// aaa.exe -style:osx

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

int main(int argc, char** argv)
{
	IButton* btn;

	if (strcmp(argv[0], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// �׷���.. ��ư�� �Ѱ��� ����� �ɱ� ??
	// ������ ����ٸ� �׶� ���� �� �ڵ带 ����Ѵٸ� ???
}








