

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

// Adapter 패턴 : 기존 클래스의 인터페이스(함수이름)를 수정
//				  시스템이 요구하는 인터페이스로 변경하는 것
//		"인터페이스의 불일치를 해결"

// 1. 클래스 어답터
// 2. 객체 어답터.

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

	TextView tv("hello"); // tv 는 TextView 타입의 객체입니다.
	v.push_back(&tv); // ???
}







