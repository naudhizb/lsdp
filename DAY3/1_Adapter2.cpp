

// github.com/codenuri/lsdp 에서 

// "DAY3_사전소스.zip" 받으시면 됩니다.

// 8:35 분에 시작하겠습니다.













#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 아래 클래스가 이미 있었다가 가정해 봅시다.

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


// 클래스 어답터
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
	TextView* txtView; // 포인터 또는 참조이어야 합니다.
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
	TextView tv("hello"); // tv 는 TextView 타입의 객체입니다.
//	v.push_back(&tv); // error

	v.push_back(new Text2(&tv)); // ok.. 인터페이스가 맞지 않는 객체를
								// 어답터를 통해서 인터페이스를 수정해서 넣은것

	v[0]->Draw();
}







