

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

// TextView�� "����������"�������� ����Ϸ���
// 1. Shape �� ���� �Ļ��Ǿ�� �Ѵ�.
// 2. �ݵ�� Draw�� ������ �Ѵ�.

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// Show() �Լ��� �̸��� Draw()�� �����Ѱ�.
	void Draw() override
	{
		TextView::Show();
	}
};

int main()
{
	vector<Shape*> v;
	
	Text txt("Hello");
	v.push_back(&txt);

	v[0]->Draw();
}







