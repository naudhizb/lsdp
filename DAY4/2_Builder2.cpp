// 2_Builder
#include <iostream>
#include <string>
using namespace std;

// Builder : ������ ��ü�� �����ϴµ�..
//			 ������ ������ ����ϰ�, �� ������ ǥ���� �ٸ� ��ü�� �����Ҷ� ���

// �������� 5���� ����
// singleton      : ���� �Ѱ��� ��ü�� ���� 
// prototype      : ���� ��ü�� �����ؼ� ���ο� ��ü ����
// abstract factory : ��ǰ�� ���� �����ϱ� ���� �������̽� ����
// factory method : ��ü�� ����� ���� �������̽� ����, � ��ü�� �������� ���� Ŭ������ ���� 
// builder        : ���� �������� ������ ��ü �����.



// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef string Hat;			// class Hat{}
typedef string Uniform;	    // class Uniform{}
typedef string Shoes;		// class Shoes{}
typedef string Character;	// class Character{}��� ����

// ĳ���͸� ����µ� �ʿ��� �� ������ �������̽���
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};
// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* pBuilder = 0;
public:
	void setBuilder(IBuilder* p) { pBuilder = p; }
	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
	//	c = c + pBuilder->makeHat();
		c = c + pBuilder->makeUniform();
		c = c + pBuilder->makeShoes();
		return c;
	}
};
struct Korean : public IBuilder
{
	Hat makeHat()         override { return "��"; }
	Uniform makeUniform() override { return "�Ѻ�"; }
	Shoes makeShoes()     override { return "¤��"; }
};
struct American : public IBuilder
{
	Hat makeHat()         override { return "�߱�����"; }
	Uniform makeUniform() override { return "�纹"; }
	Shoes makeShoes()     override { return "����"; }
};
int main()
{
	Korean k; American a;
	Director d;
	d.setBuilder(&k);
	Character c = d.construct();
	cout << c << endl;

}