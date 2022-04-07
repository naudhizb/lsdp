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
		case WM_LBUTTONDOWN: pThis->LButtonDown(); break;
		case WM_KEYDOWN:     pThis->KeyDown(); break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};


class MyWindow : public CWnd
{
public:
	void LButtonDown() { cout << "LBUTTON" << endl; }
};
class ImageView : public CWnd
{
public:
	void LButtonDown() { cout << "ImageView LBUTTON" << endl; }
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



