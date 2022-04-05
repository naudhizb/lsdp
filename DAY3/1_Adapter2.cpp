

// github.com/codenuri/lsdp ���� 

// "DAY3_�����ҽ�.zip" �����ø� �˴ϴ�.

// 8:35 �п� �����ϰڽ��ϴ�.













#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

class TextView
{
	string data;
public:
	TextView(string s) : data(s) {}

	void Show() { cout << data << endl; }
};




class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { cout << "Draw Circle" << endl; }
};


// Ŭ���� �����
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void Draw() override
	{
		TextView::Show();
	}
};

class Text2 :  public Shape
{
	TextView* txtView; // ������ �Ǵ� �����̾�� �մϴ�.
public:
	Text2(TextView* p) : txtView(p) {}

	void Draw() override
	{
		txtView->Show();
	}
};

int main()
{
	vector<Shape*> v;
	TextView tv("hello"); // tv �� TextView Ÿ���� ��ü�Դϴ�.
//	v.push_back(&tv); // error

	v.push_back(new Text2(&tv)); // ok.. �������̽��� ���� �ʴ� ��ü��
								// ����͸� ���ؼ� �������̽��� �����ؼ� ������

	v[0]->Draw();
}







