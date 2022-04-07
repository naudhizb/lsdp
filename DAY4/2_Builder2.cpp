// 2_Builder
#include <iostream>
#include <string>
using namespace std;

// Builder : 복잡한 객체를 생성하는데..
//			 동일한 공정을 사용하고, 각 공정의 표현이 다른 객체를 생성할때 사용

// 생성패턴 5가지 정리
// singleton      : 오직 한개의 객체만 생성 
// prototype      : 기존 객체를 복사해서 새로운 객체 생성
// abstract factory : 제품의 군을 생성하기 위한 인터페이스 설계
// factory method : 객체를 만들기 위한 인터페이스 정의, 어떤 객체를 만들지는 하위 클래스가 결정 
// builder        : 동일 공정으로 복잡한 객체 만들기.



// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef string Hat;			// class Hat{}
typedef string Uniform;	    // class Uniform{}
typedef string Shoes;		// class Shoes{}
typedef string Character;	// class Character{}라고 가정

// 캐릭터를 만드는데 필요한 각 공정을 인터페이스로
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};
// 캐릭터를 만드는 클래스
class Director
{
	IBuilder* pBuilder = 0;
public:
	void setBuilder(IBuilder* p) { pBuilder = p; }
	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
	//	c = c + pBuilder->makeHat();
		c = c + pBuilder->makeUniform();
		c = c + pBuilder->makeShoes();
		return c;
	}
};
struct Korean : public IBuilder
{
	Hat makeHat()         override { return "갓"; }
	Uniform makeUniform() override { return "한복"; }
	Shoes makeShoes()     override { return "짚신"; }
};
struct American : public IBuilder
{
	Hat makeHat()         override { return "야구모자"; }
	Uniform makeUniform() override { return "양복"; }
	Shoes makeShoes()     override { return "구두"; }
};
int main()
{
	Korean k; American a;
	Director d;
	d.setBuilder(&k);
	Character c = d.construct();
	cout << c << endl;

}