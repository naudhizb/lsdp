#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class CWnd;
map<int, CWnd*> this_map;

class CWnd
{
	int mHandle;

	//---------------------
	CWnd* parent; // �θ� ������� �Ѱ��̴�.
	std::vector<CWnd*> child_vec; // �ڽ�������� ������ �̴�.
public:

	void AddChild(CWnd* child)
	{
		child_vec.push_back(child);
		child->parent = this;

		// ���� child->mHandle �����츦 ���� ������ �ڽ����� ���̴� �Լ�
		ec_add_child(this->mHandle, child->mHandle);
	}

	void Create()
	{
		mHandle = ec_make_window(foo, "A");
		this_map[mHandle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		CWnd* const pThis = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: pThis->FireLButtonDown(); break;
		case WM_KEYDOWN:     pThis->KeyDown(); break;
		}
		return 0;
	}

	void FireLButtonDown()
	{
		// 1. �ڽ��� ó���� �õ�
		if (LButtonDown() == true)
			return;

		//2. �θ������찡 �ִٸ� ����
		if (parent != 0)
			parent->FireLButtonDown();
	}

	virtual bool LButtonDown() { return false; }
	virtual bool KeyDown()     { return false; }
};


class MyWindow : public CWnd
{
public:
	bool LButtonDown() { cout << "LBUTTON" << endl; return true; }
};
class ImageView : public CWnd
{
public:
	bool LButtonDown() { cout << "ImageView LBUTTON" << endl; return true; }
};

int main()
{
	MyWindow w;
	w.Create();

	ImageView view;
	view.Create();
	w.AddChild(&view); // view �� w�� �ڽ�������� ���δ�.

	ec_process_message();
}


