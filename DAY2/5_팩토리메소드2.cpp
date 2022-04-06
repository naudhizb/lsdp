// 5_팩토리메소드
#include <iostream>

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
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

// 변해야 하는 것은 가상함수화 해서 파생 클래스가 변경가능하게
// 동일한 코드는 기반 클래스로!!

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit*   edit = CreateEdit();
		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
	// 객체를 생성하지 위한 인터페이스를 만들고 사용하지만
	// 어떤 객체를 만들지는 파생 클래스에서 결정한다.
	// "팩토리 메소드" 패턴. 기본 모양은 템플릿 메소드와 동일
	// 생성될 객체의 종류를 하위 계층에서 결정하는 패턴.

	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() {return new WinButton;}
	virtual IEdit*   CreateEdit() { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	virtual IButton* CreateButton() { return new OSXButton; }
	virtual IEdit*   CreateEdit() { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}


// GoF 의  23개 패턴은 3가지로 분류 됩니다.

// 생성 패턴 5개 : 싱글톤, 추상팩토리, 팩토리 메소드, 프로토타입, 빌더

// 구조 패턴 7개 : Composite, Decorator, Flyweight,  
//				    Adapter, Proxy, 
//					Bridge, Facade

// 행위 패턴 11개 : template, strategy, command
//					





