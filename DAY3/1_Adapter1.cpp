

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

// TextView를 "도형편집기"예제에서 사용하려면
// 1. Shape 로 부터 파생되어야 한다.
// 2. 반드시 Draw를 만들어야 한다.

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// Show() 함수의 이름을 Draw()로 변경한것.
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







