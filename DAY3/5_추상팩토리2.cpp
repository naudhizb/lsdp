// 3_추상팩토리 - 147
#include <iostream>
using namespace std;

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
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
// 추상 팩토리 : "제품의 군"을 만들기 위한 인터페이스를 제공한다.
//				 어떤 제품들을 만들지는 구체화한 팩토리가 결정한다.

// GoF's 패턴에 "Factory" 라는 이름은 없습니다.
//			   "Abstract Factory" 가 있습니다.
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};




//  style 별로 각 콘트롤을 만드는 공장
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

	// 컨트롤이 필요하면 공장을 사용해서 생성
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











